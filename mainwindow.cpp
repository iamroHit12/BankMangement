#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainpage.h"
#include "admin.h"
#include <QString>
#include"QDebug"
#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
head MainWindow::user_top;
int MainWindow::count;
QString MainWindow::session;
head next;
bool first = true;
QString gender_name[2] = {"Male", "Female"};
QString type[2] = {"Saving","Current"};
QString gen_rand(int account)
{
    QString tmp_s;
    const char alphanum[] =
           "0123456789"
           "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
           "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < 7; ++i)
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];

    tmp_s+=QString::number(account);
    return tmp_s;

}


void MainWindow::on_pushButton_clicked()
{
    QString name = ui->customer_name->text();
    QString aadhar = ui->aadhar_no->text();
    QString gender = gender_name[ui->gender->currentIndex()];
    QString account_type = type[ui->account_type->currentIndex()];

    QString number = ui->phone_no->text();
    QString dob=ui->dateEdit->text();
    int opening_amount = (ui->min_amount->text()).toInt();

    User *user = new User();
    user->name =name;
    user->aadhar =aadhar;
    user->gender=gender;
    user->account_type=account_type;
    user->balance =opening_amount;
    user->phone=number;
    user->dob=dob;
    user->account=count;
    QString password= gen_rand(count);
    user->password= password;
    user->next=0;

    if(first)
     {
     user_top=user;
     next=user;
     first = false;
     }
    else
     {
        next->next=user;
        next=user;
     }
    QString a = QString::number(count);
      count++;
    QMessageBox::about(this,"User confirmation","account no. is "+a+"and password is "+ password);
}


void MainWindow::on_pushButton_menu_clicked()
{
    //MainPage *mainpage = new MainPage();
    //mainpage->show();
    Admin *admin = new Admin();
    admin->show();
    this->hide();
}
