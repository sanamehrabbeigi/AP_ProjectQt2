#include "mainwindow.h"
#include "logindialog.h"
#include "signupdialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent){

    //QObjects
    setWindowTitle("Welcome!");
    central= new QWidget();
    btn_login= new QPushButton();
    btn_signup= new QPushButton();


    //Signals
    connect(btn_login,SIGNAL(clicked()),this,SLOT(login_pressed()));
    connect(btn_signup,SIGNAL(clicked()),this,SLOT(signup_pressed()));


    //layouts
    QHBoxLayout * Layout_L1 = new QHBoxLayout();

    Layout_L1->addWidget(btn_login);
    Layout_L1->addWidget(btn_signup);
    btn_login->setText("Log in");
    btn_signup->setText("Sign up");

    central->setLayout(Layout_L1);
    setCentralWidget(central);
}

void MainWindow::login_pressed()
{
    LoginDialog * new_dialog=new LoginDialog();


     new_dialog->show();

   // emit send_data(username->text());
}
void MainWindow::signup_pressed()
{
    SignupDialog * new_dialog = new SignupDialog();
    new_dialog->show();

}


MainWindow::~MainWindow()
{

}


