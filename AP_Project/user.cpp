#include "user.h"

 //user
user::user()
{
	// cout << "constructor is called!\n";
	time_in.hour = 0;
	time_in.minute = 0;
	time_in.second = 0;
	time_out.hour = 0;
	time_in.minute = 0;
	time_in.second = 0;
    state = 1;
    type = 1;

}
user::~user()
{
	// cout << "distructor is called!\n";
}
//setter:
void user::set_birthday(date d)
{
	birthday = d;
}
void user::set_family(QString s)
{
	family = s;
}
void user::set_name(QString s)
{
	name = s;
}
void user::set_password(QString s)
{
	password = s;
}
void user::set_state(bool b)
{
	state = b;
}
void user::set_time_in(Time t)
{
	time_in = t;
}
void user::set_time_out(Time t)
{
	time_out = t;
}
void user::set_username(QString s)
{
	username = s;
}
void user::set_cash(double a)
{
	cash = a;
}
void user::set_type(bool b)
{
    type = b;
}

//getter:
date user::get_birthday()
{
	return birthday;
}
QString user::get_family()
{
	return family;
}
QString user::get_name()
{
	return name;
}
QString user::get_password()
{
	return password;
}
bool user::get_state()
{
	return state;
}
Time user::get_time_in()
{
	return time_in;
}
Time user::get_time_out()
{
	return time_out;
}
QString user::get_username()
{
	return username;
}
double user::get_cash()
{
	return cash;
}
bool user::get_type()
{
    return type;
}
/*
//normal user
normal_user::normal_user()
{
	// cout << "constructor is called!\n";
}
normal_user::~normal_user()
{
	// cout << "distructor is called!\n";
}
//setter:
void normal_user::set_v_rent_for_normal_user(QVector<rent> v)
{
	v_rent_for_normal_user = v;
}
void normal_user::set_v_sale_for_normal_user(QVector<sale> v)
{
	v_sale_for_normal_user = v;
}
//getter:
QVector<rent> normal_user::get_v_rent_for_normal_user()
{
	return v_rent_for_normal_user;
}
QVector<sale> normal_user::get_v_sale_for_normal_user()
{
	return v_sale_for_normal_user;
}

//manager
manager::manager()
{
	// cout << "constructor is called!\n";
}
manager::~manager()
{
	// cout << "distructor is called!\n";
}
//setter:
void manager::set_v_rent_for_manager(QVector<rent> v)
{
	v_rent_for_manager = v;
}
void manager::set_v_sale_for_manager(QVector<sale> v)
{
	v_sale_for_manager = v;
}
void manager::set_v_northVilla_for_manager(QVector<northVilla> v)
{
	v_northVilla_for_manager = v;
}
void manager::set_v_southVilla_for_manager(QVector<southVilla> v)
{
	v_southVilla_for_manager = v;
}
void manager::set_v_apartment_for_manager(QVector<apartment> v)
{
	v_apartment_for_manager = v;
}
//getter:
QVector<rent> manager::get_v_rent_for_manager()
{
	return v_rent_for_manager;
}
QVector<sale> manager::get_v_sale_for_manager()
{
	return v_sale_for_manager;
}
QVector<northVilla> manager::get_v_northVilla_for_manager()
{
	return v_northVilla_for_manager;
}
QVector<southVilla> manager::get_v_southVilla_for_manager()
{
	return v_southVilla_for_manager;
}
QVector <apartment> manager::get_v_apartment_for_manager()
{
	return v_apartment_for_manager;
}
*/
