#ifndef ADDSALEDIAG_H
#define ADDSALEDIAG_H

#include "global.h"

class addSaleDiag : public QDialog
{
    Q_OBJECT

public:
    explicit addSaleDiag(QWidget *parent = 0);
    ~addSaleDiag();

private slots:
    void addButtonClicked();
    void clearButtonClicked();

private:
    QPushButton * addButton;
    QPushButton * clearButton;

    QComboBox * paymentMethodComboBox;
    QComboBox * typeComboBox;

    QLabel * typeLabel;
    QLabel * IDLabel;
    QLabel * commisionLabel;
    QLabel * paymentMethodLabel;

    QLineEdit * IDLineEdit = new QLineEdit;
    QLineEdit * commisionLineEdit = new QLineEdit;





};

#endif // ADDSALEDIAG_H
