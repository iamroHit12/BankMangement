#include "login.h"
#include "ui_login.h"
#include "admin.h"
#include "mainwindow.h"
#include"mainpage.h"
#include<QDebug>
Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    ui->admin_password->setEchoMode(QLineEdit::Password);
    ui->user_password->setEchoMode(QLineEdit::Password);

}

Login::~Login()
{
    delete ui;
}

void Login::on_adminLogin_clicked()
{
   Admin *admin = new Admin();
   QString id = ui->admin_id->text();
   QString password = ui->admin_password->text();

   if(id=="admin"&&password=="password")
   {
       admin->show();
       this->hide();
   }
   else
   {

   }

}

void Login::on_userLogin_clicked()
{
    QString user_id =ui->user_account->text();
    QString password = ui->user_password->text();

    head temp=MainWindow::user_top;
    qDebug()<<"user login clicked";
    if(temp)
    {
         qDebug()<<temp->name;
        do{
            if(user_id==QString::number(temp->account))
            {
                if(password==temp->password)
                {
                    MainPage *m = new MainPage(nullptr,temp);
                    m->show();
                    this->hide();
                    break;

                }
                else
                {
                    qDebug()<<"Password wrong";
                }
                break;
            }
            else
            {
                qDebug()<<"User not registered";
            }
            temp=temp->next;

        }
        while(temp!=0);

    }
    else{
        qDebug()<<"NO User registered";
    }

}
