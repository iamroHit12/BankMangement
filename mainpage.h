#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QMainWindow>
#include "withdraw.h"
#include "mainwindow.h"
#include "deposit.h"
#include "transfer.h"

namespace Ui {
class MainPage;
}

class MainPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainPage(QWidget *parent = nullptr);
    ~MainPage();

private slots:
    void on_pushButton_withdraw_clicked();

    void on_pushButton_openaccount_clicked();

    void on_pushButton_deposit_clicked();

    void on_pushButton_transfer_clicked();

private:
    Ui::MainPage *ui;
    withdraw *Withdraw;
    MainWindow *mainwindow;
    deposit *Deposit;
    transfer *Transfer;
};

#endif // MAINPAGE_H
