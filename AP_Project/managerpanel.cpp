#include "managerpanel.h"


managerPanel::managerPanel(QWidget *parent) :
    QDialog(parent)
{
    setWindowTitle("Manager Panel");

    //Dialogs
    QDialog * addApartmentDiag = new QDialog();
    QDialog * addHouseDiag = new QDialog();


    //LineEdits
    apartmentIDLineEdit = new QLineEdit();
    floorNumberLineEdit = new QLineEdit();
    totalSpaceLineEdit = new QLineEdit();
    numberOfFloorsLineEdit = new QLineEdit();
    pricePerMeterLineEdit = new QLineEdit();
    addressLineEdit = new QLineEdit();
    buildingSpaceLineEdit = new QLineEdit();
    apartmentIdLineEdit = new QLineEdit();
    houseIdLineEdit = new QLineEdit();


    //Labels
    totalSpaceLabel = new QLabel("Total Space :");
    numberOfFloorsLabel = new QLabel("Number Of Floors :");
    elevatorsLabel = new QLabel("Does it have elevator? ");
    pricePerMeterLabel = new QLabel("Price per Meter :");
    addressLabel = new QLabel("Address");
    apartmentIdLabel = new QLabel("ID");
    apartmentModeLabel = new QLabel("Mode");


    numberOfRoomsLabel = new QLabel("Number Of Rooms");
    apartmentIDLabel = new QLabel("Apartment ID");
    floorNumberLabel = new QLabel("Floor Number");
    buildingSpaceLabel = new QLabel("Building Space");
    useLabel = new QLabel("Use");
    houseIdLabel = new QLabel("ID");
    houseModeLabel = new QLabel("Mode");



    //ComboBox
        //Add Apartment
    elevatorsComboBox = new QComboBox();
    elevatorsComboBox->addItem("Yes");
    elevatorsComboBox->addItem("No");
    apartmentModeComboBox = new QComboBox();
    apartmentModeComboBox -> addItem("Add");
    apartmentModeComboBox -> addItem("Edit");

        //Add House

    useComboBox = new QComboBox();
    useComboBox->addItem("Normal");
    useComboBox->addItem("Adminstrative");
    useComboBox->addItem("Commercial");
    numberOfRoomsComboBox = new QComboBox;
    numberOfRoomsComboBox->addItem("0");
    numberOfRoomsComboBox->addItem("1");
    numberOfRoomsComboBox->addItem("2");
    numberOfRoomsComboBox->addItem("3");
    numberOfRoomsComboBox->addItem("4");
    numberOfRoomsComboBox->addItem("5");
    houseModeComboBox = new QComboBox();
    houseModeComboBox -> addItem("Add");
    houseModeComboBox -> addItem("Edit");

    //Buttons
    addApartmentButton = new QPushButton("Apply");
    addPictureButton = new QPushButton("Add Picture");
    addApartmentCancelButton = new QPushButton("Clear");
    apartmentOkButton = new QPushButton("Ok");
    apartmentFindIDButton = new QPushButton("Find ID");

    addHouseButton = new QPushButton("Apply");
    addHouseClearButton = new QPushButton("Clear");
    houseOkButton = new QPushButton("Ok");
    houseFindIDButton = new QPushButton("Find ID");

    //Hide
    apartmentIdLabel ->hide();
    apartmentIdLineEdit -> hide();
    apartmentFindIDButton ->hide();

    houseIdLabel ->hide();
    houseIdLineEdit -> hide();
    houseFindIDButton ->hide();
    //Layouts

        //Add Apartment
    QHBoxLayout * addressHLayout = new QHBoxLayout();
    QHBoxLayout * totalSpaceHLayout = new QHBoxLayout();
    QHBoxLayout * numberOfFloorsHLayout = new QHBoxLayout();
    QHBoxLayout * elevatorsHLayout = new QHBoxLayout();
    QHBoxLayout * pricePerMeterHLayout = new QHBoxLayout;
    QHBoxLayout * buttonsHLayout = new QHBoxLayout();
    QVBoxLayout * addApartmentMainLayout = new QVBoxLayout();
    QVBoxLayout * mainVLayout = new QVBoxLayout();

    QHBoxLayout * apartmentModeHLayout = new QHBoxLayout();
    QHBoxLayout * apartmentFindIDHLayout = new QHBoxLayout();

    addressHLayout->addWidget(addressLabel);
    addressHLayout->addWidget(addressLineEdit);

    totalSpaceHLayout->addWidget(totalSpaceLabel);
    totalSpaceHLayout->addWidget(totalSpaceLineEdit);

    numberOfFloorsHLayout->addWidget(numberOfFloorsLabel);
    numberOfFloorsHLayout->addWidget(numberOfFloorsLineEdit);

    elevatorsHLayout->addWidget(elevatorsLabel);
    elevatorsHLayout->addWidget(elevatorsComboBox);

    pricePerMeterHLayout->addWidget(pricePerMeterLabel);
    pricePerMeterHLayout->addWidget(pricePerMeterLineEdit);

    buttonsHLayout->addWidget(addApartmentCancelButton);
    buttonsHLayout->addWidget(addPictureButton);
    buttonsHLayout->addWidget(addApartmentButton);

    apartmentModeHLayout ->addWidget(apartmentModeLabel);
    apartmentModeHLayout ->addWidget(apartmentModeComboBox);
    apartmentModeHLayout ->addWidget(apartmentOkButton);

    apartmentFindIDHLayout -> addWidget(apartmentIdLabel);
    apartmentFindIDHLayout -> addWidget(apartmentIdLineEdit);
    apartmentFindIDHLayout -> addWidget(apartmentFindIDButton);

    addApartmentMainLayout->addLayout(apartmentModeHLayout);
    addApartmentMainLayout->addLayout(apartmentFindIDHLayout);

    addApartmentMainLayout->addLayout(totalSpaceHLayout);
    addApartmentMainLayout->addLayout(numberOfFloorsHLayout);
    addApartmentMainLayout->addLayout(pricePerMeterHLayout);
    addApartmentMainLayout->addLayout(elevatorsHLayout);
    addApartmentMainLayout->addLayout(addressHLayout);
    addApartmentMainLayout->addLayout(buttonsHLayout);

    addApartmentDiag->setLayout(addApartmentMainLayout);


        //Add House
    QVBoxLayout * rightBox = new QVBoxLayout();
    QVBoxLayout * leftBox = new QVBoxLayout();
    QHBoxLayout * houseButtonsLayout = new QHBoxLayout();
    QHBoxLayout * widgetsHLayout = new QHBoxLayout();
    QVBoxLayout * addHouseVLayout = new QVBoxLayout();

    QHBoxLayout * houseModeHLayout = new QHBoxLayout();
    QHBoxLayout * houseFindIDHLayout = new QHBoxLayout();

    //for house ??
    houseModeHLayout ->addWidget(houseModeComboBox);
    houseModeHLayout ->addWidget(houseOkButton);

    houseFindIDHLayout -> addWidget(houseIdLineEdit);
    houseFindIDHLayout -> addWidget(houseFindIDButton);

    rightBox->addLayout(houseModeHLayout);
    rightBox->addLayout(houseFindIDHLayout);
    rightBox->addWidget(apartmentIDLineEdit);
    rightBox->addWidget(floorNumberLineEdit);
    rightBox->addWidget(numberOfRoomsComboBox);
    rightBox->addWidget(buildingSpaceLineEdit);
    rightBox->addWidget(useComboBox);

    leftBox->addWidget(houseModeLabel);
    leftBox->addWidget(houseIdLabel);
    leftBox->addWidget(apartmentIDLabel);
    leftBox->addWidget(floorNumberLabel);
    leftBox->addWidget(numberOfRoomsLabel);
    leftBox->addWidget(buildingSpaceLabel);
    leftBox->addWidget(useLabel);

    houseButtonsLayout->addWidget(addHouseClearButton);
    houseButtonsLayout->addWidget(addHouseButton);

    widgetsHLayout->addLayout(leftBox);
    widgetsHLayout->addLayout(rightBox);

    addHouseVLayout->addLayout(widgetsHLayout);
    addHouseVLayout->addLayout(houseButtonsLayout);

    addHouseDiag->setLayout(addHouseVLayout);



    //connect
    connect(addPictureButton, SIGNAL(clicked(bool)), this, SLOT(addPictureButtonClicked()));

    connect(apartmentOkButton, SIGNAL(clicked(bool)), this, SLOT(apartmentOkButtonClicked()));
    connect(apartmentFindIDButton, SIGNAL(clicked(bool)), this, SLOT(apartmentFindIDButtonClicked()));


    connect(addApartmentCancelButton, SIGNAL(clicked(bool)), this, SLOT(addApartmentCancelButtonClicked()));
    connect(addApartmentButton, SIGNAL(clicked(bool)), this, SLOT(addApartmentButtonClicked()));


    connect(addHouseButton, SIGNAL(clicked(bool)), this, SLOT(addHouseButtonClicked()));
    connect(addHouseClearButton, SIGNAL(clicked(bool)), this, SLOT(addHouseClearButtonClicked()));

    connect(houseOkButton, SIGNAL(clicked(bool)), this, SLOT(houseOkButtonClicked()));
    connect(houseFindIDButton, SIGNAL(clicked(bool)), this, SLOT(houseFindIDButtonClicked()));


    //End

    addNorthVillaDiag * northVillaDiag = new addNorthVillaDiag();
    addSouthVillaDiag * southVillaDiag = new addSouthVillaDiag();
    addRentDocument * rentDiag = new addRentDocument();
    addSaleDiag * saleDiag = new addSaleDiag();
    showManagerDiag * managerShowDiag = new showManagerDiag();

    mainTab->addTab(addApartmentDiag, "Add Apartment");
    mainTab->addTab(addHouseDiag, "Add House");
    mainTab->addTab(northVillaDiag, "Add North Villa");
    mainTab->addTab(southVillaDiag, "Add South Villa");
    mainTab->addTab(rentDiag, "Add Rent Document");
    mainTab->addTab(saleDiag, "Add Sale Document");
    mainTab->addTab(managerShowDiag, "Show Habitation");

    mainVLayout->addWidget(mainTab);

    setLayout(mainVLayout);
    this->resize(1000,700);


}

