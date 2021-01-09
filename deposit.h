#ifndef DEPOSIT_H
#define DEPOSIT_H

#include <QMainWindow>
#include "mainwindow.h"

namespace Ui {
class deposit;
}

class deposit : public QMainWindow
{
    Q_OBJECT

public:
    head user;
    explicit deposit(QWidget *parent = nullptr,head user=nullptr);
    ~deposit();

private slots:
    void on_pushButton_deposit_clicked();

    void on_pushButton_mainmenu_clicked();

private:
    Ui::deposit *ui;
};

#endif // DEPOSIT_H
