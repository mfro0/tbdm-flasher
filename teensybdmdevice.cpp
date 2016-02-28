#include "teensybdmdevice.h"

TeensyBDMDevice::TeensyBDMDevice()
{

}

void TeensyBDMDevice::open()
{
}

void TeensyBDMDevice::close()
{
}

void TeensyBDMDevice::getVersion(void)
{

}

void TeensyBDMDevice::getLastStatus(void)
{
}

void TeensyBDMDevice::reset(void)
{

}

quint8 TeensyBDMDevice::getStatus(void)
{
    quint8 status = 0;

    return status;
}

void TeensyBDMDevice::halt(void)
{

}

void TeensyBDMDevice::go(void)
{
}

void TeensyBDMDevice::step(void)
{

}

void TeensyBDMDevice::resync(void)
{

}

void TeensyBDMDevice::assertTA(void)
{

}

quint8 TeensyBDMDevice::readMemByte(quint32 address)
{
    quint8 val = 0;

    return val;
}

quint16 TeensyBDMDevice::readMemWord(quint32 address)
{
    quint16 val = 0;

    return val;
}

quint32 TeensyBDMDevice::readMemLong(quint32 address)
{
    quint32 val = 0;

    return val;
}

void TeensyBDMDevice::readMemblockByte(quint32 address, QByteArray &arr)
{

}

void TeensyBDMDevice::readMemblockWord(quint32 address, QByteArray &arr)
{

}

void TeensyBDMDevice::readMemblockLong(quint32 address, QByteArray &arr)
{

}

void TeensyBDMDevice::writeMemByte(quint32 address, quint8 byte)
{

}

void TeensyBDMDevice::writeMemWord(quint32 address, quint16 word)
{

}

void TeensyBDMDevice::writeMemLong(quint32 address, quint32 longw)
{

}

void TeensyBDMDevice::writeMemblockByte(quint32 address, QByteArray &arr)
{

}

void TeensyBDMDevice::writeMemblockWord(quint32 address, QByteArray &arr)
{

}

void TeensyBDMDevice::writeMemblockLong(quint32 address, QByteArray &arr)
{

}

quint32 TeensyBDMDevice::readReg(int regNum)
{
    quint32 regValue = 0;

    return regValue;
}

void TeensyBDMDevice::writeReg(int regnum, quint32 value)
{

}

quint32 TeensyBDMDevice::readCReg(int regNum)
{
    quint32 regValue = 0;

    return regValue;
}

void TeensyBDMDevice::writeCReg(int regnum, quint32 value)
{

}

quint32 TeensyBDMDevice::readDbgReg(int regnum)
{
    quint32 regValue = 0;

    return regValue;
}

void TeensyBDMDevice::writeDbgReg(int regnum, quint32 value)
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
