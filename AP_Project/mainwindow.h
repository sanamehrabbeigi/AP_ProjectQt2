#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QDebug>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>


class MainWindow : public QMainWindow
{
    Q_OBJECT
    QWidget * central;
    QPushButton * btn_login;
    QPushButton * btn_signup;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void login_pressed();
    void signup_pressed();

private:

};

#endif // MAINWINDOW_H
