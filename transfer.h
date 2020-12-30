#ifndef TRANSFER_H
#define TRANSFER_H

#include <QMainWindow>

namespace Ui {
class transfer;
}

class transfer : public QMainWindow
{
    Q_OBJECT

public:
    explicit transfer(QWidget *parent = nullptr);
    ~transfer();

private slots:
    void on_pushButton_main_clicked();

private:
    Ui::transfer *ui;
};

#endif // TRANSFER_H
