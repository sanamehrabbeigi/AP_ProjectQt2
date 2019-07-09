#ifndef ADDNORTHVILLADIAG_H
#define ADDNORTHVILLADIAG_H

#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QComboBox>
#include <QWidget>
#include <QLineEdit>

#include "global.h"
#include "startandend.h"


class addNorthVillaDiag : public QDialog
{
    Q_OBJECT

public:
    explicit addNorthVillaDiag(QWidget *parent = 0);
    ~addNorthVillaDiag();

private slots:
    void addButtonClicked();
    void clearButtonClicked();
    void okModeClicked();
    void applyIDClicked();

private:


    QLineEdit * areaOfFrontYardLineEdit;
    QLineEdit * areaOfBackYardLineEdit;
    QLineEdit * pricePerMeterLineEdit;
    QLineEdit * addressLineEdit;
    QLineEdit * buildingSpaceLineEdit;
    QLineEdit * totalSpaceLineEdit;
    QLineEdit * IDLineEdit;


    QComboBox * numberOfRoomsComboBox;
    QComboBox * modeComboBox;



    QLabel * areaOfFrontYardLabel;
    QLabel * areaOfBackYardLabel;
    QLabel * buildingSpaceLabel;
    QLabel * totalSpaceLabel;
    QLabel * pricePerMeterLabel;
    QLabel * numberOfRoomsLabel;
    QLabel * addressLabel;
    QLabel * modeLabel;
    QLabel * IDLabel;


    QPushButton * okMode;
    QPushButton * applyID;
    QPushButton * addButton;
    QPushButton * ClearButton;




};

#endif // ADDNORTHVILLADIAG_H
