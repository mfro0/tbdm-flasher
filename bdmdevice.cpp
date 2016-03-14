#include "bdmdevice.h"
#include "bdmcommand.h"

/*
 * bdmdevice.cpp
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
 * along with BaS_gcc.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Copyright 2016        M. Froeschle
 *
 *
 */

BDMDevice::BDMDevice()
{
}

BDMDevice::~BDMDevice()
{

}

quint8 BDMDevice::getVersion(void)
{
    int ret;

    BDMCommand cmd(GET_VERSION);

    ret = sendCommand(cmd);
    if (ret)
        return cmd.getBytes()->at(2);

    return -1;
}

int BDMDevice::getLastStatus(void)
{
    int ret;
    BDMCommand cmd(GET_LAST_STATUS);

    ret = sendCommand(cmd);

    if (ret)
        return cmd.getBytes()->at(2);

    return -1;
}

int BDMDevice::reset(void)
{
    int ret;
    BDMCommand cmd(RESET);

    ret = sendCommand(cmd);

    if (ret)
        return cmd.getBytes()->at(2);

    return -1;
}

int BDMDevice::getStatus(void)
{
    BDMCommand cmd(GET_STATUS);
    int ret;

    ret = sendCommand(cmd);
    if (ret)
        return cmd.getBytes()->at(2);

    return -1;
}

int BDMDevice::halt(void)
{
    int ret;
    BDMCommand cmd(HALT);

    ret = sendCommand(cmd);

    if (ret)
        return cmd.getBytes()->at(2);

    return -1;
}

int BDMDevice::go(void)
{
    int ret;
    BDMCommand cmd(GO);

    ret = sendCommand(cmd);

    if (ret)
        return cmd.getBytes()->at(2);

    return -1;
}

int BDMDevice::step(void)
{
    int ret;
    BDMCommand cmd(STEP);

    ret = sendCommand(cmd);

    if (ret)
        return cmd.getBytes()->at(2);

    return -1;
}

int BDMDevice::resync(void)
{
    int ret;
    BDMCommand cmd(RESYNC);

    ret = sendCommand(cmd);

    if (ret)
        return cmd.getBytes()->at(2);

    return -1;
}

int BDMDevice::assertTA(void)
{
    int ret;
    BDMCommand cmd(ASSERT_TA);

    ret = sendCommand(cmd);

    if (ret)
        return cmd.getBytes()->at(2);

    return -1;
}

quint8 BDMDevice::readMemByte(quint32 address)
{
    quint8 val = 0;
    BDMCommand cmd;

    sendCommand(cmd);

    return val;
}

quint16 BDMDevice::readMemWord(quint32 address)
{
    BDMCommand cmd;
    quint16 val = 0;

    sendCommand(cmd);

    return val;
}

quint32 BDMDevice::readMemLong(quint32 address)
{
    BDMCommand cmd;
    quint32 val = 0;

    sendCommand(cmd);
    return val;
}

void BDMDevice::readMemblockByte(quint32 address, QByteArray &arr)
{
    BDMCommand cmd;

    sendCommand(cmd);
}

void BDMDevice::readMemblockWord(quint32 address, QByteArray &arr)
{
    BDMCommand cmd;

    sendCommand(cmd);
}

void BDMDevice::readMemblockLong(quint32 address, QByteArray &arr)
{
    BDMCommand cmd(READ_MEMBLOCK_LONG);

    cmd.setBytes(&arr);
    sendCommand(cmd);
}

void BDMDevice::writeMemByte(quint32 address, quint8 byte)
{
    BDMCommand cmd;

    sendCommand(cmd);
}

void BDMDevice::writeMemWord(quint32 address, quint16 word)
{
    BDMCommand cmd;

    sendCommand(cmd);
}

void BDMDevice::writeMemLong(quint32 address, quint32 longw)
{
    BDMCommand cmd;

    sendCommand(cmd);
}

void BDMDevice::writeMemblockByte(quint32 address, QByteArray &arr)
{
    BDMCommand cmd;

    sendCommand(cmd);
}

void BDMDevice::writeMemblockWord(quint32 address, QByteArray &arr)
{
    BDMCommand cmd;

    sendCommand(cmd);
}

void BDMDevice::writeMemblockLong(quint32 address, QByteArray &arr)
{
    BDMCommand cmd;

    sendCommand(cmd);
}

quint32 BDMDevice::readReg(int regNum)
{
    BDMCommand cmd;
    quint32 regValue = 0;

    sendCommand(cmd);

    return regValue;
}

void BDMDevice::writeReg(int regnum, quint32 value)
{
    BDMCommand cmd;

    sendCommand(cmd);
}

quint32 BDMDevice::readCReg(int regNum)
{
    BDMCommand cmd;

    quint32 regValue = 0;

    sendCommand(cmd);

    return regValue;
}

void BDMDevice::writeCReg(int regnum, quint32 value)
{
    BDMCommand cmd;

    sendCommand(cmd);
}

quint32 BDMDevice::readDbgReg(int regnum)
{
    quint32 regValue = 0;
    BDMCommand cmd;

    sendCommand(cmd);

    return regValue;
}

void BDMDevice::writeDbgReg(int regnum, quint32 value)
{
    BDMCommand cmd;

    sendCommand(cmd);
}
