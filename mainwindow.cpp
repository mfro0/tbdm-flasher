#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>
#include <qfiledialog.h>
#include <QSerialPortInfo>

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
    filenameChanged(fi.fileName() + "(" + fi.created().toString() + ")");

    f->read(s19Filename);

    ui->flashButton->setEnabled(true);
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

    int length = 0;
    int size = fi.size();

    while (! f.atEnd())
    {
        QString line = f.readLine();
        length += line.length();
        double percentage = (double) length / (double) size * 100.0;
        // ui->progressBar->setValue((int) percentage);
        convertSRecords(line);
    }
    f.close();
    qDebug() << binary;

    return 0;
}

bool FlashFile::checkChecksum(QString &s, uint32_t address, uint8_t byte_count, QByteArray &data)
{
    uint16_t cs = 0;
    bool ok;

    union swap_uint32
    {
        uint32_t i;
        uint8_t a[4];
    };

    swap_uint32 addr;

    addr.i = address;
    uint8_t tmp = addr.a[0];
    addr.a[0] = addr.a[3];
    addr.a[3] = tmp;

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
    qDebug() << "checksum check failed. S-Record = " << srec_cs << " data = " << cs << endl;
    return false;
}

int FlashFile::convertSRecords(QString &s)
{
    bool good;
    long address;
    int byte_count;

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
            address = s.midRef(4, 8).toLong(&good, 16);
            byte_count = s.midRef(2, 2).toInt(&good, 16);

            for (int i = 12; i <= byte_count * 2; i += 2)
            {
                uint8_t byte;
                QByteArray data;

                byte = s.midRef(i, 2).toInt(&good, 16);
                if (good)
                {
                    data.append(byte);
                }
                else
                {
                    return -1;
                }
                // calculate and compare checksum
                if (checkChecksum(s, address, byte_count, data) == 0)
                {
                    binary->append(data);
                }
                else
                {
                    return -1;
                }
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
    qDebug() << s << endl;

    return 0;
}
