/*
 * teensybdmdevice.h
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

#ifndef TEENSYBDMDEVICE_H
#define TEENSYBDMDEVICE_H
#include "bdmdevice.h"

class BDMCommand;
class QSerialPort;
struct libusb_context;
struct libusb_device_handle;

class TeensyBDMDevice : public BDMDevice
{
public:
    TeensyBDMDevice();
    ~TeensyBDMDevice();

    virtual void open();
    virtual void close();
    void findDevices(quint16 product_id);

private:
    libusb_context *ctx;
    libusb_device_handle *dev_handle;
    int dev_count;

    virtual int sendCommand(BDMCommand &command);
};

#endif // TEENSYBDMDEVICE_H
