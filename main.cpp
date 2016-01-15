#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget wid;
    MainWindow w(&wid);
    w.show();

    return a.exec();
}
