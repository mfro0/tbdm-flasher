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
    uint32_t status;

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

}

uint16_t TeensyBDMDevice::read_mem_word(uint32_t address)
{

}

uint32_t TeensyBDMDevice::read_mem_long(uint32_t address)
{

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

}

void TeensyBDMDevice::write_reg(int regnum, uint32_t value)
{

}

uint32_t TeensyBDMDevice::read_creg(int regNum)
{

}

void TeensyBDMDevice::write_creg(int regnum, uint32_t value)
{

}

uint32_t TeensyBDMDevice::read_dbgreg(int regnum)
{

}

void TeensyBDMDevice::write_dbgreg(int regnum, uint32_t value)
{
}
