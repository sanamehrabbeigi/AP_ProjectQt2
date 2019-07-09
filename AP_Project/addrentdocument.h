#ifndef ADDRENTDOCUMENT_H
#define ADDRENTDOCUMENT_H

#include "global.h"

class addRentDocument : public QDialog
{
    Q_OBJECT

public:
    explicit addRentDocument(QWidget *parent = 0);
    ~addRentDocument();

private slots:
    void clearButtonClicked();
    void addButtonClicked();

private:
    QComboBox * typeComboBox;

    QPushButton * clearButton;
    QPushButton * addButton;

    QLabel * typeLabel;
    QLabel * IDLabel;
    QLabel * commisionLabel;
    QLabel * durationOfRentLabel;

    QLineEdit * IDLineEdit;
    QLineEdit * commisionLineEdit;
    QLineEdit * durationOfRentLineEdit;

};

#endif // ADDRENTDOCUMENT_H