managerPanel::~managerPanel()
{

}

void managerPanel::addPictureButtonClicked()
{
    addPicture * addPicDiag = new addPicture(k_id);
    addPicDiag->exec();
}

void managerPanel::addApartmentCancelButtonClicked()
{
    totalSpaceLineEdit ->setText("");
    numberOfFloorsLineEdit -> setText("");
    pricePerMeterLineEdit -> setText("");
    addressLineEdit -> setText("");
    elevatorsComboBox ->setCurrentIndex(0);
    apartmentIdLineEdit -> setText("");
}

void managerPanel::addApartmentButtonClicked()
{
    if ( apartmentModeComboBox -> currentText() == "Add" )
    {
        apartment apt;
        apt.setTotalSpace(totalSpaceLineEdit -> text().toInt());
        apt.setNumberOfFloors(numberOfFloorsLineEdit -> text().toInt());
        apt.setPricePerMetr(pricePerMeterLineEdit -> text().toInt());
        apt.setElevator( ((elevatorsComboBox -> currentIndex() + 1)%2));
        apt.setAddress(addressLineEdit -> text());
        apt.set_m_username(v_user[index_of_current_user].get_username());
        apt.calTotalPrice();
        k_id = apt.getId();
        v_apartment.push_back(apt);

        QMessageBox * msg = new QMessageBox;
        msg->setText("Apartment Successfully Added!(Now You Can Add Picture!)");
        msg->setIcon(QMessageBox::Information);
        msg->setWindowTitle("YOHOOO!");
        msg->exec();
    }
    else
    {
        for(int i=0;i<v_apartment.size();i++)
            if ( apartmentIdLineEdit ->text() == v_apartment[i].getId() &&  v_apartment[i].get_m_username() == current_user)
            {
                v_apartment[i].setTotalSpace(totalSpaceLineEdit -> text().toInt());
                v_apartment[i].setNumberOfFloors(numberOfFloorsLineEdit -> text().toInt());
                v_apartment[i].setPricePerMetr(pricePerMeterLineEdit -> text().toInt());
                v_apartment[i].setElevator( ((elevatorsComboBox -> currentIndex() + 1)%2));
                v_apartment[i].setAddress(addressLineEdit -> text());
                v_apartment[i].set_m_username(v_user[index_of_current_user].get_username());
                v_apartment[i].calTotalPrice();
                i = v_apartment.size();

                QMessageBox * msg = new QMessageBox;
                msg->setText("Apartment Successfully Edited!");
                msg->setIcon(QMessageBox::Information);
                msg->setWindowTitle("YOHOOO!");
                msg->exec();
            }
    }
    //end();
}

