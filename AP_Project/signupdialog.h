#ifndef SIGNUPDIALOG_H
#define SIGNUPDIALOG_H

#include "global.h"

class SignupDialog : public QDialog
{
    Q_OBJECT
    QLineEdit * name;
    QLineEdit * family;
    QLineEdit * birthdate;
    QLineEdit * username;
    QLineEdit * password;
    QLineEdit * cash;
    QLabel * l_name;
    QLabel * l_family;
    QLabel * l_birthdate;
    QLabel * l_username;
    QLabel * l_password;
    QLabel * l_cash;
    QLabel * l_user;
    QPushButton * btn_cancel;
    QPushButton * btn_register;
    QComboBox * com_user;

public:

    explicit SignupDialog(QWidget *parent = nullptr);
    ~SignupDialog();

private:
   // Ui::SignupDialog *ui;

public slots:
   void register_pressed();
   void cancel_pressed();

};

#endif // SIGNUPDIALOG_H
