#include "mainpage.h"
#include "ui_mainpage.h"

MainPage::MainPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainPage)
{
    ui->setupUi(this);
}

MainPage::~MainPage()
{
    delete ui;
}

void MainPage::on_pushButton_withdraw_clicked()
{
    hide();
    Withdraw = new withdraw(this);
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
