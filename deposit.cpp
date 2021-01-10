#include <QDebug>
#include<QMessageBox>
#include <QString>
#include "deposit.h"
#include "ui_deposit.h"
#include "mainpage.h"
#include "mainwindow.h"
#include "admin.h"
#include "transaction.h"


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
   Transaction *last_transaction=user->transaction;

   if(last_transaction)
   {
       while(last_transaction->next!=0){
           last_transaction=last_transaction->next;
       }


   }
  QString amount = ui->lineEdit_3->text();
  user->balance+=amount.toInt();
  Transaction *new_transaction=new Transaction();
  new_transaction->amount=amount.toInt();
  new_transaction->Date=ui->dateEdit->text();
  new_transaction->type="Deposit";
  new_transaction->next=0;
  last_transaction->next=new_transaction;

  QMessageBox::information(this,"Deposit","Transaction completed");
}

void deposit::on_pushButton_mainmenu_clicked()
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
