#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include "global.h"

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT
    QLineEdit * username;
    QLineEdit * password;
    QLabel * user_label;
    QLabel * pass_label;
    QPushButton * btn_cancel;
    QPushButton * btn_ok;
    QHBoxLayout * L1;
    QHBoxLayout * L2;
    QHBoxLayout * L3;
    QVBoxLayout * L4;

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

private:
  //  Ui::LoginDialog *ui;

public slots:
   void ok_pressed();
   void cancel_pressed();

};

#endif // LOGINDIALOG_H
