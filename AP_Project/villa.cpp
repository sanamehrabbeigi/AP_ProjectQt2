#include "villa.h"

//villa
villa::villa()
{
	// cout << "constructor is called!\n";
	state = 0;
	total_space = 0;
	building_space = 0;
    m_username = "-1";
    nu_username = "-1";
    isInList = 0;
}
villa::~villa()
{
	// cout << "distructor is called!\n";
}
void villa::set_building_space(int b)
{
	building_space = b;
}
int villa::get_building_space()
{
	return building_space;
}
void villa::set_total_space(int t)
{
	total_space = t;
}
int villa::get_total_space()
{
	return total_space;
}
void villa::set_price_per_metr(double p)
{
	price_per_metr = p;
}
double villa::get_price_per_metr()
{
	return price_per_metr;
}
void villa::set_number_of_rooms(int n)
{
	number_of_rooms = n;
}
int villa::get_number_of_rooms()
{
	return number_of_rooms;
}
void villa::set_address(QString a)
{
	address = a;
}
QString villa::get_address()
{
	return address;
}
int villa::get_state()
{
	return state;
}
void villa::set_state(int s)
{
	state = s;
}
void villa::setId(QString s)
{
	id = s;
}
QString villa::getId()
{
	return id;
}
void villa::set_m_username(QString s)
{
    m_username = s;
}
QString villa::get_m_username()
{
    return m_username;
}
void villa::set_nu_username(QString s)
{
    nu_username = s;
}

void villa::setIsInList(bool b)
{
    isInList = b;
}
QString villa ::get_nu_username()
{
    return nu_username;
}

bool villa::getIsInList()
{
    return isInList;
}

//northVilla
northVilla::northVilla()
{
	// cout << "constructor is called!\n";
    id = "10"+ QString::number(n_count);
    n_count++;
}
northVilla::~northVilla()
{
	// cout << "distructor is called!\n";
}
void northVilla::set_area_of_front_yard(int af)
{
	area_of_front_yard = af;
}
int northVilla::get_area_of_front_yard()
{
	return area_of_front_yard;
}
void northVilla::set_area_of_back_yard(int ab)
{
	area_of_back_yard = ab;
}
int northVilla::get_area_of_back_yard()
{
	return area_of_back_yard;
}
void northVilla::set_total_price(double tp)
{
	total_price = tp;
}
double northVilla::get_total_price()
{
	return total_price;
}
double northVilla::cal_total_price()
{
	total_price = price_per_metr*((building_space)+(area_of_back_yard*0.15) + (area_of_front_yard*0.3));
	return total_price;
}

//southVilla
southVilla::southVilla()
{
	// cout << "constructor is called!\n";
    id = "11"+ QString::number(s_count);
    s_count++;
}
southVilla::~southVilla()
{
	// cout << "distructor is called!\n";
}
void southVilla::set_area_of_yard(int ay)
{
	area_of_yard = ay;
}
int southVilla::get_area_of_yard()
{
	return area_of_yard;
}
void southVilla::set_area_of_parking(int ap)
{
	area_of_parking = ap;
}
int southVilla::get_area_of_parking()
{
	return area_of_parking;
}
void southVilla::set_total_price(double tp)
{
	total_price = tp;
}
double southVilla::get_total_price()
{
	return total_price;
}
double southVilla::cal_total_price()
{
	total_price = price_per_metr*(building_space + (area_of_yard*0.3) + (area_of_parking*0.15));
	return total_price;
}
int northVilla::n_count = 0;
int southVilla::s_count = 0;
