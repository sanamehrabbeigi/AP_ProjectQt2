#ifndef SHOWPICTURE_H
#define SHOWPICTURE_H

#include <QDialog>
#include <QPixmap>
#include <QLabel>
#include <QHBoxLayout>



class showPicture : public QDialog
{
    Q_OBJECT

public:
    explicit showPicture(QString path,QWidget *parent = 0);
    ~showPicture();

private:

};

#endif // SHOWPICTURE_H
