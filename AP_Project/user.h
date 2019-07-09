#pragma once

#include <QString>

using namespace std;

typedef struct date
{
	int day, month, year;
}date;

typedef struct Time
{
	int hour, minute, second;
}Time;

class user
{
protected:
    bool state, type;// 0 for fired 1 for active  0->manager  1->normal user
	QString name, family, username, password;
    date birthday;
	Time time_in, time_out;
    double cash;
public:
	user();
	~user();
	//setter:
	void set_state(bool b);
	void set_name(QString s);
	void set_family(QString s);
	void set_username(QString s);
	void set_password(QString s);
	void set_birthday(date d);
	void set_time_in(Time t);
	void set_time_out(Time t);
    void set_cash(double a);
    void set_type(bool b);
	//getter:
	bool get_state();
	QString get_name();
	QString get_family();
	QString get_username();
	QString get_password();
    date get_birthday();
	Time get_time_in();
	Time get_time_out();
    double get_cash();
    bool get_type();
};

/*
class normal_user : public user
{
private:
	QVector <rent> v_rent_for_normal_user;
	QVector <sale> v_sale_for_normal_user;
public:
	normal_user();
	~normal_user();
	//setter:
	void set_v_rent_for_normal_user(QVector<rent> v);
	void set_v_sale_for_normal_user(QVector<sale> v);
	//getter:
	QVector<rent> get_v_rent_for_normal_user();
	QVector<sale> get_v_sale_for_normal_user();
};

class manager : public user
{
private:
	QVector <rent> v_rent_for_manager;
	QVector <sale> v_sale_for_manager;
	QVector <northVilla> v_northVilla_for_manager;
	QVector <southVilla> v_southVilla_for_manager;
	QVector <apartment> v_apartment_for_manager;
public:
	manager();
	~manager();
	//setter:
	void set_v_rent_for_manager(QVector<rent> v);
	void set_v_sale_for_manager(QVector<sale> v);
	void set_v_northVilla_for_manager(QVector<northVilla> v);
	void set_v_southVilla_for_manager(QVector<southVilla> v);
	void set_v_apartment_for_manager(QVector<apartment> v);
	//getter:
	QVector<rent> get_v_rent_for_manager();
	QVector<sale> get_v_sale_for_manager();
	QVector<northVilla> get_v_northVilla_for_manager();
	QVector<southVilla> get_v_southVilla_for_manager();
	QVector<apartment> get_v_apartment_for_manager();
};
*/
