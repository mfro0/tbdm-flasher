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

    virtual quint8 readMemByte(quint32 address);
    virtual quint16 readMemWord(quint32 address);
    virtual quint32 readMemLong(quint32 address);

    virtual void readMemblockByte(quint32 address, QByteArray &arr);
    virtual void readMemblockWord(quint32 address, QByteArray &arr);
    virtual void readMemblockLong(quint32 address, QByteArray &arr);

    virtual void writeMemByte(quint32 address, quint8 byte);
    virtual void writeMemWord(quint32 address, quint16 word);
    virtual void writeMemLong(quint32 address, quint32 longw);

    virtual void writeMemblockByte(quint32 address, QByteArray &arr);
    virtual void writeMemblockWord(quint32 address, QByteArray &arr);
    virtual void writeMemblockLong(quint32 address, QByteArray &arr);

    virtual quint32 readReg(int regNum);
    virtual void writeReg(int regnum, quint32 value);

    virtual quint32 readCReg(int regNum);
    virtual void writeCReg(int regnum, quint32 value);

    virtual quint32 readDbgReg(int regnum);
    virtual void writeDbgReg(int regnum, quint32 value);

private:
    void sendCommand(BDMCommand *command);
    quint32 receiveResult(void);
};

#endif // TEENSYBDMDEVICE_H
