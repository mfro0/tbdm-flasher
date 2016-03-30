/*
 * teensybdmdevice.cpp
 *
 * This file is part of tbdm.
 *
 * tbdm is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * tbdm is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with BaS_gcc.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Copyright 2016        M. Froeschle
 *
 *
 */

#include <QDebug>

#include "bdmcommand.h"
#include "teensybdmdevice.h"

#include "libusb.h"
#include <algorithm>            // for min()

#define BDMCF_VID   0x0425
#define BDMCF_PID   0x1001

typedef struct bdmcf_usb_dev_s
{
    libusb_device *device;
    libusb_device_handle *handle;
    struct libusb_device_descriptor desc;
    quint8 bus_number;
    quint8 device_address;
    char name[16];
} bdmcf_usb_dev;


/*
 * find all BDMCF devices attached to the computer
 */
void TeensyBDMDevice::findDevices(quint16 product_id)
{
    int i;
    int count;
    libusb_device **usb_libusb_devs;
    bdmcf_usb_dev *bdmcf_usbdevs = 0;


    count = libusb_get_device_list(NULL, &usb_libusb_devs);
    if (count < 0)
    {
        fprintf(stderr, "warning: error getting device list");
        return;
    }

    /* scan through all busses then devices counting the number found */
    for (i = 0; i < count; i++)
    {
        libusb_device *dev = usb_libusb_devs[i];
        struct libusb_device_descriptor desc;
        int r = libusb_get_device_descriptor(dev, &desc);

        qDebug() << QString("found USB device vendor=0x%1 product=0x%2").arg(desc.idVendor, 0, 16).arg(desc.idProduct, 0, 16);
        if (r < 0)
        {
            qWarning() << "failed to get usb device descriptor";
        }
        else
        {
            if ((desc.idVendor == BDMCF_VID) && (desc.idProduct == product_id))
            {
                /* found a device */
                dev_count++;
            }
        }
    }

    bdmcf_usbdevs = (bdmcf_usb_dev *) calloc(dev_count, sizeof (bdmcf_usb_dev));
    if (!bdmcf_usbdevs) return;

    dev_count = 0;

    /* scan through all busses and devices adding each one */
    for (i = 0; i < count; i++)
    {
        libusb_device *dev = usb_libusb_devs[i];
        struct libusb_device_descriptor desc;
        bdmcf_usb_dev *udev = &bdmcf_usbdevs[dev_count];
        int r = libusb_get_device_descriptor(dev, &desc);

        if (r >= 0)
        {
            if ((desc.idVendor == BDMCF_VID) && (desc.idProduct == product_id))
            {
                /* found a device */
                udev->desc = desc;
                udev->device = dev;
                udev->bus_number = libusb_get_bus_number(dev);
                udev->device_address = libusb_get_device_address(dev);
                snprintf(udev->name, sizeof(udev->name), "%03d-%03d", udev->bus_number, udev->device_address);
                qDebug() << "device found at bus " << udev->bus_number << "device address" << udev->device_address;
                dev_count++;
            }
        }
    }

}



TeensyBDMDevice::TeensyBDMDevice()
{
    dev_count = 0;

    libusb_init(&ctx);                  /* init LIBUSB */
    libusb_set_debug(ctx, 3); //set verbosity level to 3, as suggested in the documentation
    // libusb_set_debug(ctx, 0);          /* set debug level to minimum */

    findDevices(BDMCF_PID);  /* look for devices on all USB busses */
    qDebug() << "TeensyBDMDevice::TeensyBDMDevice(): USB initialised, found " << dev_count << " device(s)";
}

TeensyBDMDevice::~TeensyBDMDevice()
{

    libusb_exit(ctx);
}

