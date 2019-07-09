#ifndef SHOWMANAGERDIAG_H
#define SHOWMANAGERDIAG_H




#include "global.h"
#include "showpicture.h"


class showManagerDiag : public QWidget
{
    Q_OBJECT
    QPushButton * btn_1;
    QPushButton * btn_2;
    QPushButton * btn_3;
    QPushButton * btn_4;
    QPushButton * btn_5;
    QPushButton * btn_6;
    QPushButton * btn_7;
    QVBoxLayout * L1;
    QVBoxLayout * L2;
    QVBoxLayout * L3;
    QVBoxLayout * L4;
    QHBoxLayout * L5;
    QHBoxLayout * L6;
    QHBoxLayout * L7;
    QLabel * la_result;
    QListWidget * li_result;
    QPushButton * btn_exit;
    QLabel * la_input;
    QLineEdit * input1;
    QLineEdit * input2;
    QPushButton * btn_showPicture;

    QString id;
    QPushButton * selectIDButton;
    QLineEdit * IDLineEdit;


public:
    explicit showManagerDiag(QWidget *parent = nullptr);
    ~showManagerDiag();

private:

public slots:
    void selectIDPressed();


    void btn_1_pressed();
    void btn_2_pressed();
    void btn_3_pressed();
    void btn_4_pressed();
    void btn_5_pressed();
    void btn_6_pressed();
    void btn_7_pressed();
    void btn_exit_pressed();
    void btn_showPicture_pressed();

};

#endif // SHOWMANAGERDIAG_H
