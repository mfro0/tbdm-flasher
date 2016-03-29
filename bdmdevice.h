/*
 * bdmdevice.h
 *
 * This file is part of tbdm.
 *
 * tbdm is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * tbdm is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with tbdm.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Copyright 2016        M. Froeschle
 *
 *
 */

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
    virtual quint8 getVersion(void);
    virtual int getLastStatus(void);

    virtual int reset(void);
    virtual int getStatus(void);
    virtual int halt(void);
    virtual int go(void);
    virtual int step(void);
    virtual int resync(void);
    virtual int assertTA(void);

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
    virtual int sendCommand(BDMCommand &command) = 0;

    QHash<QString, QString> deviceParameters;

};

#endif // BDMDEVICE_H
