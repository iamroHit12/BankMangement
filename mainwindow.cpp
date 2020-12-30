#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainpage.h"


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


void MainWindow::on_pushButton_menu_clicked()
{
    MainPage *mainpage = new MainPage();
    mainpage->show();
    this->hide();
}
