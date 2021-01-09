#include "withdraw.h"
#include "ui_withdraw.h"
#include "mainpage.h"

withdraw::withdraw(QWidget *parent) :
    QMainWindow(parent),
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
    MainPage *mainPage = new MainPage();
    mainPage->show();
    this->hide();
}
