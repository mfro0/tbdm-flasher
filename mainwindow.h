#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <stdint.h>

namespace Ui {
class MainWindow;
}

class FlashFile;

class MainWindow : public QMainWindow
{
    Q_OBJECT

signals:
    void filenameChanged(QString);

public slots:
    void readFile(void);

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    Ui::MainWindow *ui;
    FlashFile *f;
};

class FlashFile : public QObject
{
    Q_OBJECT

public:
    explicit FlashFile(void);
    ~FlashFile(void);

    int read(QString);
    int convertSRecords(QString &s);

    bool checkChecksum(QString &s, uint32_t address, uint8_t byte_count, QByteArray &data);

private:
    QByteArray *binary;
};

#endif // MAINWINDOW_H
