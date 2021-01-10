#include "userlist.h"
#include "ui_userlist.h"
#include"mainwindow.h"
#include"mainpage.h"
#include<QLabel>
#include<QTableWidgetItem>
#include<QString>
#include"admin.h"
UserList::UserList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserList)
{

    ui->setupUi(this);
    int count=0;
    head temp = MainWindow::user_top;
    if(temp)
    {
        do
        {
            ui->tableWidget->setRowCount(count+1);
            QTableWidgetItem *item= new QTableWidgetItem(temp->name);
            ui->tableWidget->setItem(count,0,item);
            item = new QTableWidgetItem(QString::number(temp->account));
            ui->tableWidget->setItem(count,1,item);
            item = new QTableWidgetItem(temp->account_type);
            ui->tableWidget->setItem(count,2,item);
            item = new QTableWidgetItem(temp->dob);
            ui->tableWidget->setItem(count,3,item);
            item = new QTableWidgetItem(temp->phone);
            ui->tableWidget->setItem(count,4,item);
            count++;
            temp=temp->next;

        }while(temp!=0);
    }


}

UserList::~UserList()
{
    delete ui;
}

void UserList::on_pushButton_clicked()
{
    Admin *admin = new Admin();
    admin->show();
    this->hide();
}
