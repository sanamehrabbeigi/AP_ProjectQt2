#include "addsouthvilladiag.h"

addSouthVillaDiag::addSouthVillaDiag(QWidget *parent) :
    QDialog(parent)
{
    areaOfYardLineEdit = new QLineEdit();
    areaOfParkingLineEdit = new QLineEdit();
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


    areaOfYardLabel = new QLabel("Area Of Yard");
    areaOfParkingLabel = new QLabel("Area Of Parking");
    buildingSpaceLabel = new QLabel("Building Space");
    totalSpaceLabel = new QLabel("Total Space");
    pricePerMeterLabel = new QLabel("Price per Meter");
    numberOfRoomsLabel = new QLabel("Number of Rooms");
    addressLabel = new QLabel("Address");
    IDLabel = new QLabel("ID");
    modeLabel = new QLabel("Mode");




    addButton = new QPushButton("Apply");
    ClearButton = new QPushButton("Clear");
    modeButton = new QPushButton("Ok");
    applyIDButton = new QPushButton("Find ID");



    //connect
    connect(addButton, SIGNAL(clicked(bool)), this, SLOT(addButtonClicked()));
    connect(ClearButton, SIGNAL(clicked(bool)), this, SLOT(clearButtonClicked()));

    connect(modeButton, SIGNAL(clicked(bool)), this, SLOT(modeButtonClicked()));
    connect(applyIDButton, SIGNAL(clicked(bool)), this, SLOT(applyIDButtonClicked()));



    //Layouts
    QHBoxLayout * IDBox = new QHBoxLayout();
    QHBoxLayout * modeBox = new QHBoxLayout();

    QVBoxLayout * rightBox = new QVBoxLayout();
    QVBoxLayout * leftBox = new QVBoxLayout();
    QHBoxLayout * buttonsBox = new QHBoxLayout();
    QHBoxLayout * mainLayout = new QHBoxLayout();
    QVBoxLayout * page = new QVBoxLayout();

    IDBox->addWidget(IDLineEdit);
    IDBox->addWidget(applyIDButton);

    modeBox->addWidget(modeComboBox);
    modeBox->addWidget(modeButton);

    leftBox->addWidget(modeLabel);
    leftBox->addWidget(IDLabel);
    leftBox->addWidget(buildingSpaceLabel);
    leftBox->addWidget(totalSpaceLabel);
    leftBox->addWidget(pricePerMeterLabel);
    leftBox->addWidget(numberOfRoomsLabel);
    leftBox->addWidget(addressLabel);
    leftBox->addWidget(areaOfYardLabel);
    leftBox->addWidget(areaOfParkingLabel);


    rightBox->addLayout(modeBox);
    rightBox->addLayout(IDBox);
    rightBox->addWidget(buildingSpaceLineEdit);
    rightBox->addWidget(totalSpaceLineEdit);
    rightBox->addWidget(pricePerMeterLineEdit);
    rightBox->addWidget(numberOfRoomsComboBox);
    rightBox->addWidget(addressLineEdit);
    rightBox->addWidget(areaOfYardLineEdit);
    rightBox->addWidget(areaOfParkingLineEdit);


    IDLabel->hide();
    IDLineEdit->hide();
    applyIDButton->hide();


    buttonsBox->addWidget(ClearButton);
    buttonsBox->addWidget(addButton);


    mainLayout->addLayout(leftBox);
    mainLayout->addLayout(rightBox);

    page->addLayout(mainLayout);
    page->addLayout(buttonsBox);

    setLayout(page);


}

addSouthVillaDiag::~addSouthVillaDiag()
{

}

void addSouthVillaDiag::addButtonClicked()
{
    if (modeComboBox->currentIndex() == 0){
        southVilla temp;
        temp.set_address(addressLineEdit->text());
        temp.set_area_of_parking(areaOfParkingLineEdit->text().toInt());
        temp.set_area_of_yard(areaOfYardLineEdit->text().toInt());
        temp.set_building_space(buildingSpaceLineEdit->text().toInt());
        temp.set_m_username(current_user);
        temp.set_number_of_rooms(numberOfRoomsComboBox->currentIndex());
        temp.set_price_per_metr(pricePerMeterLineEdit->text().toDouble());
        temp.set_total_space(totalSpaceLineEdit->text().toInt());
        temp.cal_total_price();
        qDebug () << temp.getId();
        v_southVilla.push_back(temp);
        //qDebug () << v_northVilla[v_northVilla.size()-1].getId();
        end();
        QMessageBox * msg = new QMessageBox;
        msg->setText("Villa Added Successfuly.");
        msg->setIcon(QMessageBox::Information);
        msg->setWindowTitle("ERROR!");
        msg->exec();
    }else if(modeComboBox->currentIndex() == 1){
        QString ID = IDLineEdit->text();
        for (int i = 0; i < v_southVilla.size(); ++i){
            if (v_southVilla[i].getId() == ID){
                v_southVilla[i].set_address(addressLineEdit->text());
                v_southVilla[i].set_area_of_parking(areaOfParkingLineEdit->text().toInt());
                v_southVilla[i].set_area_of_yard(areaOfYardLineEdit->text().toInt());
                v_southVilla[i].set_building_space(buildingSpaceLineEdit->text().toInt());
                v_southVilla[i].set_m_username(current_user);
                v_southVilla[i].set_number_of_rooms(numberOfRoomsComboBox->currentIndex());
                v_southVilla[i].set_price_per_metr(pricePerMeterLineEdit->text().toDouble());
                v_southVilla[i].set_total_space(totalSpaceLineEdit->text().toInt());
                v_southVilla[i].cal_total_price();
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

void addSouthVillaDiag::clearButtonClicked()
{
    IDLineEdit->setText("");
    areaOfParkingLineEdit->setText("");
    areaOfYardLineEdit->setText("");
    pricePerMeterLineEdit->setText("");
    addressLineEdit->setText("");
    totalSpaceLineEdit->setText("");
    buildingSpaceLineEdit->setText("");
    numberOfRoomsComboBox->setCurrentIndex(0);
}

void addSouthVillaDiag::applyIDButtonClicked()
{
    QString ID = IDLineEdit->text();
    for (int i = 0; i < v_southVilla.size(); ++i){
        if (v_southVilla[i].getId() == ID){
            totalSpaceLineEdit->setText(QString::number(v_southVilla[i].get_total_space()));
            pricePerMeterLineEdit->setText(QString::number(v_southVilla[i].get_price_per_metr()));
            areaOfParkingLineEdit->setText(QString::number(v_southVilla[i].get_area_of_parking()));
            areaOfYardLineEdit->setText(QString::number(v_southVilla[i].get_area_of_yard()));
            numberOfRoomsComboBox->setCurrentIndex(v_southVilla[i].get_number_of_rooms());
            addressLineEdit->setText(v_southVilla[i].get_address());
            buildingSpaceLineEdit->setText(QString::number(v_southVilla[i].get_building_space()));
            break;
        }
    }
}



void addSouthVillaDiag::modeButtonClicked()
{
    if(modeComboBox->currentIndex() == 0){
        IDLabel->hide();
        IDLineEdit->hide();
        applyIDButton->hide();
    }else{
        IDLabel->show();
        IDLineEdit->show();
        applyIDButton->show();
    }

}
