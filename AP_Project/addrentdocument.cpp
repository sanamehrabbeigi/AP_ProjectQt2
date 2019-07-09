#include "addrentdocument.h"


addRentDocument::addRentDocument(QWidget *parent) :
    QDialog(parent)
{
    typeComboBox = new QComboBox;
    IDLabel = new QLabel("ID");
    typeLabel = new QLabel("Type");
    commisionLabel = new QLabel("Commision");
    durationOfRentLabel = new QLabel("Duration Of Rent");
    clearButton = new QPushButton("Clear");
    addButton = new QPushButton("Add");

    IDLineEdit = new QLineEdit();
    commisionLineEdit = new QLineEdit();
    durationOfRentLineEdit = new QLineEdit();

    typeComboBox->addItem("Villa");
    typeComboBox->addItem("Apartment");

    QVBoxLayout * rightBox = new QVBoxLayout();
    QVBoxLayout * leftBox = new QVBoxLayout();
    QHBoxLayout * widgetsBox = new QHBoxLayout();
    QHBoxLayout * ButtonsBox = new QHBoxLayout();
    QVBoxLayout * mainLayout = new QVBoxLayout();


    connect(addButton, SIGNAL(clicked(bool)), this, SLOT(addButtonClicked()));
    connect(clearButton, SIGNAL(clicked(bool)), this, SLOT(clearButtonClicked()));


    leftBox->addWidget(typeLabel);
    leftBox->addWidget(IDLabel);
    leftBox->addWidget(commisionLabel);
    leftBox->addWidget(durationOfRentLabel);

    rightBox->addWidget(typeComboBox);
    rightBox->addWidget(IDLineEdit);
    rightBox->addWidget(commisionLineEdit);
    rightBox->addWidget(durationOfRentLineEdit);

    widgetsBox->addLayout(leftBox);
    widgetsBox->addLayout(rightBox);

    ButtonsBox->addWidget(clearButton);
    ButtonsBox->addWidget(addButton);

    mainLayout->addLayout(widgetsBox);
    mainLayout->addLayout(ButtonsBox);

    setLayout(mainLayout);
}

addRentDocument::~addRentDocument()
{

}

void addRentDocument::clearButtonClicked()
{
    typeComboBox ->setCurrentIndex(0);
    IDLineEdit -> setText("");
    commisionLineEdit -> setText("");
    durationOfRentLineEdit -> setText("");
}

void addRentDocument::addButtonClicked()
{
    rent r;
    r.set_id(IDLineEdit -> text());
    QString id = IDLineEdit -> text();
    r.set_type(typeComboBox -> currentIndex());
    r.set_commission(commisionLineEdit ->text().toDouble());
    r.set_dorent(durationOfRentLineEdit -> text().toInt());
    if (id[0] == '0' && id[1] == '0')
    {
        QMessageBox * msg = new QMessageBox;
        msg->setText("You can't choose apartment!");
        msg->setIcon(QMessageBox::Information);
        msg->setWindowTitle("ERROR!");
        msg->exec();
    }
    else if( id[0] == '0' && id[1] == '1')
    {
        for(int i=0; i< v_apartment.size();i++)
        {
            for(int j=0; j< v_apartment[i].get_v_house_for_apartment().size();j++)
            {
                house h =  v_apartment[i].get_v_house_for_apartment()[j];
                if ( h.getId() == id && h.get_state() == 0)
                {
                    h.set_state(1);
                    r.cal_mortgage(h.getTotalPriceOfHouse());
                    r.cal_corent(h.getTotalPriceOfHouse());
                    r.cal_final_price();
                }

            }
        }
    }
    else if( id[1] == '0' && id[1] == '1')
    {

    }
    else if( id[1] == '0' && id[1] == '1')
    {

    }
    else
    {
        QMessageBox * msg = new QMessageBox;
        msg->setText("Not Valid!");
        msg->setIcon(QMessageBox::Information);
        msg->setWindowTitle("ERROR!");
        msg->exec();
    }

}
