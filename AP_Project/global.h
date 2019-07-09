#ifndef GLOBAL_H
#define GLOBAL_H

#include <QtGlobal>

#include <QDialog>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QDebug>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>
#include <QString>
#include <QVector>
#include <QListWidget>
#include <QComboBox>
#include <QMessageBox>
#include <QTabWidget>
#include <QByteArray>
#include <QCryptographicHash>
#include <QTextCodec>
#include <QTime>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QFile>

#include "rent.h"
#include "sale.h"
#include "user.h"
#include "apartment.h"
#include "villa.h"

QT_BEGIN_NAMESPACE
class QString;
QT_END_NAMESPACE

#define MAGIC_NUM 42

extern QVector <apartment> v_apartment;
extern QVector <northVilla> v_northVilla;
extern QVector <southVilla> v_southVilla;
extern QVector <user> v_user;
extern QVector <rent> v_rent;
extern QVector <sale> v_sale;


extern QString  current_user;
extern int index_of_current_user;

#endif // GLOBAL_H
