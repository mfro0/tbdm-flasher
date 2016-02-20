#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>
#include <qfiledialog.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QByteArray convertSRecords(QString s)
{
    QByteArray data;
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
