#include "signupdialog.h"
//#include "ui_signupdialog.h"
#include "mainwindow.h"

SignupDialog::SignupDialog(QWidget *parent) :
    QDialog(parent)
{
    //Objects
    name = new QLineEdit();
    family =new QLineEdit();
    birthdate=new QLineEdit();
    username=new QLineEdit();
    password=new QLineEdit();
    cash=new QLineEdit();
    l_name=new QLabel();
    l_family=new QLabel();
    l_birthdate=new QLabel();
    l_username=new QLabel();
    l_password=new QLabel();
    l_cash=new QLabel();
    l_user = new QLabel("type of user :");
    com_user = new QComboBox();
    btn_cancel = new QPushButton("Cancel");
    btn_register = new QPushButton("Register");

    //layouts
    QVBoxLayout * L1=new QVBoxLayout();
    L1->addWidget(name);
    L1->addWidget(family);
    L1->addWidget(birthdate);
    L1->addWidget(username);
    L1->addWidget(password);
    L1->addWidget(cash);
    L1->addWidget(com_user);
    L1->addWidget(btn_cancel);
    QVBoxLayout * L2=new QVBoxLayout();
    L2->addWidget(l_name);
    L2->addWidget(l_family);
    L2->addWidget(l_birthdate);
    L2->addWidget(l_username);
    L2->addWidget(l_password);
    L2->addWidget(l_cash);
    L2->addWidget(l_user);
    L2->addWidget(btn_register);
    QHBoxLayout * L3=new QHBoxLayout();
    L3->addLayout(L2);
    L3->addLayout(L1);
    setLayout(L3);

    //signals
    connect(btn_register,SIGNAL(clicked()),this,SLOT(register_pressed()));
    connect(btn_cancel,SIGNAL(clicked()),this,SLOT(cancel_pressed()));

    l_name->setText("Name: ");
    l_family->setText("Family: ");
    l_birthdate->setText("Birthday: (2000/03/28) ");
    l_username->setText("Username: ");
    l_password->setText("Password: ");
    l_cash->setText("Cash: ");
    com_user ->addItem("manager");
    com_user ->addItem("normal user");
}

SignupDialog::~SignupDialog()
{
    //delete ui;
}

void SignupDialog::register_pressed()
{
    bool b = 0;
    for(int i=0; i< v_user.size();i++)
    {
        if ( v_user[i].get_username() == username->text() )
        {
            QMessageBox * msg = new QMessageBox;
            msg->setText("Try another username!");
            msg->setIcon(QMessageBox::Information);
            msg->setWindowTitle("ERROR!");
            msg->exec();
            b = 1;
        }
    }
    if ( b == 0 && username->text() != ""  && name->text() != "" && family->text() != "" && password->text() != "" && birthdate->text() != "")
    {
        user u_temp;
        u_temp.set_cash(cash->text().toInt());
        u_temp.set_name(name->text());
        if (com_user->currentText() == "manager")
            u_temp.set_type(0);
        else
            u_temp.set_type(1);
        u_temp.set_state(1);
        u_temp.set_family(family->text());
        date t_birthday;
        QString s1 =  birthdate->text() , s2 = "";
        s2 += s1[0];
        s2 += s1[1];
        s2 += s1[2];
        s2 += s1[3];
        qDebug() << s2 << endl;
        t_birthday.year = (s2.toInt());
        s2 = "";
        s2 += s1[5];
        s2 += s1[6];
        t_birthday.month = (s2.toInt());
        s2 = "";
        s2 += s1[8];
        s2 += s1[9];
        t_birthday.day = (s2.toInt());
        u_temp.set_birthday(t_birthday);
        QByteArray qb=QCryptographicHash::hash(password->text().toUtf8(),QCryptographicHash::Md5);
        QString pass = QTextCodec::codecForMib(106)->toUnicode(qb);
        u_temp.set_password(pass);
        u_temp.set_username(username->text());
        v_user.push_back(u_temp);
        QMessageBox * msg = new QMessageBox;
        msg->setText("Successfully registered!");
        msg->setIcon(QMessageBox::Information);
        msg->setWindowTitle(";)");
        msg->exec();
        this ->close();
    }
}

void SignupDialog::cancel_pressed()
{
    this -> close();
}
