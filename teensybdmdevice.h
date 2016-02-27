#ifndef TEENSYBDMDEVICE_H
#define TEENSYBDMDEVICE_H
#include "bdmdevice.h"

class BDMCommand;

class TeensyBDMDevice : public BDMDevice
{
public:
    TeensyBDMDevice();
    virtual void open();
    virtual void close();

    // BDM commands
    virtual void getVersion(void);
    virtual void getLastStatus(void);

    virtual void reset(void);
    virtual uint32_t getStatus(void) = 0;
    virtual void halt(void) = 0;
    virtual void go(void) = 0;
    virtual void step(void) = 0;
    virtual void resync(void) = 0;
    virtual void assertTA(void) = 0;

    virtual uint8_t read_mem_byte(uint32_t address);
    virtual uint16_t read_mem_word(uint32_t address);
    virtual uint32_t read_mem_long(uint32_t address);

    virtual void read_memblock_byte(uint32_t address, QByteArray &arr);
    virtual void read_memblock_word(uint32_t address, QByteArray &arr);
    virtual void read_memblock_long(uint32_t address, QByteArray &arr);

    virtual void write_mem_byte(uint32_t address, uint8_t byte);
    virtual void write_mem_word(uint32_t address, uint16_t word);
    virtual void write_mem_long(uint32_t address, uint32_t longw);

    virtual void write_memblock_byte(uint32_t address, QByteArray &arr);
    virtual void write_memblock_word(uint32_t address, QByteArray &arr);
    virtual void write_memblock_long(uint32_t address, QByteArray &arr);

    virtual uint32_t read_reg(int regNum);
    virtual void write_reg(int regnum, uint32_t value);

    virtual uint32_t read_creg(int regNum);
    virtual void write_creg(int regnum, uint32_t value);

    virtual uint32_t read_dbgreg(int regnum);
    virtual void write_dbgreg(int regnum, uint32_t value);

private:
    void send_command(BDMCommand *command);
    uint32_t receive_result(void);
};

#endif // TEENSYBDMDEVICE_H
