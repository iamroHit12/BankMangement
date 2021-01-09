#ifndef WITHDRAW_H
#define WITHDRAW_H

#include <QMainWindow>

namespace Ui {
class withdraw;
}

class withdraw : public QMainWindow
{
    Q_OBJECT

public:
    explicit withdraw(QWidget *parent = nullptr);
    ~withdraw();

private slots:

    void on_pushButton_clicked();

private:
    Ui::withdraw *ui;
};

#endif // WITHDRAW_H
