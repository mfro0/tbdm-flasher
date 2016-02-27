#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>
#include <qfiledialog.h>
#include <QSerialPortInfo>
#include <QtDebug>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QList<QSerialPortInfo> ports = QSerialPortInfo::availablePorts();

    for (int i = 0; i < ports.size(); i++)
    {
        ui->portName->addItem(ports.at(i).portName());
    }
    f = new FlashFile();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete f;
}




void MainWindow::readFile(void)
{
    QString s19Filename = QFileDialog::getOpenFileName(this,
                                                       tr("select .s19 file to flash"),
                                                       ".",
                                                       tr("*.s19"));

    QFileInfo fi(s19Filename);
    filenameChanged(fi.fileName() + " (" + fi.created().toString() + ")");

    f->read(s19Filename);
    qDebug() << "file size = " << f->fileSize() << endl;

    filenameChanged(fi.fileName() + ", " + QString("%1").arg(f->fileSize()) + " Bytes, " +
                    fi.created().toString());

    ui->flashButton->setEnabled(true);
}

void MainWindow::flashFile(void)
{
    const int blockSize = 4096;

    qDebug() << "flashFile()" << endl;
    if (f->data() != NULL)
    {
        for (int i = 0; i < f->data()->length(); i += blockSize)
        {
            QByteArray block = f->data()->mid(i, blockSize);

            for (int j = 0; j < blockSize; j++)
            {
                qDebug() << QString("%1").arg((int) block.at(i)) << endl;
            }

        }
    }
}

FlashFile::FlashFile(void)
{
    binary = new QByteArray;
}

FlashFile::~FlashFile(void)
{
    delete binary;
}

int FlashFile::read(QString s19Filename)
{
    QFile f(s19Filename);
    QFileInfo fi(f);
    if (! f.open(QIODevice::Text | QIODevice::ReadOnly))
    {
        return -1;
    }

    while (! f.atEnd())
    {
        QString line = f.readLine();

        if (!convertSRecords(line))
        {
            break;
        }
    }
    f.close();

    qDebug() << binary->length() << "bytes read." << endl;

    return 0;
}

uint16_t byteSwap(uint16_t w)
{
    return ((w & 0xff) << 8) | ((w & 0xff00) >> 8);
}

uint32_t byteSwap(uint32_t l)
{
    return byteSwap((uint16_t)((l >> 16) & 0xffff)) | byteSwap((uint16_t)((l << 16) & 0xffff0000));
}

bool FlashFile::checkChecksum(QString &s, uint32_t address, uint8_t byte_count, QByteArray &data)
{
    uint16_t cs = 0;
    bool ok;

    uint8_t srec_cs = s.midRef(s.length() - 3, 2).toInt(&ok, 16);
    if (!ok)
    {
        qDebug() << "ckecksum conversion failed" << endl;
        return false;
    }

    for (int i = 24; i >= 0; i -= 8)
    {
        uint8_t byte = (uint8_t) (address >> i) & 0xff;
        cs += byte;
    }

    cs += byte_count;

    for (int i = 0; i < data.size(); i++)
    {
        cs += data.at(i);
    }
    cs = ~cs & 0xff;

    if (cs == srec_cs)
    {
        return true;
    }
    qDebug() << "checksum check failed. S-Record = " <<
                QString("%1").arg(srec_cs, 0, 16) << " data = " <<
                QString("%1").arg(cs, 0, 16) <<
                "data.size() = " << data.size() <<
                endl;
    qDebug() << QString("%1").arg(data.size() + 5, 0, 16) << QString("%1").arg((long) address, 0, 16) << data.toHex() << endl;
    return false;
}

bool FlashFile::convertSRecords(QString &s)
{
    bool good;
    uint32_t address;
    int byte_count;
    QByteArray data;

    if (s.leftRef(1).at(0) != 'S')
    {
        qDebug() << "illegal S-Record found" << endl;
        return -1;
    }

    switch (s.midRef(1, 1).at(0).digitValue())
    {
        case 0:
            qDebug() << "S0 header found." << endl;
            break;

        case 1:
            qDebug() << "S1 record found" << endl;
            break;

        case 2:
            qDebug() << "S2 record found" << endl;
            break;

        case 3:
            address = s.midRef(4, 8).toULong(&good, 16);
            if (!good)
            {
                qDebug() << "address conversion failed!" << endl;
                return false;
            }

            byte_count = s.midRef(2, 2).toInt(&good, 16);

            for (int i = 12; i <= (byte_count - 6) * 2 + 12; i += 2)
            {
                uint8_t byte;

                byte = s.midRef(i, 2).toInt(&good, 16);
                if (good)
                {
                    data.append(byte);
                }
                else
                {
                    qDebug() << "data conversion failed!" << endl;
                    return false;
                }
            }

            // calculate and compare checksum
            if (checkChecksum(s, address, byte_count, data))
            {
                binary->append(data);
            }
            else
            {
                return false;
            }
            break;

        case 5:
            break;

        case 6:
            break;

        case 7:
            break;

        case 8:
            break;

        case 9:
            break;

        default:
            qDebug() << "illegal S-Record " << s << endl;
    }

    return true;
}
