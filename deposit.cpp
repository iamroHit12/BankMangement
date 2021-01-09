#include "deposit.h"
#include "ui_deposit.h"
#include "mainpage.h"
#include "mainwindow.h"
#include <QString>
#include "admin.h"
#include <QDebug>
#include<QMessageBox>

deposit::deposit(QWidget *parent,head user):
    QMainWindow(parent),
    user(user),
    ui(new Ui::deposit)
{
    ui->setupUi(this);

}

deposit::~deposit()
{
    delete ui;
}

void deposit::on_pushButton_deposit_clicked()
{
  QString amount = ui->lineEdit_3->text();
  user->balance+=amount.toInt();
  qDebug()<<"transaction completed";
}

void deposit::on_pushButton_mainmenu_clicked()
{
    qDebug()<<"deposit clicked";
    if(MainWindow::session=="user")
    {
        MainPage *mainPage = new MainPage(nullptr,user);
        mainPage->show();
    }
    else
    {
        Admin *admin = new Admin();
        admin->show();
    }
    this->hide();
}
