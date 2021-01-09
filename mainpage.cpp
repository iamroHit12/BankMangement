#include "mainpage.h"
#include"mainwindow.h"
#include"login.h"
#include "ui_mainpage.h"
head MainPage::user;
MainPage::MainPage(QWidget *parent,head ptr) :

    QMainWindow(parent),
    ui(new Ui::MainPage)
{
    ui->setupUi(this);
    ui->name->setText(ptr->name);
    user=ptr;
}

MainPage::~MainPage()
{
    delete ui;
}

void MainPage::on_pushButton_withdraw_clicked()
{
    hide();
    Withdraw = new withdraw();
    Withdraw->show();
}

void MainPage::on_pushButton_openaccount_clicked()
{
    hide();
    mainwindow = new MainWindow(this);
    mainwindow->show();
}

void MainPage::on_pushButton_deposit_clicked()
{
    hide();
    Deposit = new deposit(this);
    Deposit->show();
}

void MainPage::on_pushButton_transfer_clicked()
{
    hide();
    Transfer = new transfer(this);
    Transfer->show();
}

void MainPage::on_logout_clicked()
{
    Login *login = new Login();
    login->show();
    this->hide();


}
