#include "admin.h"
#include "ui_admin.h"
#include "withdraw.h"
#include "deposit.h"
#include "transfer.h"
#include "login.h"
#include "mainwindow.h"
#include"userlist.h"
#include"usertransactions.h"
#include<QDebug>
Admin::Admin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);
    ui->userInfo->hide();
    MainWindow::session="admin";
}

Admin::~Admin()
{
    delete ui;
}

void Admin::on_moneWithdrawal_clicked()
{
    withdraw *w = new withdraw(nullptr,user);
    w->show();
    this->hide();
}

void Admin::on_moneyDeposit_clicked()
{
    deposit *d = new deposit(nullptr,user);
    d->show();
    this->hide();
}

void Admin::on_moneyTransfer_clicked()
{
    transfer *t = new transfer(nullptr,user);
    t->show();
    this->hide();
}


void Admin::on_searchUser_clicked()
{


  head temp = MainWindow::user_top;
  bool flag =false;
  if(temp)
  {

      int account = ui->userSearch->text()!=""?(ui->userSearch->text()).toInt():-1;
      do
      {
          if(temp->account==account)
          {
              flag=true;
              qDebug()<<account;
              user=temp;
              break;
          }
          else{
              temp=temp->next;
          }
      }
      while(temp!=0);
      if(flag)
      {
          ui->name->setText(temp->name);
          ui->aadhaar->setText(temp->aadhar);
          ui->account_no->setText(QString::number(temp->account));
          ui->balance->setText(QString::number(temp->balance));
          ui->mobile->setText(temp->phone);
          ui->userInfo->show();
      }
      else{
          qDebug()<<"Invalid account no.";
          ui->userInfo->hide();
      }
  }
  else
  {
      qDebug()<<"No User Found";
  }
}

void Admin::on_newAccount_clicked()
{
  MainWindow *mainWindow = new MainWindow();
  mainWindow->show();
  this->hide();
}

void Admin::on_logout_clicked()
{
   Login *login = new Login();
   login->show();
   this->hide();
}

void Admin::on_pushButton_clicked()
{
    UserList *list = new UserList();
    list->show();
    this->hide();

}

void Admin::on_transactions_clicked()
{
    Usertransactions *transaction = new Usertransactions(nullptr,user);
    transaction->show();
    this->hide();
}
