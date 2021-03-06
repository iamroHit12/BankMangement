#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "transaction.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

typedef struct user{
    QString name;
    int account;
    QString password;
    QString gender;
    QString account_type;
    QString dob;
    QString phone;
    QString aadhar;
    Transaction *transaction;
    int balance;
    struct user *next;

} User ,*head;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    static head user_top  ;
    static QString session;
    static int count;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_menu_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
