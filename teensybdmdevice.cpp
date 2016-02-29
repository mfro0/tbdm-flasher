#include "teensybdmdevice.h"
#include <QSerialPort>

TeensyBDMDevice::TeensyBDMDevice()
{
    serial = new QSerialPort();
}

TeensyBDMDevice::~TeensyBDMDevice()
{
    delete serial;
}

void TeensyBDMDevice::open()
{

}

void TeensyBDMDevice::close()
{
}

void TeensyBDMDevice::sendCommand(BDMCommand *command)
{

}

quint32 TeensyBDMDevice::receiveResult(void)
{
    quint32 value = 0;

    return value;
}
