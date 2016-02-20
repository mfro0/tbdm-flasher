#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>
#include <qfiledialog.h>
#include <QSerialPortInfo>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QList<QSerialPortInfo> ports = QSerialPortInfo::availablePorts();

    for (int i = 0; i < ports.size(); i++)
    {
        ui->portName->addItem(ports.at(i).portName());
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


QByteArray convertSRecords(QString s)
{
    QByteArray data;
    bool failure;
    long address;
    int size;

    if (s.leftRef(1).at(0) != 'S')
    {
        qDebug() << "illegal S-Record found" << endl;
        return data;
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
            address = s.midRef(4, 8).toLong(&failure, 16);
            size = s.midRef(2, 2).toInt(&failure, 16);

            qDebug() << QString("S3 record found. Address = 0x%1").arg(address, 8, 16) <<
                        ", size = " << size;
            break;

        case 4:
            break;
    }
    qDebug() << s << endl;

    return data;
}

void MainWindow::readFile(void)
{
    QString s19Filename = QFileDialog::getOpenFileName(this,
                                                       tr("select .s19 file to flash"),
                                                       ".",
                                                       tr("*.s19"));
    QFile f(s19Filename);
    QFileInfo fi(f);
    if (! f.open(QIODevice::Text | QIODevice::ReadOnly))
    {
        return;
    }

    QByteArray data;
    int length = 0;
    int size = fi.size();

    while (! f.atEnd())
    {
        QString line = f.readLine();
        length += line.length();
        double percentage = (double) length / (double) size * 100.0;
        ui->progressBar->setValue((int) percentage);
        data.append(convertSRecords(line));
    }
    f.close();

    filenameChanged(fi.fileName() + "(" + fi.created().toString() + ")");
    ui->flashButton->setEnabled(true);


}
