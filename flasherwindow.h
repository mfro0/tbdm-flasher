/*
 * flasherwindow.h
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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "bdmdevice.h"

namespace Ui
{
    class MainWindow;
}

class FlashFile;

class FlasherWindow : public QMainWindow
{
    Q_OBJECT

signals:

private slots:
    void readFile(void);
    void flashFile(void);

public:
    explicit FlasherWindow(QWidget *parent = 0);
    ~FlasherWindow();

private:
    void flashBlock(QByteArray *block);
    Ui::MainWindow *ui;
    FlashFile *f;
    BDMDevice *dev;
};

class FlashFile : public QObject
{
    Q_OBJECT

public:
    explicit FlashFile(void);
    ~FlashFile(void);

    int read(QString);
    bool convertSRecords(QString &s);
    bool checkChecksum(QString &s, quint32 address, quint8 byte_count, QByteArray &data);
    int fileSize() { return binary->size(); }
    QByteArray *data() { return binary; }
private:
    QByteArray *binary;
};

#endif // MAINWINDOW_H
