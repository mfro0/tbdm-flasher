#ifndef BDMDEVICE_H
#define BDMDEVICE_H

#include <QtGlobal>
#include <QString>
#include <QHash>

class QByteArray;
class BDMCommand;

class BDMDevice
{
public:
    BDMDevice();
    ~BDMDevice();

    virtual void setDeviceParameters(QHash<QString, QString> params) { deviceParameters = params; }
    virtual QHash<QString, QString> &getDeviceParameters(void) { return deviceParameters; }

    virtual void open() = 0;
    virtual void close() = 0;

    // BDM commands
    virtual void getVersion(void);
    virtual void getLastStatus(void);

    virtual void reset(void) = 0;
    virtual quint8 getStatus(void) = 0;
    virtual void halt(void) = 0;
    virtual void go(void) = 0;
    virtual void step(void) = 0;
    virtual void resync(void) = 0;
    virtual void assertTA(void) = 0;

    virtual quint8 readMemByte(quint32 address) = 0;
    virtual quint16 readMemWord(quint32 address) = 0;
    virtual quint32 readMemLong(quint32 address) = 0;

    virtual void readMemblockByte(quint32 address, QByteArray &arr) = 0;
    virtual void readMemblockWord(quint32 address, QByteArray &arr) = 0;
    virtual void readMemblockLong(quint32 address, QByteArray &arr) = 0;

    virtual void writeMemByte(quint32 address, quint8 byte) = 0;
    virtual void writeMemWord(quint32 address, quint16 word) = 0;
    virtual void writeMemLong(quint32 address, quint32 longw) = 0;

    virtual void writeMemblockByte(quint32 address, QByteArray &arr) = 0;
    virtual void writeMemblockWord(quint32 address, QByteArray &arr) = 0;
    virtual void writeMemblockLong(quint32 address, QByteArray &arr) = 0;

    virtual quint32 readReg(int regNum) = 0;
    virtual void writeReg(int regnum, quint32 value) = 0;

    virtual quint32 readCReg(int regNum) = 0;
    virtual void writeCReg(int regnum, quint32 value) = 0;

    virtual quint32 readDbgReg(int regnum) = 0;
    virtual void writeDbgReg(int regnum, quint32 value) = 0;

private:
    virtual void sendCommand(BDMCommand &command) = 0;
    virtual quint32 receiveResult(void) = 0;

    QHash<QString, QString> deviceParameters;

};

#endif // BDMDEVICE_H
