#ifndef PROFILE_H
#define PROFILE_H

#include <QWidget>
#include"mainwindow.h"
namespace Ui {
class Profile;
}

class Profile : public QWidget
{
    Q_OBJECT

public:
    head user;
    explicit Profile(QWidget *parent = nullptr,head user=nullptr);
    ~Profile();

private slots:
    void on_save_clicked();

    void on_mainmenu_clicked();

private:
    Ui::Profile *ui;
};

#endif // PROFILE_H
