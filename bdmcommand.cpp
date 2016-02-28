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
    delete data;
}

