#include "addnorthvilladiag.h"


addNorthVillaDiag::addNorthVillaDiag(QWidget *parent) :
    QDialog(parent)
{
    areaOfFrontYardLineEdit = new QLineEdit();
    areaOfBackYardLineEdit = new QLineEdit();
    pricePerMeterLineEdit = new QLineEdit();
    addressLineEdit = new QLineEdit();
    buildingSpaceLineEdit = new QLineEdit();
    totalSpaceLineEdit = new QLineEdit();
    IDLineEdit = new QLineEdit();

    numberOfRoomsComboBox = new QComboBox();
    numberOfRoomsComboBox->addItem("0");
    numberOfRoomsComboBox->addItem("1");
    numberOfRoomsComboBox->addItem("2");
    numberOfRoomsComboBox->addItem("3");
    numberOfRoomsComboBox->addItem("4");
    numberOfRoomsComboBox->addItem("5");


    modeComboBox = new QComboBox();
    modeComboBox->addItem("Add");
    modeComboBox->addItem("Edit");


    areaOfFrontYardLabel = new QLabel("Area Of Front Yard");
    areaOfBackYardLabel = new QLabel("Area Of Back Yard");
    buildingSpaceLabel = new QLabel("Building Space");
    totalSpaceLabel = new QLabel("Total Space");
    pricePerMeterLabel = new QLabel("Price per Meter");
    numberOfRoomsLabel = new QLabel("Number of Rooms");
    addressLabel = new QLabel("Address");
    IDLabel = new QLabel("ID");
    modeLabel = new QLabel("Mode");


    okMode = new QPushButton("Ok");
    applyID = new QPushButton("Find ID");
    addButton = new QPushButton("Apply");
    ClearButton = new QPushButton("Clear");



    //connect
    connect(addButton, SIGNAL(clicked(bool)), this, SLOT(addButtonClicked()));
    connect(ClearButton, SIGNAL(clicked(bool)), this, SLOT(clearButtonClicked()));
    connect(okMode, SIGNAL(clicked(bool)), this, SLOT(okModeClicked()));
    connect(applyID, SIGNAL(clicked(bool)), this, SLOT(applyIDClicked()));


    //Layouts
    QHBoxLayout * modeBox = new QHBoxLayout();
    QHBoxLayout * IDBox = new QHBoxLayout();
    QVBoxLayout * rightBox = new QVBoxLayout();
    QVBoxLayout * leftBox = new QVBoxLayout();
    QHBoxLayout * buttonsBox = new QHBoxLayout();
    QHBoxLayout * mainLayout = new QHBoxLayout();
    QVBoxLayout * page = new QVBoxLayout();



    modeBox->addWidget(modeComboBox);
    modeBox->addWidget(okMode);


    IDBox->addWidget(IDLineEdit);
    IDBox->addWidget(applyID);

    leftBox->addWidget(modeLabel);
    leftBox->addWidget(IDLabel);
    leftBox->addWidget(buildingSpaceLabel);
    leftBox->addWidget(totalSpaceLabel);
    leftBox->addWidget(pricePerMeterLabel);
    leftBox->addWidget(numberOfRoomsLabel);
    leftBox->addWidget(addressLabel);
    leftBox->addWidget(areaOfFrontYardLabel);
    leftBox->addWidget(areaOfBackYardLabel);



    rightBox->addLayout(modeBox);
    rightBox->addLayout(IDBox);
    rightBox->addWidget(buildingSpaceLineEdit);
    rightBox->addWidget(totalSpaceLineEdit);
    rightBox->addWidget(pricePerMeterLineEdit);
    rightBox->addWidget(numberOfRoomsComboBox);
    rightBox->addWidget(addressLineEdit);
    rightBox->addWidget(areaOfFrontYardLineEdit);
    rightBox->addWidget(areaOfBackYardLineEdit);



    buttonsBox->addWidget(ClearButton);
    buttonsBox->addWidget(addButton);


    mainLayout->addLayout(leftBox);
    mainLayout->addLayout(rightBox);

    IDLabel->hide();
    IDLineEdit->hide();
    applyID->hide();

    page->addLayout(modeBox);
    page->addLayout(IDBox);
    page->addLayout(mainLayout);
    page->addLayout(buttonsBox);

    setLayout(page);

}

