#pragma once

#include<QString>

using namespace std;

class rent
{
private:
	bool type; // 0 for villa 1 for apartment
	double commission, mortgage, corent, final_price;
	long long dorent;
    QString id;
public:
	rent();
	~rent();
	//setter :
	void set_type(bool b);
	void set_commission(double a);
	void set_mortgage(double);
	void set_corent(double a);
    void set_final_price(double a);
	void set_dorent(long long a);
	void set_id(QString s);
	//getter :
	bool get_type();
	double get_commission();
	double get_mortgage();
	double get_corent();
	double get_final_price();
	long long get_dorent();
	QString get_id();

    void cal_mortgage(double a);
    void cal_corent(double a);
    void cal_final_price();
};
