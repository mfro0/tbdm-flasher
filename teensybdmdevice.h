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
    virtual quint8 getStatus(void) = 0;
    virtual void halt(void) = 0;
    virtual void go(void) = 0;
    virtual void step(void) = 0;
    virtual void resync(void) = 0;
    virtual void assertTA(void) = 0;

    virtual quint8 read_mem_byte(quint32 address);
    virtual quint16 read_mem_word(quint32 address);
    virtual quint32 read_mem_long(quint32 address);

    virtual void read_memblock_byte(quint32 address, QByteArray &arr);
    virtual void read_memblock_word(quint32 address, QByteArray &arr);
    virtual void read_memblock_long(quint32 address, QByteArray &arr);

    virtual void write_mem_byte(quint32 address, quint8 byte);
    virtual void write_mem_word(quint32 address, quint16 word);
    virtual void write_mem_long(quint32 address, quint32 longw);

    virtual void write_memblock_byte(quint32 address, QByteArray &arr);
    virtual void write_memblock_word(quint32 address, QByteArray &arr);
    virtual void write_memblock_long(quint32 address, QByteArray &arr);

    virtual quint32 read_reg(int regNum);
    virtual void write_reg(int regnum, quint32 value);

    virtual quint32 read_creg(int regNum);
    virtual void write_creg(int regnum, quint32 value);

    virtual quint32 read_dbgreg(int regnum);
    virtual void write_dbgreg(int regnum, quint32 value);

private:
    void send_command(BDMCommand *command);
    quint32 receive_result(void);
};

#endif // TEENSYBDMDEVICE_H
