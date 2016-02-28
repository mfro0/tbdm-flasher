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
