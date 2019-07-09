#ifndef ADDPICTURE_H
#define ADDPICTURE_H

#include <QDialog>
#include <QPixmap>
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>

#include "global.h"
#include "showpicture.h"

class addPicture : public QDialog
{
    Q_OBJECT

public:
    explicit addPicture(QString ID,QWidget *parent = 0);
    ~addPicture();

private slots:
    void addButtonClicked();
private:

    QString apartmentID;
    QString path;
    QLabel * pathLabel;
    QLineEdit * pathLineEdit;
    QPushButton * addButton;
};

#endif // ADDPICTURE_H
