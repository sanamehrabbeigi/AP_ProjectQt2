#include "mainwindow.h"
#include "global.h"
#include <QApplication>
#include "startandend.h"

int main(int argc, char *argv[])
{
    //start();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
