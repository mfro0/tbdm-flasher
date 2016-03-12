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

#include "teensybdmdevice.h"

#include "libusb.h"

#define BDMCF_VID   0x0425
#define BDMCF_PID   0x1001
//#define BDMCF_VID   0x03eb
//#define BDMCF_PID   0x8a06


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
    libusb_device_handle *dev_handle = libusb_open_device_with_vid_pid(ctx, BDMCF_VID, BDMCF_PID);
    if (dev_handle != NULL)
    {
        int config;
        int res;

        res = libusb_get_configuration(dev_handle, &config);
        if (res == 0)
        {
            qDebug() << "active configuration =" << config;
        }

        res = libusb_kernel_driver_active(dev_handle, 0);
        if (res == 0)
        {
            qDebug() << "no kernel driver active";
        }

        res = libusb_get_configuration(dev_handle, &config);
        if (res == 0)
        {
            qDebug() << "configuration" << config << "is active";
        }

        res = libusb_set_configuration(dev_handle, 1);
        if (res == 0)
        {
            qDebug() << "configuration 1 set";
        }

    }
    if (dev_handle != NULL)
    {
        quint8 data[255] = { 0 };
        int transferred;
        int res;

        res = libusb_claim_interface(dev_handle, 0);
        qDebug() << "libusb_claim_interface res=" << res;

        // res = libusb_control_transfer(dev_handle, )
        res = libusb_bulk_transfer(dev_handle, 2 | LIBUSB_ENDPOINT_OUT, data, sizeof(data), &transferred, 1000);
        qDebug() << "libusb_bulk_transfer res=" << res;
    }

    libusb_free_device_list(usb_libusb_devs, 1);
}



TeensyBDMDevice::TeensyBDMDevice()
{
    dev_count = 0;

    libusb_init(&ctx);                  /* init LIBUSB */
    libusb_set_debug(ctx, 3); //set verbosity level to 3, as suggested in the documentation
    // libusb_set_debug(NULL, 0);          /* set debug level to minimum */

    findDevices(BDMCF_PID);  /* look for devices on all USB busses */
    qDebug() << "bdmcf_init: USB initialised, found " << dev_count << " device(s)";
}

TeensyBDMDevice::~TeensyBDMDevice()
{

    libusb_exit(ctx);
}

void TeensyBDMDevice::open()
{
    // libusb_open(dev, &device_handle);
}

void TeensyBDMDevice::close()
{
}

int TeensyBDMDevice::sendCommand(BDMCommand &command)
{
    int ret = 0;

    return ret;
}

