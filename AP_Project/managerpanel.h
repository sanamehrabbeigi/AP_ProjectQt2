#ifndef MANAGERPANEL_H
#define MANAGERPANEL_H

#include "global.h"
#include "addnorthvilladiag.h"
#include "addsouthvilladiag.h"
#include "addrentdocument.h"
#include "addsalediag.h"
#include "addpicture.h"
#include "showpicture.h"
#include "showmanagerdiag.h"

class managerPanel : public QDialog
{
    Q_OBJECT
    //LineEdits
    QLineEdit * apartmentIDLineEdit;
    QLineEdit * floorNumberLineEdit;
    QLineEdit * totalSpaceLineEdit;
    QLineEdit * numberOfFloorsLineEdit;
    QLineEdit * pricePerMeterLineEdit;
    QLineEdit * addressLineEdit;
    QLineEdit * buildingSpaceLineEdit;
    QLineEdit * apartmentIdLineEdit;
    QLineEdit * houseIdLineEdit;


    //Labels
    QLabel * totalSpaceLabel;
    QLabel * numberOfFloorsLabel;
    QLabel * elevatorsLabel;
    QLabel * pricePerMeterLabel;
    QLabel * addressLabel;
    QLabel * apartmentIdLabel;
    QLabel * apartmentModeLabel;


    QLabel * numberOfRoomsLabel;
    QLabel * apartmentIDLabel;
    QLabel * floorNumberLabel;
    QLabel * buildingSpaceLabel;
    QLabel * useLabel;
    QLabel * houseIdLabel;
    QLabel * houseModeLabel;



    //ComboBox
        //Add Apartment
    QComboBox * elevatorsComboBox;
    QComboBox * apartmentModeComboBox;
        //Add House
    QComboBox * useComboBox;
    QComboBox * numberOfRoomsComboBox;
    QComboBox * houseModeComboBox;

    //Buttons
    QPushButton * addApartmentButton;
    QPushButton * addPictureButton;
    QPushButton * addApartmentCancelButton;
    QPushButton * apartmentOkButton;
    QPushButton * apartmentFindIDButton;

    QPushButton * addHouseButton;
    QPushButton * addHouseClearButton;
    QPushButton * houseOkButton;
    QPushButton * houseFindIDButton;

    QString k_id;

public:
    explicit managerPanel(QWidget *parent = 0);
    ~managerPanel();


private slots:
    //Add Apartment
    void addPictureButtonClicked();
    void addApartmentCancelButtonClicked();
    void addApartmentButtonClicked();
    void apartmentOkButtonClicked();
    void apartmentFindIDButtonClicked();

    //Add House
    void addHouseButtonClicked();
    void addHouseClearButtonClicked();
    void houseOkButtonClicked();
    void houseFindIDButtonClicked();




private:
    QTabWidget * mainTab = new QTabWidget;

};

#endif // MANAGERPANEL_H
