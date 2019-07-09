#include "showpicture.h"


showPicture::showPicture(QString path,QWidget *parent) :
    QDialog(parent)
{
    resize(400, 400);
    QLabel * picLabel = new QLabel();
    QPixmap pix(path);
    picLabel->setPixmap(pix.scaled(400, 400, Qt::KeepAspectRatio));

    QHBoxLayout * hBox = new QHBoxLayout();
    hBox->addWidget(picLabel);

    setLayout(hBox);
}

showPicture::~showPicture()
{

}