void managerPanel::apartmentOkButtonClicked()
{
    if ( apartmentModeComboBox -> currentText() == "Edit" )
    {
        apartmentIdLabel ->show();
        apartmentIdLineEdit -> show();
        apartmentFindIDButton -> show();
    }
    else
    {
        apartmentIdLabel ->hide();
        apartmentIdLineEdit -> hide();
        apartmentFindIDButton ->hide();
    }
}

void managerPanel::apartmentFindIDButtonClicked()
{
    if ( apartmentModeComboBox -> currentText() == "Edit" )
    {
        bool b =0;
        for(int i=0;i<v_apartment.size();i++)
        {
            if ( apartmentIdLineEdit ->text() == v_apartment[i].getId() )
            {
                 apartment apt = v_apartment[i];
                 if ( apt.get_m_username() == current_user )
                 {
                     totalSpaceLineEdit -> setText(QString::number(apt.getTotalSpace()));
                     numberOfFloorsLineEdit  ->setText(QString::number(apt.getNumberOfFloors()));
                     pricePerMeterLineEdit ->setText(QString::number(apt.getPricePerMetr()));
                     if (apt.getElevator())
                        elevatorsComboBox ->setCurrentIndex(0);
                     else
                        elevatorsComboBox ->setCurrentIndex(1);
                     addressLineEdit -> setText(apt.getAddress());
                    i = v_apartment.size();
                    b =1;
                 }
                 else
                 {
                     QMessageBox * msg = new QMessageBox;
                     msg->setText("Can't Access!");
                     msg->setIcon(QMessageBox::Information);
                     msg->setWindowTitle("ERROR!");
                     msg->exec();
                 }
            }
        }
        if ( b == 0)
        {
            QMessageBox * msg = new QMessageBox;
            msg->setText("Not Valid!");
            msg->setIcon(QMessageBox::Information);
            msg->setWindowTitle("ERROR!");
            msg->exec();
        }
    }
}

