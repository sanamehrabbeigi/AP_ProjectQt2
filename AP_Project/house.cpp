#include "house.h"

//house
house::house()
{
	// cout << "constructor is called!\n";
	number_of_rooms = 0;
	floor_number = 0;
	building_space = 0;
	use = 0;
    id = "01" + QString::number(h_count);
    nu_username = "-1";
    state = 0;
    h_count++;
    isInList = 0;
}
house::~house()
{
	// cout << "distructor is called!\n";
}

//setter
void house::setFloorNumber(int f)
{
	floor_number = f;
}
void house::setNumberOfRooms(int n)
{
	number_of_rooms = n;
}
void house::setBuildingSpace(int b)
{
	building_space = b;
}
void house::setTotalPriceOfHouse(double t)
{
	total_price_of_house = t;
}
void house::setUse(int a)
{
	use = a;
}
void house::setId(QString s)
{
	id = s;
}
void house::set_nu_username(QString s)
{
    nu_username = s;
}
void house::set_state(int a)
{
    state = a;
}

void house::setIsInList(bool b)
{
    isInList = b;
}

//getter
int house::getFloorNumber()
{
	return floor_number;
}
int house::getNumberOfRooms()
{
	return number_of_rooms;
}
int house::getBuildingSpace()
{
	return building_space;
}
double house::getTotalPriceOfHouse()
{
	return total_price_of_house;
}
int house::getUse()
{
	return use;
}
QString house::getId()
{
	return id;
}
QString house::get_nu_username()
{
    return nu_username;
}
int house::get_state()
{
    return state;
}

bool house::getIsInList()
{
    return isInList;
}

int house:: h_count = 0;
