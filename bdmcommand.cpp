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
}

BDMCommand::BDMCommand(BDMCommandCode cmd)
{
    data = new QByteArray();
    data->append((quint8) (cmd & 0xff));
    data->append((quint8) (cmd >> 8));
}

BDMCommand::~BDMCommand()
{
    // delete data;
}

