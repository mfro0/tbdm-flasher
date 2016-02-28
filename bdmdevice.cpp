#include "bdmdevice.h"
#include "bdmcommand.h"

BDMDevice::BDMDevice()
{
}

void BDMDevice::getVersion(void)
{
    BDMCommand cmd(GET_VERSION);

    sendCommand(cmd);
}

void BDMDevice::getLastStatus(void)
{
    BDMCommand cmd;

    sendCommand(cmd);
}

void BDMDevice::reset(void)
{
    BDMCommand cmd;

    sendCommand(cmd);
}

quint8 BDMDevice::getStatus(void)
{
    quint8 status = 0;

    return status;
}

void BDMDevice::halt(void)
{

}

void BDMDevice::go(void)
{
}

void BDMDevice::step(void)
{

}

void BDMDevice::resync(void)
{

}

void BDMDevice::assertTA(void)
{

}

quint8 BDMDevice::readMemByte(quint32 address)
{
    quint8 val = 0;
    BDMCommand cmd;

    sendCommand(cmd);

    return val;
}

quint16 BDMDevice::readMemWord(quint32 address)
{
    BDMCommand cmd;
    quint16 val = 0;

    sendCommand(cmd);

    return val;
}

quint32 BDMDevice::readMemLong(quint32 address)
{
    BDMCommand cmd;
    quint32 val = 0;

    sendCommand(cmd);
    return val;
}

void BDMDevice::readMemblockByte(quint32 address, QByteArray &arr)
{
    BDMCommand cmd;

    sendCommand(cmd);
}

void BDMDevice::readMemblockWord(quint32 address, QByteArray &arr)
{
    BDMCommand cmd;

    sendCommand(cmd);
}

void BDMDevice::readMemblockLong(quint32 address, QByteArray &arr)
{
    BDMCommand cmd;

    sendCommand(cmd);
}

void BDMDevice::writeMemByte(quint32 address, quint8 byte)
{
    BDMCommand cmd;

    sendCommand(cmd);
}

void BDMDevice::writeMemWord(quint32 address, quint16 word)
{
    BDMCommand cmd;

    sendCommand(cmd);
}

void BDMDevice::writeMemLong(quint32 address, quint32 longw)
{
    BDMCommand cmd;

    sendCommand(cmd);
}

void BDMDevice::writeMemblockByte(quint32 address, QByteArray &arr)
{
    BDMCommand cmd;

    sendCommand(cmd);
}

void BDMDevice::writeMemblockWord(quint32 address, QByteArray &arr)
{
    BDMCommand cmd;

    sendCommand(cmd);
}

void BDMDevice::writeMemblockLong(quint32 address, QByteArray &arr)
{
    BDMCommand cmd;

    sendCommand(cmd);
}

quint32 BDMDevice::readReg(int regNum)
{
    BDMCommand cmd;
    quint32 regValue = 0;

    sendCommand(cmd);

    return regValue;
}

void BDMDevice::writeReg(int regnum, quint32 value)
{
    BDMCommand cmd;

    sendCommand(cmd);
}

quint32 BDMDevice::readCReg(int regNum)
{
    BDMCommand cmd;

    quint32 regValue = 0;

    sendCommand(cmd);

    return regValue;
}

void BDMDevice::writeCReg(int regnum, quint32 value)
{
    BDMCommand cmd;

    sendCommand(cmd);
}

quint32 BDMDevice::readDbgReg(int regnum)
{
    quint32 regValue = 0;
    BDMCommand cmd;

    sendCommand(cmd);

    return regValue;
}

void BDMDevice::writeDbgReg(int regnum, quint32 value)
{
    BDMCommand cmd;

    sendCommand(cmd);
}
