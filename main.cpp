#include "mainwindow.h"
#include "mainpage.h"
#include "login.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   // MainWindow w;
    //MainPage mp;
    Login login;
    login.show();
    return a.exec();
}
