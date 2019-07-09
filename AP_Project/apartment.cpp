#include "apartment.h"

//apartment
apartment::apartment()
{
	// cout << "constructor is called!\n";
    id = "00" + QString::number(a_count);
    m_username = "-1";
    a_count++;
}
apartment::~apartment()
{
	// cout << "distructor is called!\n";
}

//setter
void apartment::setTotalSpace(int s)
{
	total_space = s;
}
void apartment::setPricePerMetr(double p)
{
	price_per_metr = p;
}
void apartment::setNumberOfFloors(int n)
{
	number_of_floors = n;
}
void apartment::setElevator(bool e)
{
	elevator = e;
}
void apartment::setAddress(QString a)
{
	address = a;
}
void apartment::setTotalPrice(double tp)
{
	total_price = tp;
}
void apartment::set_v_house_for_apartment(QVector<house> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		double d_base = price_per_metr * v[i].getBuildingSpace();
		double d = d_base;
		d += d_base*0.05*v[i].getFloorNumber();
		d += d_base*0.08*v[i].getNumberOfRooms();
		if (v[i].getUse() == 1)
			d += d_base * 0.3;
		else if (v[i].getUse() == 2)
			d += d_base * 0.5;
		if (elevator == 1)
			d += d_base*0.02;
		v[i].setTotalPriceOfHouse(d);
	}
	v_house_for_apartment = v;
}
void apartment::setId(QString s)
{
	id = s;
}
void apartment::set_m_username(QString s)
{
    m_username = s;
}

void apartment::setPicAd(QString address)
{
    pic_ad = address;
}

//getter
int apartment::getTotalSpace()
{
	return total_space;
}
double apartment::getPricePerMetr()
{
	return price_per_metr;
}
int apartment::getNumberOfFloors()
{
	return number_of_floors;
}
bool apartment::getElevator()
{
	return elevator;
}
QString apartment::getAddress()
{
	return address;
}
double apartment::getTotalPrice()
{
	return total_price;
}
QVector<house> apartment::get_v_house_for_apartment()
{
	return v_house_for_apartment;
}
QString apartment::getId()
{
	return id;
}
QString apartment::get_m_username()
{
    return m_username;
}

QString apartment::getPicAd()
{
    return pic_ad;
}

double apartment::calTotalPrice()
{
	total_price = total_space*price_per_metr*0.8;
	return total_price;
}

int apartment::a_count = 0;
