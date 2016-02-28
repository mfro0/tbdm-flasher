#include "flasherwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FlasherWindow w;
    w.show();

    return a.exec();
}
