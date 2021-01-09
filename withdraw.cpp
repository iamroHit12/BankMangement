#include "withdraw.h"
#include "ui_withdraw.h"
#include"admin.h"
#include "mainpage.h"
#include<QDebug>

withdraw::withdraw(QWidget *parent,head user) :
    QMainWindow(parent),
    user(user),
    ui(new Ui::withdraw)
{
    ui->setupUi(this);

}

withdraw::~withdraw()
{
    delete ui;
}


void withdraw::on_pushButton_clicked()
{
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

void withdraw::on_pushButton_main_clicked()
{
    int amount = ui->lineEdit->text().toInt();
    if(user->balance<amount)
    {

        qDebug()<<"Not allowed low balance";
    }
    else
    {
        user->balance-=amount;

        qDebug()<<"transaction completed";
    }
}
