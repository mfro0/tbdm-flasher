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

    void setCommand(BDMCommandCode cmd) { this->cmd = cmd; }
    const QByteArray *getBytes(void) { return data; }

private:
    BDMCommandCode cmd;
    QByteArray *data;
};

#endif // BDMCOMMAND_H
