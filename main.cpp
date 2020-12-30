#include "mainwindow.h"
#include "mainpage.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    MainPage mp;
    mp.show();
    return a.exec();
}
