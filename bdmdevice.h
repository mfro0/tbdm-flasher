#ifndef BDMDEVICE_H
#define BDMDEVICE_H

#include <QtGlobal>

class QByteArray;
class BDMCommand;

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
    virtual quint8 getStatus(void) = 0;
    virtual void halt(void) = 0;
    virtual void go(void) = 0;
    virtual void step(void) = 0;
    virtual void resync(void) = 0;
    virtual void assertTA(void) = 0;

    virtual quint8 read_mem_byte(quint32 address) = 0;
    virtual quint16 read_mem_word(quint32 address) = 0;
    virtual quint32 read_mem_long(quint32 address) = 0;

    virtual void read_memblock_byte(quint32 address, QByteArray &arr) = 0;
    virtual void read_memblock_word(quint32 address, QByteArray &arr) = 0;
    virtual void read_memblock_long(quint32 address, QByteArray &arr) = 0;

    virtual void write_mem_byte(quint32 address, quint8 byte) = 0;
    virtual void write_mem_word(quint32 address, quint16 word) = 0;
    virtual void write_mem_long(quint32 address, quint32 longw) = 0;

    virtual void write_memblock_byte(quint32 address, QByteArray &arr) = 0;
    virtual void write_memblock_word(quint32 address, QByteArray &arr) = 0;
    virtual void write_memblock_long(quint32 address, QByteArray &arr) = 0;

    virtual quint32 read_reg(int regNum) = 0;
    virtual void write_reg(int regnum, quint32 value) = 0;

    virtual quint32 read_creg(int regNum) = 0;
    virtual void write_creg(int regnum, quint32 value) = 0;

    virtual quint32 read_dbgreg(int regnum) = 0;
    virtual void write_dbgreg(int regnum, quint32 value) = 0;

private:
    virtual void send_command(BDMCommand *command) = 0;
    virtual quint32 receive_result(void) = 0;

};

#endif // BDMDEVICE_H
