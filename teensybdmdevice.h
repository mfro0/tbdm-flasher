#ifndef TEENSYBDMDEVICE_H
#define TEENSYBDMDEVICE_H
#include "bdmdevice.h"

class BDMCommand;
class QSerialPort;
struct libusb_context;

class TeensyBDMDevice : public BDMDevice
{
public:
    TeensyBDMDevice();
    ~TeensyBDMDevice();

    virtual void open();
    virtual void close();
    void findDevices(quint16 product_id);

private:
    libusb_context *ctx;
    int dev_count;

    virtual int sendCommand(BDMCommand &command);
};

#endif // TEENSYBDMDEVICE_H
