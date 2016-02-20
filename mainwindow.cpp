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

void MainWindow::readFile(void)
{
    QString s19Filename = QFileDialog::getOpenFileName(this,
                                                       tr("select .s19 file to flash"),
                                                       ".",
                                                       tr("*.s19"));
}
