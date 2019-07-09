#pragma once

#include <iostream>

#include <QString>
#include <QVector>

using namespace std;

class villa
{
protected:
	int building_space;
    int total_space;
	double price_per_metr;
	int number_of_rooms;
    QString address, id, m_username, nu_username;
    int state; // 0 ya  1->rent ya 2->sale 3gone
    bool isInList;
public:
	villa();
	~villa();
	//setter:
	void set_building_space(int b);
	void set_total_space(int t);
	void set_price_per_metr(double p);
	void set_number_of_rooms(int n);
	void set_address(QString a);
	void set_state(int s);
	void setId(QString s);
    void set_m_username(QString s);
    void set_nu_username(QString s);
    void setIsInList(bool b);

	//getter:
	int get_building_space();
	int get_total_space();
	double get_price_per_metr();
	int get_number_of_rooms();
	QString get_address();
	int get_state();
	QString getId();
    QString get_m_username();
    QString get_nu_username();
    bool getIsInList();

	virtual double cal_total_price() = 0;
};

class northVilla : public villa
{
private:
	int area_of_front_yard;
	int area_of_back_yard;
	double total_price;
    static int n_count;
public:
	northVilla();
	~northVilla();
	void set_area_of_front_yard(int af);
	int get_area_of_front_yard();
	void set_area_of_back_yard(int ab);
	int get_area_of_back_yard();
	void set_total_price(double tp);
	double get_total_price();

	double cal_total_price();
};

class southVilla :public villa 
{
private:
	int area_of_yard;
	int area_of_parking;
	double total_price;
    static int s_count;

public:
	southVilla();
	~southVilla();
	void set_area_of_yard(int ay);
	int get_area_of_yard();
	void set_area_of_parking(int ap);
	int get_area_of_parking();
	void set_total_price(double tp);
	double get_total_price();

	double cal_total_price();
};
