#include "mainpage.h"
#include"mainwindow.h"
#include"login.h"
#include "ui_mainpage.h"
#include "userlist.h"
#include"usertransactions.h"
#include<QDebug>
head MainPage::user;
MainPage::MainPage(QWidget *parent,head ptr) :
    QMainWindow(parent),
    ui(new Ui::MainPage)
{
    ui->setupUi(this);
    MainWindow::session="user";
    ui->name->setText(ptr->name);
    if(ptr)
    {
         user=ptr;
    }
}

MainPage::~MainPage()
{
    delete ui;
}

void MainPage::on_pushButton_withdraw_clicked()
{
    hide();
    Withdraw = new withdraw(nullptr,user);
    Withdraw->show();
}


void MainPage::on_pushButton_transfer_clicked()
{
    hide();
    Transfer = new transfer(nullptr,user);
    Transfer->show();
}

void MainPage::on_logout_clicked()
{
    Login *login = new Login();
    login->show();
    this->hide();


}

void MainPage::on_pushButton_openaccount_clicked()
{

}

void MainPage::on_transaction_clicked()
{
    Usertransactions *transaction = new Usertransactions(nullptr,user);
    transaction->show();
    this->hide();
}
