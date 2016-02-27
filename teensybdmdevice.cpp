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

uint32_t TeensyBDMDevice::getStatus(void)
{
    uint32_t status = 0;

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

uint8_t TeensyBDMDevice::read_mem_byte(uint32_t address)
{
    uint8_t val = 0;

    return val;
}

uint16_t TeensyBDMDevice::read_mem_word(uint32_t address)
{
    uint16_t val = 0;

    return val;
}

uint32_t TeensyBDMDevice::read_mem_long(uint32_t address)
{
    uint32_t val = 0;

    return val;
}

void TeensyBDMDevice::read_memblock_byte(uint32_t address, QByteArray &arr)
{

}

void TeensyBDMDevice::read_memblock_word(uint32_t address, QByteArray &arr)
{

}

void TeensyBDMDevice::read_memblock_long(uint32_t address, QByteArray &arr)
{

}

void TeensyBDMDevice::write_mem_byte(uint32_t address, uint8_t byte)
{

}

void TeensyBDMDevice::write_mem_word(uint32_t address, uint16_t word)
{

}

void TeensyBDMDevice::write_mem_long(uint32_t address, uint32_t longw)
{

}

void TeensyBDMDevice::write_memblock_byte(uint32_t address, QByteArray &arr)
{

}

void TeensyBDMDevice::write_memblock_word(uint32_t address, QByteArray &arr)
{

}

void TeensyBDMDevice::write_memblock_long(uint32_t address, QByteArray &arr)
{

}

uint32_t TeensyBDMDevice::read_reg(int regNum)
{
    uint32_t regValue = 0;

    return regValue;
}

void TeensyBDMDevice::write_reg(int regnum, uint32_t value)
{

}

uint32_t TeensyBDMDevice::read_creg(int regNum)
{
    uint32_t regValue = 0;

    return regValue;
}

void TeensyBDMDevice::write_creg(int regnum, uint32_t value)
{

}

uint32_t TeensyBDMDevice::read_dbgreg(int regnum)
{
    uint32_t regValue = 0;

    return regValue;
}

void TeensyBDMDevice::write_dbgreg(int regnum, uint32_t value)
{
}

void TeensyBDMDevice::send_command(BDMCommand *command)
{

}

uint32_t TeensyBDMDevice::receive_result(void)
{
    uint32_t value = 0;

    return value;
}
