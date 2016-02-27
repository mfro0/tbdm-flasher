#ifndef BDMDEVICE_H
#define BDMDEVICE_H

#include <stdint.h>

class QByteArray;

class BDMDevice
{
public:
    BDMDevice();

    virtual void open() = 0;
    virtual void close() = 0;

    // BDM commands
    virtual void getVersion(void) = 0;
    virtual void getLastStatus(void) = 0;

    virtual void reset(void) = 0;
    virtual uint32_t getStatus(void) = 0;
    virtual void halt(void) = 0;
    virtual void go(void) = 0;
    virtual void step(void) = 0;
    virtual void resync(void) = 0;
    virtual void assertTA(void) = 0;

    virtual uint8_t read_mem_byte(uint32_t address) = 0;
    virtual uint16_t read_mem_word(uint32_t address) = 0;
    virtual uint32_t read_mem_long(uint32_t address) = 0;

    virtual void read_memblock_byte(uint32_t address, QByteArray &arr) = 0;
    virtual void read_memblock_word(uint32_t address, QByteArray &arr) = 0;
    virtual void read_memblock_long(uint32_t address, QByteArray &arr) = 0;

    virtual void write_mem_byte(uint32_t address, uint8_t byte) = 0;
    virtual void write_mem_word(uint32_t address, uint16_t word) = 0;
    virtual void write_mem_long(uint32_t address, uint32_t longw) = 0;

    virtual void write_memblock_byte(uint32_t address, QByteArray &arr) = 0;
    virtual void write_memblock_word(uint32_t address, QByteArray &arr) = 0;
    virtual void write_memblock_long(uint32_t address, QByteArray &arr) = 0;

    virtual uint32_t read_reg(int regNum) = 0;
    virtual void write_reg(int regnum, uint32_t value) = 0;

    virtual uint32_t read_creg(int regNum) = 0;
    virtual void write_creg(int regnum, uint32_t value) = 0;

    virtual uint32_t read_dbgreg(int regnum) = 0;
    virtual void write_dbgreg(int regnum, uint32_t value) = 0;
};

#endif // BDMDEVICE_H
