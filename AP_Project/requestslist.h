#ifndef REQUESTSLIST_H
#define REQUESTSLIST_H

#include <QDialog>
#include "global.h"
#include "startandend.h"

class requestsList : public QDialog
{
    Q_OBJECT

public:
    explicit requestsList(QWidget *parent = 0);
    ~requestsList();

private:
    QListWidget * li_result;
    QLabel * titleLabel;
    QLabel * IDLabel;
    QPushButton * acceptButton;
    QPushButton * declineButton;
    QLineEdit * IDLineEdit;



private slots:

    void declineButtonClicked();
    void acceptButtonClicked();

};

#endif // REQUESTSLIST_H
