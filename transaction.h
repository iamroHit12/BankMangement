#ifndef TRANSACTION_H
#define TRANSACTION_H
#include<QString>
typedef struct transaction{
    QString type;
    QString Date;
    int amount;
    QString recepient;
    struct transaction *next;
}Transaction;


#endif // TRANSACTION_H
