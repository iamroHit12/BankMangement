#include "usertransactions.h"
#include "ui_usertransactions.h"
#include "mainwindow.h"
#include"mainpage.h"
#include"transaction.h"
#include"admin.h"
Usertransactions::Usertransactions(QWidget *parent,head user) :
    QWidget(parent),
    user(user),
    ui(new Ui::Usertransactions)
{
    ui->setupUi(this);
    int count =0;
    Transaction *temp = user->transaction;
    if(temp)
    {
        do
        {
            ui->tableWidget->setRowCount(count+1);
            QTableWidgetItem *item= new QTableWidgetItem(temp->type);
            ui->tableWidget->setItem(count,0,item);
            item = new QTableWidgetItem(temp->Date);
            ui->tableWidget->setItem(count,1,item);
            if(temp->type=="Sent")
                item = new QTableWidgetItem(temp->recepient);
            else
                item = new QTableWidgetItem("SELF");
            ui->tableWidget->setItem(count,2,item);
            item = new QTableWidgetItem(QString::number(temp->amount));
            ui->tableWidget->setItem(count,3,item);
            count++;
            temp=temp->next;

        }while(temp!=0);
    }
}

Usertransactions::~Usertransactions()
{
    delete ui;
}

void Usertransactions::on_pushButton_clicked()
{
    if(MainWindow::session=="user")
    {
        MainPage *mainPage = new MainPage(nullptr,user);
        mainPage->show();
    }
    else
    {
        Admin *admin = new Admin();
        admin->show();
    }
    this->hide();

}
