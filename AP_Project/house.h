#pragma once

#include <QString>
#include <QVector>

using namespace std;

class house
{
private:
    int floor_number, number_of_rooms, building_space, use , state; // 0 ->normal 1->administrative 2->commercial   0free 1rent 2sale 3gone
	double total_price_of_house;
    QString id , nu_username;
    static int h_count;
    bool isInList;
public:
	house();
	~house();
	//setter:
	void setFloorNumber(int f);
	void setNumberOfRooms(int n);
	void setBuildingSpace(int b);
	void setTotalPriceOfHouse(double t);
	void setUse(int a);
	void setId(QString s);
    void set_nu_username(QString s);
    void set_state(int a);
    void setIsInList(bool b);
	//getter:
	int getFloorNumber();
	int getNumberOfRooms();
	int getBuildingSpace();
	double getTotalPriceOfHouse();
	int getUse();
	QString getId();
    QString get_nu_username();
    int get_state();
    bool getIsInList();
};
