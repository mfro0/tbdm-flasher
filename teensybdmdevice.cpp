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

quint8 TeensyBDMDevice::read_mem_byte(quint32 address)
{
    quint8 val = 0;

    return val;
}

quint16 TeensyBDMDevice::read_mem_word(quint32 address)
{
    quint16 val = 0;

    return val;
}

quint32 TeensyBDMDevice::read_mem_long(quint32 address)
{
    quint32 val = 0;

    return val;
}

void TeensyBDMDevice::read_memblock_byte(quint32 address, QByteArray &arr)
{

}

void TeensyBDMDevice::read_memblock_word(quint32 address, QByteArray &arr)
{

}

void TeensyBDMDevice::read_memblock_long(quint32 address, QByteArray &arr)
{

}

void TeensyBDMDevice::write_mem_byte(quint32 address, quint8 byte)
{

}

void TeensyBDMDevice::write_mem_word(quint32 address, quint16 word)
{

}

void TeensyBDMDevice::write_mem_long(quint32 address, quint32 longw)
{

}

void TeensyBDMDevice::write_memblock_byte(quint32 address, QByteArray &arr)
{

}

void TeensyBDMDevice::write_memblock_word(quint32 address, QByteArray &arr)
{

}

void TeensyBDMDevice::write_memblock_long(quint32 address, QByteArray &arr)
{

}

quint32 TeensyBDMDevice::read_reg(int regNum)
{
    quint32 regValue = 0;

    return regValue;
}

void TeensyBDMDevice::write_reg(int regnum, quint32 value)
{

}

quint32 TeensyBDMDevice::read_creg(int regNum)
{
    quint32 regValue = 0;

    return regValue;
}

void TeensyBDMDevice::write_creg(int regnum, quint32 value)
{

}

quint32 TeensyBDMDevice::read_dbgreg(int regnum)
{
    quint32 regValue = 0;

    return regValue;
}

void TeensyBDMDevice::write_dbgreg(int regnum, quint32 value)
{
}

void TeensyBDMDevice::send_command(BDMCommand *command)
{

}

quint32 TeensyBDMDevice::receive_result(void)
{
    quint32 value = 0;

    return value;
}
