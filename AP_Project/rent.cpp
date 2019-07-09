#include "rent.h"

#define FIXED 2000

//rent
rent::rent()
{
	// cout << "counstructor is called!\n";
	commission = FIXED;
	type = 0;
	mortgage = 0;
	corent = 0;
	final_price = 0;
	dorent = 0;
	id = "0";
}
rent::~rent()
{
	// cout << "distructor is called!\n";
}

//setter:
void rent::set_type(bool b)
{
	type = b;
}
void rent::set_commission(double a)
{
	commission = a;
}
void rent::set_mortgage(double a)
{
    mortgage = a;
}
void rent::set_corent(double a)
{
    corent = a;
}
void rent::set_final_price(double a)
{
    final_price = a;
}
void rent::set_dorent(long long a)
{
	dorent = a;
}
void rent::set_id(QString s)
{
	id = s;
}

//getter:
bool rent::get_type()
{
	return type;
}
double rent::get_commission()
{
	return commission;
}
double rent::get_mortgage()
{
	return mortgage;
}
double rent::get_corent()
{
	return corent;
}
double rent::get_final_price()
{
	return final_price;
}
long long rent::get_dorent()
{
	return dorent;
}
QString rent::get_id()
{
    return id;
}

void rent::cal_mortgage(double a)
{
    mortgage = (a * 5) / 100;
}

void rent::cal_corent(double a)
{
    corent = (a / 100);
}

void rent::cal_final_price()
{
    final_price = (corent * dorent) + mortgage + (commission * mortgage);
}
