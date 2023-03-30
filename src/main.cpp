#include <iostream>
#include <QApplication>

#include "mainwindow.h"
#include "../include/config.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
