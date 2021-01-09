#ifndef WITHDRAW_H
#define WITHDRAW_H

#include <QMainWindow>
#include "mainwindow.h"
namespace Ui
{
class withdraw;
}

class withdraw : public QMainWindow
{
    Q_OBJECT

public:
    head user;
    explicit withdraw(QWidget *parent = nullptr,head account=nullptr);
    ~withdraw();

private slots:

    void on_pushButton_clicked();

    void on_pushButton_main_clicked();

private:
    Ui::withdraw *ui;
};

#endif // WITHDRAW_H
