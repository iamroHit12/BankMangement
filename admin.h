#ifndef ADMIN_H
#define ADMIN_H
#include <QWidget>
#include"mainwindow.h"
namespace Ui {
class Admin;
}

class Admin : public QWidget
{
    Q_OBJECT

public:
    head user;
    explicit Admin(QWidget *parent = nullptr);
    ~Admin();

private slots:
    void on_moneWithdrawal_clicked();

    void on_moneyDeposit_clicked();

    void on_moneyTransfer_clicked();

    void on_searchUser_clicked();

    void on_newAccount_clicked();

    void on_logout_clicked();

    void on_pushButton_clicked();

    void on_transactions_clicked();

private:
    Ui::Admin *ui;
};

#endif // ADMIN_H
