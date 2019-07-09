#include "addsalediag.h"


addSaleDiag::addSaleDiag(QWidget *parent) :
    QDialog(parent)
{
    typeLabel = new QLabel("Type");
    IDLabel = new QLabel("ID");
    commisionLabel = new QLabel("Commision");
    paymentMethodLabel = new QLabel("Payment");

    paymentMethodComboBox = new QComboBox();
    paymentMethodComboBox->addItem("Credit");
    paymentMethodComboBox->addItem("Cash");

    typeComboBox = new QComboBox();
    typeComboBox->addItem("Apartment");
    typeComboBox->addItem("Villa");

    IDLineEdit = new QLineEdit();
    commisionLineEdit = new QLineEdit();

    addButton = new QPushButton("Add");
    clearButton = new QPushButton("Clear");

    QVBoxLayout * leftBox = new QVBoxLayout();
    QVBoxLayout * rightBox = new QVBoxLayout();
    QHBoxLayout * widgetsBox = new QHBoxLayout();
    QHBoxLayout * buttonsLayout = new QHBoxLayout();
    QVBoxLayout * mainLayout = new QVBoxLayout();

    leftBox->addWidget(typeLabel);
    leftBox->addWidget(IDLabel);
    leftBox->addWidget(commisionLabel);
    leftBox->addWidget(paymentMethodLabel);

    rightBox->addWidget(typeComboBox);
    rightBox->addWidget(IDLineEdit);
    rightBox->addWidget(commisionLineEdit);
    rightBox->addWidget(paymentMethodComboBox);

    widgetsBox->addLayout(leftBox);
    widgetsBox->addLayout(rightBox);

    buttonsLayout->addWidget(clearButton);
    buttonsLayout->addWidget(addButton);

    mainLayout->addLayout(widgetsBox);
    mainLayout->addLayout(buttonsLayout);


    setLayout(mainLayout);


}

addSaleDiag::~addSaleDiag()
{

}

void addSaleDiag::addButtonClicked()
{

}

void addSaleDiag::clearButtonClicked()
{

}
