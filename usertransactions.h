#ifndef USERTRANSACTIONS_H
#define USERTRANSACTIONS_H

#include <QWidget>
#include"mainwindow.h"
namespace Ui {
class Usertransactions;
}

class Usertransactions : public QWidget
{
    Q_OBJECT

public:
    head user;
    explicit Usertransactions(QWidget *parent = nullptr,head user=nullptr);
    ~Usertransactions();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Usertransactions *ui;
};

#endif // USERTRANSACTIONS_H
