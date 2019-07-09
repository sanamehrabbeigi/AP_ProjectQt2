#include "logindialog.h"
#include "mainwindow.h"
#include "normaluserpanel.h"
#include "managerpanel.h"

//#include "ui_logindialog.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent)
{
    //Objects
    username=new QLineEdit();
    password=new QLineEdit();
    user_label=new QLabel("Username: ");
    pass_label=new QLabel("Password: ");
    btn_ok = new QPushButton("Ok");
    btn_cancel = new QPushButton("Cancel");

    //Layouts
    L1 = new QHBoxLayout();
    L1->addWidget(user_label);
    L1->addWidget(username);
    L2 = new QHBoxLayout();
    L2->addWidget(pass_label);
    L2->addWidget(password);
    L3 = new QHBoxLayout();
    L3->addWidget(btn_ok);
    L3->addWidget(btn_cancel);
    L4 = new QVBoxLayout();
    L4->addLayout(L1);
    L4->addLayout(L2);
    L4->addLayout(L3);

    setLayout(L4);

    // SIGNALS
    connect(btn_ok,SIGNAL(clicked()),this,SLOT(ok_pressed()));
    connect(btn_cancel,SIGNAL(clicked()),this,SLOT(cancel_pressed()));

}

LoginDialog::~LoginDialog()
{
    //delete ui;
}

void LoginDialog::ok_pressed()
{
    bool b =0;
    QByteArray qb=QCryptographicHash::hash(password->text().toUtf8(),QCryptographicHash::Md5);
    QString pass = QTextCodec::codecForMib(106)->toUnicode(qb);
    for(int i=0; i< v_user.size();i++)
    {
        qDebug() <<i <<"  "<< v_user[i].get_username() <<"  "<< v_user[i].get_password() << endl;
        qDebug() << username->text() <<"  "<< pass << endl;
        if( v_user[i].get_username() == username->text() && v_user[i].get_password() == pass &&  v_user[i].get_state() == 1)
        {
            index_of_current_user = i;
            current_user = v_user[i].get_username();
            i = v_user.size();
            b = 1;
        }
    }
    if ( b == 0)
    {
        QMessageBox * msg = new QMessageBox;
        msg->setText("Not valid!");
        msg->setIcon(QMessageBox::Information);
        msg->setWindowTitle("ERROR!");
        msg->exec();
    }
    else
    {
        QTime time = QTime ::currentTime();
        Time mytime;
        mytime.hour = time.hour();
        mytime.minute = time.minute();
        mytime.second = time.second();
        v_user[index_of_current_user].set_time_in(mytime);
        if ( v_user[index_of_current_user].get_type() == 0)
        {
            this->close();
            managerPanel * managePage = new managerPanel;
            managePage->exec();
        }
        else
        {
            this -> close();
            normaluserpanel * new_Widget = new normaluserpanel();
            new_Widget -> show();
        }
    }
}

void LoginDialog::cancel_pressed()
{
    this->close();
}
