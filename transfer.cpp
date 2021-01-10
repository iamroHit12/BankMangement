#include "transfer.h"
#include "ui_transfer.h"
#include "mainpage.h"
#include "mainwindow.h"
#include "admin.h"
#include<QMessageBox>
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
        if(amount<=user->balance)
        {
            Transaction *last_transaction=user->transaction;
            Transaction *reciever_last_transaction=temp->transaction;
            if(last_transaction)
            {
                while(last_transaction->next!=0){
                    last_transaction=last_transaction->next;
                }


            }
             Transaction *new_transaction=new Transaction();
             Transaction *new_reciever_transaction=new Transaction();
             new_transaction->amount=amount;
             new_transaction->Date=ui->dateEdit->date().toString("dd.MM.yyyy");
             new_transaction->type="Sent";
             new_transaction->next=0;
             new_transaction->recepient=ui->lineEdit->text();
             last_transaction->next=new_transaction;
             new_reciever_transaction->amount=amount;
             new_reciever_transaction->Date=ui->dateEdit->date().toString("dd.MM.yyyy");
             new_reciever_transaction->type="Recieved";
             new_reciever_transaction->next=0;
             reciever_last_transaction->next=new_reciever_transaction;
             user->balance-=amount;
             temp->balance+=amount;
             QMessageBox::information(this,"Transaction succesfull","Money sent");
        }
        else
        {

            QMessageBox::warning(this,"Invalid amount","amount exceeds balance");
        }

    }
    else
    {

        QMessageBox::warning(this,"Bad credentials","Invalid account no.");
    }
}