void TeensyBDMDevice::open()
{
    dev_handle = libusb_open_device_with_vid_pid(ctx, BDMCF_VID, BDMCF_PID);
    if (dev_handle != NULL)
    {
        int config;
        int res;

        res = libusb_get_configuration(dev_handle, &config);
        qDebug() << "libusb_get_configuration() returned " << res << "(" << libusb_error_name(res) << ")";
        if (res == 0)
        {
            qDebug() << "active configuration =" << config;
        }

        res = libusb_kernel_driver_active(dev_handle, 0);
        qDebug() << "libusb_kernel_driver_active() returned " << res << "(" << libusb_error_name(res) << ")";
        if (res == 0)
        {
            qDebug() << "no kernel driver active";
        }

        res = libusb_get_configuration(dev_handle, &config);
        qDebug() << "libusb_get_configuration() returned " << res << "(" << libusb_error_name(res) << ")";
        if (res == 0)
        {
            qDebug() << "configuration" << config << "is active";
        }

        res = libusb_set_configuration(dev_handle, 1);
        qDebug() << "libusb_set_configuration() returned" << res << "(" << libusb_error_name(res) << ")";
        if (res == 0)
        {
            qDebug() << "configuration 1 set";
        }

        res = libusb_claim_interface(dev_handle, 0);
        qDebug() << "libusb_claim_interface res=" << libusb_error_name(res);
    }
}

void TeensyBDMDevice::close()
{
    libusb_close(dev_handle);
    dev_handle = 0;
}

void hexdump(uint8_t buffer[], int size)
{
    int i;
    int line = 0;
    uint8_t *bp = buffer;
    QDebug deb = qDebug().nospace();

    deb.noquote();              /* suppress quotes in output */

    while (bp < buffer + size) {
        uint8_t *lbp = bp;

        // printf("%08x  ", bp - buffer);
        deb << QString("%1").arg((ulong) (bp - buffer), 8, 16);

        for (i = 0; i < 16; i++) {
            if (bp + i > buffer + size) {
                break;
            }
            // printf("%02x ", (uint8_t) *lbp++);
            deb << QString("%1").arg((quint8) *lbp++, 2, 16, QLatin1Char('0')) << " ";
        }

        lbp = bp;
        for (i = 0; i < 16; i++) {
            int8_t c = *lbp++;

            if (bp + i > buffer + size) {
                break;
            }
            if (c > ' ' && c < '~') {
                // printf("%c", c);
                deb << c;
            } else {
                // printf(".");
                deb << ".";
            }
        }
        // printf("\n");
        deb << "\r\n";

        bp += 16;
        line += 16;
    }
}

#define BULK_MAX_SIZE 64

int TeensyBDMDevice::sendCommand(BDMCommand &command)
{
    int res = 0;
    int transferred;
    size_t in_size = 0;
    size_t out_size;
    uint8_t *out_data;

    out_data = (uint8_t *) command.getOutBytes();
    if (out_data == 0L)
    {
        out_data = new quint8[2];
        command.setOutBytes(out_data, 2);
    }
    out_data[0] = command.cmd();
    out_data[1] = 'A';
    out_size = command.outBytesLength();

    hexdump((uint8_t *) out_data, out_size);

    std::vector<quint8> receiveBuffer(BULK_MAX_SIZE);

    if (dev_handle != NULL)
    {
        // send out everything there is to send
        do
        {
            res = libusb_bulk_transfer(dev_handle, 2 | LIBUSB_ENDPOINT_OUT, out_data,
                                       std::min(BULK_MAX_SIZE, (int) out_size), &transferred, 1000);
            qDebug() << "libusb_bulk_transfer OUT res=" << libusb_error_name(res) << "(" << transferred << "Bytes)";

            out_data += transferred;
            out_size -= transferred;
        } while (out_size > 0);

        // repeat receive until we get an empty transfer
        do
        {
            qDebug() << "receive";
            res = libusb_bulk_transfer(dev_handle, 1 | LIBUSB_ENDPOINT_IN,
                                       receiveBuffer.data(), receiveBuffer.capacity(), &transferred, 1000);

            in_size += transferred;
            if (transferred > 0)
                receiveBuffer.resize(receiveBuffer.capacity() + BULK_MAX_SIZE);
            qDebug() << "libusb_bulk_transfer IN res=" << libusb_error_name(res) << "(" << transferred << "Bytes)";

        } while (transferred > 0);

        if (receiveBuffer.size() > 0)
            command.setInBytes(receiveBuffer.data(), in_size);

        hexdump(receiveBuffer.data(), in_size);
    }

    return res;
}

