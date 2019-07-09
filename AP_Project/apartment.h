#pragma once

#include <QString>
#include <QVector>

#include "house.h"

using namespace std;

class apartment
{
private:
    int total_space, number_of_floors;
	double total_price, price_per_metr;
	bool elevator; // 1 or 0
    QString address, id , m_username;
	QVector <house> v_house_for_apartment;
    static int a_count;
    QString pic_ad;

public:
	apartment();
	~apartment();
	//setter
	void setTotalSpace(int s);
	void setPricePerMetr(double p);
	void setNumberOfFloors(int n);
	void setElevator(bool e);
	void setAddress(QString a);
	void setTotalPrice(double tp);
	void set_v_house_for_apartment(QVector<house> v);
	void setId(QString s);
    void set_m_username(QString s);
    void setPicAd(QString address);

    //getter
	int getTotalSpace();
	double getPricePerMetr();
	int getNumberOfFloors();
	bool getElevator();
	QString getAddress();
	double getTotalPrice();
	QVector<house> get_v_house_for_apartment();
	QString getId();
    QString get_m_username();
    QString getPicAd();

	double calTotalPrice();
};

