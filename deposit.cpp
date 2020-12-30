#include "deposit.h"
#include "ui_deposit.h"
#include "mainpage.h"

deposit::deposit(QWidget *parent) :
    QMainWindow(parent),
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

}

void deposit::on_pushButton_mainmenu_clicked()
{
    MainPage *mainPage = new MainPage();
    mainPage->show();
    this->hide();
}
