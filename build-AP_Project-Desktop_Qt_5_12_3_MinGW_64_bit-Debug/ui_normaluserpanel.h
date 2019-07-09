/********************************************************************************
** Form generated from reading UI file 'normaluserpanel.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NORMALUSERPANEL_H
#define UI_NORMALUSERPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_normaluserpanel
{
public:

    void setupUi(QWidget *normaluserpanel)
    {
        if (normaluserpanel->objectName().isEmpty())
            normaluserpanel->setObjectName(QString::fromUtf8("normaluserpanel"));
        normaluserpanel->resize(400, 300);

        retranslateUi(normaluserpanel);

        QMetaObject::connectSlotsByName(normaluserpanel);
    } // setupUi

    void retranslateUi(QWidget *normaluserpanel)
    {
        normaluserpanel->setWindowTitle(QApplication::translate("normaluserpanel", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class normaluserpanel: public Ui_normaluserpanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NORMALUSERPANEL_H
