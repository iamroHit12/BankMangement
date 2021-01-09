#include "transfer.h"
#include "ui_transfer.h"
#include "mainpage.h"
#include "mainwindow.h"
#include "admin.h"
#include <QDebug>
transfer::transfer(QWidget *parent,head user) :
    QMainWindow(parent),
    user(user),
    ui(new Ui::transfer)
{
    ui->setupUi(this);
}

transfer::~transfer()
{
    delete ui;
}

void transfer::on_pushButton_main_clicked()
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

void transfer::on_pushButton_clicked()
{
    bool flag=false;
    int account = ui->lineEdit->text().toInt();
    int amount = ui->lineEdit_2->text().toInt();
    head temp =MainWindow::user_top;
    do
    {
       if(temp->account==account)
       {
           flag=true;
           break;
       }

       else
           temp=temp->next;

    }
    while(temp!=0);
    if(flag)
    {
        qDebug()<<amount<<"and balance is"<<user->balance;
        if(amount<user->balance)
        {
            qDebug()<<"done";
            user->balance-=amount;
            temp->balance+=amount;
        }
        else
        {
            qDebug()<<"Insufficient balance";
        }

    }
    else
    {
        qDebug()<<"Use not found";
    }
}
