#include "sale.h"

#define FIXED 2000

//sale
sale::sale()
{
	// cout << "counstructor is called!\n";
	commission = FIXED;
	type = 0;
	payment = 0;
	final_price = 0;
	id = "0";
}
sale::~sale()
{
	// cout << "distructor is called!\n";
}
//setter:
void sale::set_type(bool b)
{
	type = b;
}
void sale::set_payment(bool b)
{
	payment = b;
}
void sale::set_commission(double a)
{
	commission = a;
}
void sale::set_final_price(double a)
{
    final_price = a;
}
void sale::set_id(QString s)
{
	id = s;
}
//getter:
bool sale::get_type()
{
	return type;
}
bool sale::get_payment()
{
	return payment;
}
double sale::get_commission()
{
	return commission;
}
double sale::get_final_price()
{
	return final_price;
}
QString sale::get_id()
{
    return id;
}

void sale::cal_final_price(double a)
{
    final_price = a + (a * commission);
}
