#ifndef ADDSOUTHVILLADIAG_H
#define ADDSOUTHVILLADIAG_H

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

class addSouthVillaDiag : public QDialog
{
    Q_OBJECT

public:
    explicit addSouthVillaDiag(QWidget *parent = 0);
    ~addSouthVillaDiag();

private slots:
    void addButtonClicked();
    void clearButtonClicked();

    void applyIDButtonClicked();
    void modeButtonClicked();


private:

    QLineEdit * areaOfYardLineEdit;
    QLineEdit * areaOfParkingLineEdit;
    QLineEdit * pricePerMeterLineEdit;
    QLineEdit * addressLineEdit;
    QLineEdit * buildingSpaceLineEdit;
    QLineEdit * totalSpaceLineEdit;
    QLineEdit * IDLineEdit;

    QComboBox * numberOfRoomsComboBox;
    QComboBox * modeComboBox;

    QLabel * areaOfYardLabel;
    QLabel * areaOfParkingLabel;
    QLabel * buildingSpaceLabel;
    QLabel * totalSpaceLabel;
    QLabel * pricePerMeterLabel;
    QLabel * numberOfRoomsLabel;
    QLabel * addressLabel;
    QLabel * IDLabel;
    QLabel * modeLabel;



    QPushButton * addButton;
    QPushButton * ClearButton;
    QPushButton * addPictureButton;
    QPushButton * modeButton;
    QPushButton * applyIDButton;


};

#endif // ADDNORTHVILLADIAG_H
