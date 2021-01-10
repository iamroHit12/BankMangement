#ifndef USERLIST_H
#define USERLIST_H

#include <QWidget>

namespace Ui {
class UserList;
}

class UserList : public QWidget
{
    Q_OBJECT

public:
    explicit UserList(QWidget *parent = nullptr);
    ~UserList();

private slots:
    void on_pushButton_clicked();

private:
    Ui::UserList *ui;
};

#endif // USERLIST_H