addNorthVillaDiag::~addNorthVillaDiag()
{

}

void addNorthVillaDiag::addButtonClicked()
{
    if (modeComboBox->currentIndex() == 0){
        northVilla temp;
        temp.set_address(addressLineEdit->text());
        temp.set_area_of_back_yard(areaOfBackYardLineEdit->text().toInt());
        temp.set_area_of_front_yard(areaOfFrontYardLineEdit->text().toInt());
        temp.set_building_space(buildingSpaceLineEdit->text().toInt());
        temp.set_m_username(current_user);
        temp.set_number_of_rooms(numberOfRoomsComboBox->currentIndex());
        temp.set_price_per_metr(pricePerMeterLineEdit->text().toDouble());
        temp.set_total_space(totalSpaceLineEdit->text().toInt());
        temp.cal_total_price();
        qDebug () << temp.getId();
        v_northVilla.push_back(temp);
        qDebug () << v_northVilla[v_northVilla.size()-1].getId();
        end();
        QMessageBox * msg = new QMessageBox;
        msg->setText("Villa Added Successfuly.");
        msg->setIcon(QMessageBox::Information);
        msg->setWindowTitle("ERROR!");
        msg->exec();
    }else if(modeComboBox->currentIndex() == 1){
        QString ID = IDLineEdit->text();
        for (int i = 0; i < v_northVilla.size(); ++i){
            if (v_northVilla[i].getId() == ID){
                v_northVilla[i].set_address(addressLineEdit->text());
                v_northVilla[i].set_area_of_back_yard(areaOfBackYardLineEdit->text().toInt());
                v_northVilla[i].set_area_of_front_yard(areaOfFrontYardLineEdit->text().toInt());
                v_northVilla[i].set_building_space(buildingSpaceLineEdit->text().toInt());
                v_northVilla[i].set_m_username(current_user);
                v_northVilla[i].set_number_of_rooms(numberOfRoomsComboBox->currentIndex());
                v_northVilla[i].set_price_per_metr(pricePerMeterLineEdit->text().toDouble());
                v_northVilla[i].set_total_space(totalSpaceLineEdit->text().toInt());
                v_northVilla[i].cal_total_price();
                end();
                QMessageBox * msg = new QMessageBox;
                msg->setText("Villa Edited Successfuly.");
                msg->setIcon(QMessageBox::Information);
                msg->setWindowTitle("ERROR!");
                msg->exec();
                break;
            }
        }
    }
}

void addNorthVillaDiag::clearButtonClicked()
{
    IDLineEdit->setText("");
    buildingSpaceLineEdit->setText("");
    totalSpaceLineEdit->setText("");
    areaOfBackYardLineEdit->setText("");
    areaOfFrontYardLineEdit->setText("");
    addressLineEdit->setText("");
    pricePerMeterLineEdit->setText("");
    numberOfRoomsComboBox->setCurrentIndex(0);
}



void addNorthVillaDiag::okModeClicked()
{
    if (modeComboBox->currentIndex() == 0){
        IDLabel->hide();
        IDLineEdit->hide();
        applyID->hide();
    }else{
        IDLabel->show();
        IDLineEdit->show();
        applyID->show();
    }

}

void addNorthVillaDiag::applyIDClicked()
{
    QString ID = IDLineEdit->text();
    for (int i = 0; i < v_northVilla.size(); ++i){
        if (v_northVilla[i].getId() == ID){
            totalSpaceLineEdit->setText(QString::number(v_northVilla[i].get_total_space()));
            pricePerMeterLineEdit->setText(QString::number(v_northVilla[i].get_price_per_metr()));
            areaOfBackYardLineEdit->setText(QString::number(v_northVilla[i].get_area_of_back_yard()));
            areaOfFrontYardLineEdit->setText(QString::number(v_northVilla[i].get_area_of_front_yard()));
            numberOfRoomsComboBox->setCurrentIndex(v_northVilla[i].get_number_of_rooms());
            addressLineEdit->setText(v_northVilla[i].get_address());
            buildingSpaceLineEdit->setText(QString::number(v_northVilla[i].get_building_space()));
            break;
        }
    }

}
