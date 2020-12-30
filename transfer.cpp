#include "transfer.h"
#include "ui_transfer.h"
#include "mainpage.h"

transfer::transfer(QWidget *parent) :
    QMainWindow(parent),
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
    MainPage *mainPage = new MainPage();
    mainPage->show();
    this->hide();
}
