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

private:
    void sendCommand(BDMCommand *command);
    quint32 receiveResult(void);
};

#endif // TEENSYBDMDEVICE_H