void managerPanel::addHouseButtonClicked()
{
    if ( houseModeComboBox -> currentText() == "Add" )
    {
        house h;
        h.setUse(useComboBox -> currentIndex());
        h.setFloorNumber(floorNumberLineEdit -> text().toInt());
        h.setNumberOfRooms(numberOfRoomsComboBox ->currentText().toInt());
        h.setBuildingSpace(buildingSpaceLineEdit ->text().toInt());
        for(int i=0; i<v_apartment.size();i++)
            if ( apartmentIDLineEdit -> text() == v_apartment[i].getId() )
            {
                QVector<house> vh;
                vh =  v_apartment[i].get_v_house_for_apartment();
                vh.push_back(h);
                v_apartment[i].set_v_house_for_apartment(vh);
            }
        QMessageBox * msg = new QMessageBox;
        msg->setText("House Successfully Added!");
        msg->setIcon(QMessageBox::Information);
        msg->setWindowTitle("YOHOOO!");
        msg->exec();
    }
    else
    {
        for(int i=0; i< v_apartment.size();i++)
            if(apartmentIDLineEdit -> text() == v_apartment[i].getId())
                for(int j =0; j< v_apartment[i].get_v_house_for_apartment().size();j++)
                    if( houseIdLineEdit ->text() == v_apartment[i].get_v_house_for_apartment()[j].getId() && v_apartment[i].get_m_username() == current_user)
                    {
                        v_apartment[i].get_v_house_for_apartment()[j].setUse(useComboBox -> currentIndex());
                        v_apartment[i].get_v_house_for_apartment()[j].setFloorNumber(floorNumberLineEdit -> text().toInt());
                        v_apartment[i].get_v_house_for_apartment()[j].setNumberOfRooms(numberOfRoomsComboBox ->currentText().toInt());
                        v_apartment[i].get_v_house_for_apartment()[j].setBuildingSpace(buildingSpaceLineEdit ->text().toInt());
                        j = v_apartment[i].get_v_house_for_apartment().size();
                        i = v_apartment.size();

                        QMessageBox * msg = new QMessageBox;
                        msg->setText("House Successfully Edited!");
                        msg->setIcon(QMessageBox::Information);
                        msg->setWindowTitle("YOHOOO!");
                        msg->exec();
                    }
    }
    //end();
}

