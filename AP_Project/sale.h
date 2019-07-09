#pragma once

#include<QString>

using namespace std;

class sale
{
private:
	bool type, payment; // 0 for villa 1 for apartmet 0 for cash 1 for credit
	double commission, final_price;
	QString id;
public:
	sale();
	~sale();
	//setter:
	void set_type(bool b);
	void set_payment(bool b);
	void set_commission(double a);
	void set_final_price(double a);
	void set_id(QString s);
	//getter:
	bool get_type();
	bool get_payment();
	double get_commission();
	double get_final_price();
	QString get_id();

    void cal_final_price(double a);
};
