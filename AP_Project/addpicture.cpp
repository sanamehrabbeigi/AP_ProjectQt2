#include "addpicture.h"


addPicture::addPicture(QString ID, QWidget *parent) :
    QDialog(parent)
{
    apartmentID = ID;

    pathLineEdit = new QLineEdit();
    pathLabel = new QLabel("Path");
    addButton = new QPushButton("Add");

    QHBoxLayout * hBox = new QHBoxLayout();

    connect( addButton, SIGNAL(clicked(bool)), this, SLOT(addButtonClicked()) );

    hBox->addWidget(pathLabel);
    hBox->addWidget(pathLineEdit);
    hBox->addWidget(addButton);

    setLayout(hBox);
}

addPicture::~addPicture()
{

}

void addPicture::addButtonClicked()
{
    //set pic for apart ID
    for (int i = 0; i < v_apartment.size(); ++i){
        if (apartmentID == v_apartment[i].getId()){
            path = pathLineEdit->text();
            v_apartment[i].setPicAd(path);
        }
    }
    showPicture * showPage = new showPicture(pathLineEdit->text());
    close();
    showPage->exec();

}
