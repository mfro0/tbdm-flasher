/*
 * bdmcommand.cpp
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

#include <QByteArray>

#include "bdmcommand.h"

BDMCommand::BDMCommand()
{
    out_buffer = 0L;
    out_buffer_size = 0;

    in_buffer = 0L;
    in_buffer_size = 0;
}

BDMCommand::BDMCommand(BDMCommandCode cmd)
{
    this->cmd = cmd;
    out_buffer = 0;
    in_buffer = 0;
}

BDMCommand::~BDMCommand()
{
    if (out_buffer != 0L)
        delete [] out_buffer;
    if (in_buffer != 0L)
        delete [] in_buffer;
}

void BDMCommand::setOutBytes(quint8 *data, size_t length)
{
    this->out_buffer = new quint8[length];
    if (this->out_buffer != 0L)
    {
        memcpy(this->out_buffer, data, length);
        out_buffer_size = length;

        return;
    }
    out_buffer_size = 0;
}

void BDMCommand::setInBytes(quint8 *data, size_t length)
{
    this->in_buffer = new quint8[length];
    if (this->in_buffer != 0L)
    {
        memcpy(this->in_buffer, data, length);
        in_buffer_size = length;

        return;
    }
    in_buffer_size = 0;
}
