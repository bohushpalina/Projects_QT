#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    int N = 3;
    MainWindow w(nullptr, N);
    w.show();
    return a.exec();
}
