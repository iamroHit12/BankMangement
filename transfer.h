#ifndef TRANSFER_H
#define TRANSFER_H
#include "mainwindow.h"

#include <QMainWindow>

namespace Ui {
class transfer;
}

class transfer : public QMainWindow
{
    Q_OBJECT

public:
    head user;
    explicit transfer(QWidget *parent = nullptr,head user=nullptr);
    ~transfer();

private slots:
    void on_pushButton_main_clicked();

    void on_pushButton_clicked();

private:
    Ui::transfer *ui;
};

#endif // TRANSFER_H