void managerPanel::addHouseClearButtonClicked()
{
    apartmentIDLineEdit -> setText("");
    floorNumberLineEdit -> setText("");
    numberOfRoomsComboBox -> setCurrentIndex(0);
    buildingSpaceLineEdit -> setText("");
    useComboBox -> setCurrentIndex(0);
    houseIdLineEdit -> setText("");
}

void managerPanel::houseOkButtonClicked()
{
    if ( houseModeComboBox -> currentText() == "Edit" )
    {
        houseIdLabel ->show();
        houseIdLineEdit -> show();
        houseFindIDButton -> show();
    }
    else
    {
        houseIdLabel ->hide();
        houseIdLineEdit -> hide();
        houseFindIDButton ->hide();
    }
}

void managerPanel::houseFindIDButtonClicked()
{
    if ( houseModeComboBox -> currentText() == "Edit" )
    {
        bool b =0;
        for(int i=0;i<v_apartment.size();i++)
        {
            for(int j=0; j< v_apartment[i].get_v_house_for_apartment().size();j++)
            {
                if ( houseIdLineEdit ->text() == v_apartment[i].get_v_house_for_apartment()[j].getId() )
                {
                     house h = v_apartment[i].get_v_house_for_apartment()[j];
                     if ( v_apartment[i].get_m_username() == current_user )
                     {
                        apartmentIDLineEdit ->setText(v_apartment[i].getId());
                        floorNumberLineEdit ->setText(QString::number(h.getFloorNumber()));
                        numberOfRoomsComboBox -> setCurrentIndex(h.getNumberOfRooms());
                        buildingSpaceLineEdit -> setText(QString::number(h.getBuildingSpace()));
                        useComboBox ->setCurrentIndex(h.getUse());
                        j = v_apartment[i].get_v_house_for_apartment().size();
                        i = v_apartment.size();
                        b =1;
                     }
                     else
                     {
                         QMessageBox * msg = new QMessageBox;
                         msg->setText("Can't Access!");
                         msg->setIcon(QMessageBox::Information);
                         msg->setWindowTitle("ERROR!");
                         msg->exec();
                     }
                }
             }
        }
        if ( b == 0)
        {
            QMessageBox * msg = new QMessageBox;
            msg->setText("Not Valid!");
            msg->setIcon(QMessageBox::Information);
            msg->setWindowTitle("ERROR!");
            msg->exec();
        }
    }
}


