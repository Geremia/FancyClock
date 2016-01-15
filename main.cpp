#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setOrganizationName(QString("Geremia"));
    a.setApplicationName(QString("Fancy Clock"));


    QWidget wid;
    MainWindow w(&wid);
    w.show();

    return a.exec();
}
