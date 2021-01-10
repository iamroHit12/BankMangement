#include "profile.h"
#include "ui_profile.h"
#include <QDate>
#include<QDebug>
#include<QString>
#include"mainpage.h"
#include<QMessageBox>
Profile::Profile(QWidget *parent,head user) :
    QWidget(parent),
    user(user),
    ui(new Ui::Profile)
{
    ui->setupUi(this);
    QDate date = QDate::fromString(user->dob,"dd.MM.yyyy");
    QString account = QString::number(user->account);
    ui->dateEdit->setDate(date);
    ui->name->setText(user->name);
    ui->aadhar->setText(user->aadhar);
    ui->account->setText(account);
    ui->type->setText(user->account_type);
}

Profile::~Profile()
{
    delete ui;
}

void Profile::on_save_clicked()
{
  user->name = ui->name->text();
  user->aadhar = ui->aadhar->text();
  user->phone = ui->phone->text();
  user->dob = ui->dateEdit->date().toString("dd.MM.yyyy");
  QMessageBox::information(this,"Success","User details saved");

}

void Profile::on_mainmenu_clicked()
{
     MainPage *mainpage = new MainPage(nullptr,user);
     mainpage->show();
     this->hide();
}
