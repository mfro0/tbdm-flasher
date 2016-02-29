#ifndef TEENSYBDMDEVICE_H
#define TEENSYBDMDEVICE_H
#include "bdmdevice.h"

class BDMCommand;
class QSerialPort;

class TeensyBDMDevice : public BDMDevice
{
public:
    TeensyBDMDevice();
    ~TeensyBDMDevice();

    virtual void open();
    virtual void close();

private:
    virtual void sendCommand(BDMCommand *command);
    virtual quint32 receiveResult(void);

    QSerialPort *serial;
};

#endif // TEENSYBDMDEVICE_H
