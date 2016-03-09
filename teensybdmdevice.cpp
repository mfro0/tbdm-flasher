#include <QDebug>

#include "teensybdmdevice.h"

#include "libusb.h"

// #define BDMCF_VID   0x0425
// #define BDMCF_PID   0x1001
#define BDMCF_VID   0x03eb
#define BDMCF_PID   0x8a06


typedef struct bdmcf_usb_dev_s
{
    libusb_device *device;
    libusb_device_handle *handle;
    struct libusb_device_descriptor desc;
    quint8 bus_number;
    quint8 device_address;
    char name[16];
} bdmcf_usb_dev;

static bdmcf_usb_dev *usb_devs = 0;
static libusb_device **usb_libusb_devs;


/*
 * find all BDMCF devices attached to the computer
 */
void TeensyBDMDevice::findDevices(quint16 product_id)
{
    int i;
    int count;

    if (usb_devs) return;

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

    usb_devs = (bdmcf_usb_dev *) calloc(dev_count, sizeof (bdmcf_usb_dev));
    if (!usb_devs) return;

    dev_count = 0;

    /* scan through all busses and devices adding each one */
    for (i = 0; i < count; i++)
    {
        libusb_device *dev = usb_libusb_devs[i];
        struct libusb_device_descriptor desc;
        bdmcf_usb_dev *udev = &usb_devs[dev_count];
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
                dev_count++;
            }
        }
    }
}



TeensyBDMDevice::TeensyBDMDevice()
{
    dev_count = 0;

    libusb_init(&ctx);                  /* init LIBUSB */
    libusb_set_debug(NULL, 0);          /* set debug level to minimum */

    findDevices(BDMCF_PID);  /* look for devices on all USB busses */
    qDebug() << "bdmcf_init: USB initialised, found " << dev_count << " device(s)";
}

TeensyBDMDevice::~TeensyBDMDevice()
{

    libusb_exit(ctx);
}

void TeensyBDMDevice::open()
{
}

void TeensyBDMDevice::close()
{
}

int TeensyBDMDevice::sendCommand(BDMCommand &command)
{
    int ret;

    return ret;
}

