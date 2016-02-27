#ifndef BDMDEVICE_H
#define BDMDEVICE_H

#include <stdint.h>

class BDMDevice
{
public:
    BDMDevice();

    // BDM commands
    virtual void getVersion(void) = 0;
    virtual void getLastStatus(void) = 0;

    virtual void reset(void) = 0;
    virtual void getStatus(void) = 0;
    virtual void halt(void) = 0;
    virtual void go(void) = 0;
    virtual void step(void) = 0;
    virtual void resync(void) = 0;
    virtual void assertTA(void) = 0;

    virtual uint8_t read_mem_byte(uint32_t address) = 0;
    virtual uint16_t read_mem_word(uint32_t address) = 0;
    virtual uint32_t read_mem_long(uint32_t address) = 0;
};

#endif // BDMDEVICE_H
