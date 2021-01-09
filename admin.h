#ifndef ADMIN_H
#define ADMIN_H
#include <QWidget>
namespace Ui {
class Admin;
}

class Admin : public QWidget
{
    Q_OBJECT

public:

    explicit Admin(QWidget *parent = nullptr);
    ~Admin();

private slots:
    void on_moneWithdrawal_clicked();

    void on_moneyDeposit_clicked();

    void on_moneyTransfer_clicked();

    void on_searchUser_clicked();

    void on_newAccount_clicked();

    void on_logout_clicked();

private:
    Ui::Admin *ui;
};

#endif // ADMIN_H
