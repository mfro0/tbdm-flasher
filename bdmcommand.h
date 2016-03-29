/*
 * bdmcommand.h
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

#ifndef BDMCOMMAND_H
#define BDMCOMMAND_H


enum BDMCommandCode
{
    GET_VERSION,
    GET_LAST_STATUS,
    RESET,
    GET_STATUS,
    HALT,
    GO,
    STEP,
    RESYNC,
    ASSERT_TA,
    READ_MEM_BYTE,
    READ_MEM_WORD,
    READ_MEM_LONG,
    READ_MEMBLOCK_BYTE,
    READ_MEMBLOCK_WORD,
    READ_MEMBLOCK_LONG,
    WRITE_MEM_BYTE,
    WRITE_MEM_WORD,
    WRITE_MEM_LONGWORD,
    WRITE_MEMBLOCK_BYTE,
    WRITE_MEMBLOCK_WORD,
    WRITE_MEMBLOCK_LONG,
    READ_REG,
    WRITE_REG,
    READ_CREG,
    WRITE_CREG,
    READ_DBGREG,
    WRITE_DBGREG
};

class QByteArray;


class BDMCommand
{
public:
    BDMCommand();
    BDMCommand(BDMCommandCode cmd);
    ~BDMCommand();

    void setCommand(BDMCommandCode cmd) { command = cmd; }
    BDMCommandCode cmd(void);
    quint8 *getOutBytes(void) { return out_buffer; }
    void setOutBytes(quint8 *data, size_t length);
    size_t outBytesLength(void) { return out_buffer_size; }

    quint8 *getInBytes(void) { return in_buffer; }
    void setInBytes(quint8 *data, size_t length);
    size_t inBytesLength(void) { return in_buffer_size; }
private:
    BDMCommandCode command;
    quint8 *in_buffer;
    size_t in_buffer_size;

    quint8 *out_buffer;
    size_t out_buffer_size;
};

#endif // BDMCOMMAND_H
