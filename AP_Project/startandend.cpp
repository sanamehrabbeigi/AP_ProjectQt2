#include "global.h"
#include "startandend.h"

void makeV_apartment(QJsonDocument &jsdoc)
{
    if(jsdoc.isNull() || jsdoc.isEmpty())
        return;
     // clear the vector
    v_apartment.clear(); //?

    QJsonArray all = jsdoc.array();
    for(int i=0; i<all.size();i++)
    {
        apartment apt;
        QJsonObject Jobj = all[i].toObject();
        apt.setId(Jobj["id"].toString());
        apt.setAddress(Jobj["address"].toString());
        apt.setElevator(Jobj["elevator"].toBool());
        apt.setTotalPrice(Jobj["total_price"].toDouble());
        apt.setTotalSpace(Jobj["total_space"].toInt());
        apt.set_m_username(Jobj["m_username"].toString());
        apt.setPricePerMetr(Jobj["price_per_metr"].toDouble());
        apt.setNumberOfFloors(Jobj["number_of_floors"].toInt());

        QVector<house> vh;
        QJsonArray Jarr = Jobj["houses"].toArray();
        for(int j=0; j< Jarr.size();j++)
        {
            house h;
            QJsonObject Jobj2 = Jarr[j].toObject();
            h.setId(Jobj2["id"].toString());
            h.setUse(Jobj2["use"].toInt());
            h.set_state(Jobj2["state"].toInt());
            h.setFloorNumber(Jobj2["floor_number"].toInt());
            h.set_nu_username(Jobj2["nu_username"].toString());
            h.setBuildingSpace(Jobj2["building_space"].toInt());
            h.setNumberOfRooms(Jobj2["number_of_rooms"].toInt());
            h.setTotalPriceOfHouse(Jobj2["total_price_of_house"].toDouble());

            vh.push_back(h);
        }
        apt.set_v_house_for_apartment(vh);
        v_apartment.push_back(apt);
    }

}

void makeV_northVilla(QJsonDocument &jsdoc)
{
    if(jsdoc.isNull() || jsdoc.isEmpty())
        return;
     // clear thr vector
    QJsonArray all = jsdoc.array();
    for(int i=0; i<all.size();i++)
    {
        northVilla nv;
        QJsonObject Jobj = all[i].toObject();
        nv.setId(Jobj["id"].toString());
        nv.set_total_price(Jobj["total_price"].toDouble());
        nv.set_area_of_back_yard(Jobj["area_of_back_yard"].toInt());
        nv.set_area_of_front_yard(Jobj["area_of_front_yard"].toInt());
        nv.set_state(Jobj["state"].toInt());
        nv.set_address(Jobj["address"].toString());
        nv.set_m_username(Jobj["m_username"].toString());
        nv.set_nu_username(Jobj["nu_username"].toString());
        nv.set_total_space(Jobj["total_space"].toInt());
        nv.set_building_space(Jobj["building_space"].toInt());
        nv.set_price_per_metr(Jobj["price_per_metr"].toDouble());
        nv.set_number_of_rooms(Jobj["number_of_rooms"].toInt());

        v_northVilla.push_back(nv);
     }
}

void makeV_southVilla(QJsonDocument &jsdoc)
{
    if(jsdoc.isNull() || jsdoc.isEmpty())
        return;
    // clear thr vector

    QJsonArray all = jsdoc.array();
    for(int i=0; i<all.size();i++)
    {
        southVilla sv;
        QJsonObject Jobj = all[i].toObject();
        sv.setId(Jobj["id"].toString());
        sv.set_total_price(Jobj["total_price"].toDouble());
        sv.set_area_of_yard(Jobj["area_of_yard"].toInt());
        sv.set_area_of_parking(Jobj["area_of_parkingd"].toInt());
        sv.set_state(Jobj["state"].toInt());
        sv.set_address(Jobj["address"].toString());
        sv.set_m_username(Jobj["m_username"].toString());
        sv.set_nu_username(Jobj["nu_username"].toString());
        sv.set_total_space(Jobj["total_space"].toInt());
        sv.set_building_space(Jobj["building_space"].toInt());
        sv.set_price_per_metr(Jobj["price_per_metr"].toDouble());
        sv.set_number_of_rooms(Jobj["number_of_rooms"].toInt());

        v_southVilla.push_back(sv);
     }
}

void makeV_user(QJsonDocument &jsdoc)
{
    if(jsdoc.isNull() || jsdoc.isEmpty())
        return;
    // clear thr vector

    QJsonArray all = jsdoc.array();
    for(int i=0; i<all.size();i++)
    {
        user u;
        QJsonObject Jobj = all[i].toObject();
        u.set_cash(Jobj["cash"].toDouble());
        u.set_name(Jobj["name"].toString());
        u.set_type(Jobj["type"].toBool());
        u.set_state(Jobj["state"].toInt());
        u.set_family(Jobj["family"].toString());
        Time t;
        t.hour = Jobj["time_in.hour"].toInt();
        t.minute = Jobj["time_in.minute"].toInt();
        t.second = Jobj["time_in.second"].toInt();
        u.set_time_in(t);
        t.hour = Jobj["time_out.hour"].toInt();
        t.minute = Jobj["time_out.minute"].toInt();
        t.second = Jobj["time_out.second"].toInt();
        u.set_time_out(t);
        date d;
        d.year = Jobj["birthday.year"].toInt();
        d.month = Jobj["birthday.month"].toInt();
        d.day = Jobj["birthday.day"].toInt();
        u.set_birthday(d);
        u.set_password(Jobj["password"].toString());
        u.set_username(Jobj["usrname"].toString());

        v_user.push_back(u);
    }
}

void makeV_rent(QJsonDocument &jsdoc)
{
    if(jsdoc.isNull() || jsdoc.isEmpty())
        return;
    // clear thr vector

    QJsonArray all = jsdoc.array();
    for(int i=0; i<all.size();i++)
    {
        rent r;
        QJsonObject Jobj = all[i].toObject();
        r.set_id(Jobj["id"].toString());
        r.set_type(Jobj["type"].toBool());
        r.set_corent(Jobj["corent"].toDouble());
        r.set_dorent(Jobj["dorent"].toInt());
        r.set_mortgage(Jobj["mortgage"].toDouble());
        r.set_commission(Jobj["commission"].toDouble());
        r.set_final_price(Jobj["final_price"].toDouble());

        v_rent.push_back(r);
    }
}

void makeV_sale(QJsonDocument &jsdoc)
{
    if(jsdoc.isNull() || jsdoc.isEmpty())
        return;
    // clear thr vector

    QJsonArray all = jsdoc.array();
    for(int i=0; i<all.size();i++)
    {
        sale s;
        QJsonObject Jobj = all[i].toObject();
        s.set_id(Jobj["id"].toString());
        s.set_type(Jobj["type"].toBool());
        s.set_commission(Jobj["commission"].toDouble());
        s.set_final_price(Jobj["final_price"].toDouble());
        s.set_payment(Jobj["payment"].toBool());

        v_sale.push_back(s);
    }

}




void toJsonApartment(QJsonDocument & doc)
{
    QJsonArray all;
    for(int i=0 ; i< v_apartment.size();i++)
    {
        apartment apt = v_apartment[i];
        QJsonObject Jobj;
        Jobj.insert("total_space", QJsonValue(apt.getTotalSpace()));
        Jobj.insert("number_of_floors", QJsonValue(apt.getNumberOfFloors()));
        Jobj.insert("total_price", QJsonValue(apt.getTotalPrice()));
        Jobj.insert("price_per_metr", QJsonValue(apt.getPricePerMetr()));
        Jobj.insert("elevator", QJsonValue(apt.getElevator()));
        Jobj.insert("address", QJsonValue(apt.getAddress()));
        Jobj.insert("id", QJsonValue(apt.getId()));
        Jobj.insert("m_username", QJsonValue(apt.get_m_username()));

        QJsonArray houses;
        for ( int j=0; j< apt.get_v_house_for_apartment().size();j++)
        {
            house hos = apt.get_v_house_for_apartment()[j];
            QJsonObject Jobj2;
            Jobj2.insert("floor_number", QJsonValue(hos.getFloorNumber()));
            Jobj2.insert("number_of_rooms", QJsonValue(hos.getNumberOfRooms()));
            Jobj2.insert("building_space", QJsonValue(hos.getBuildingSpace()));
            Jobj2.insert("use", QJsonValue(hos.getUse()));
            Jobj2.insert("state", QJsonValue(hos.get_state()));
            Jobj2.insert("total_price_of_house", QJsonValue(hos.getTotalPriceOfHouse()));
            Jobj2.insert("id", QJsonValue(hos.getId()));
            Jobj2.insert("nu_username", QJsonValue(hos.get_nu_username()));

            houses.push_back(Jobj2);
        }

        Jobj.insert("houses", QJsonValue(houses));
        all.push_back(Jobj);
    }
    doc.setArray(all);
}

void toJsonNorthVilla(QJsonDocument & doc)
{
    QJsonArray all;
    for(int i=0 ; i< v_northVilla.size();i++)
    {
        northVilla nv = v_northVilla[i];
        QJsonObject Jobj;
        Jobj.insert("building_space", QJsonValue(nv.get_building_space()));
        Jobj.insert("total_space", QJsonValue(nv.get_total_space()));
        Jobj.insert("price_per_metr", QJsonValue(nv.get_price_per_metr()));
        Jobj.insert("number_of_rooms", QJsonValue(nv.get_number_of_rooms()));
        Jobj.insert("address", QJsonValue(nv.get_address()));
        Jobj.insert("id", QJsonValue(nv.getId()));
        Jobj.insert("m_username", QJsonValue(nv.get_m_username()));
        Jobj.insert("nu_username", QJsonValue(nv.get_nu_username()));
        Jobj.insert("state", QJsonValue(nv.get_state()));
        Jobj.insert("area_of_front_yard", QJsonValue(nv.get_area_of_front_yard()));
        Jobj.insert("area_of_back_yard", QJsonValue(nv.get_area_of_back_yard()));
        Jobj.insert("total_price", QJsonValue(nv.get_total_price()));

        all.push_back(Jobj);
    }
    doc.setArray(all);
}

void toJsonSouthVilla(QJsonDocument & doc)
{
    QJsonArray all;
    for(int i=0 ; i< v_southVilla.size();i++)
    {
        southVilla sv = v_southVilla[i];
        QJsonObject Jobj;
        Jobj.insert("building_space", QJsonValue(sv.get_building_space()));
        Jobj.insert("total_space", QJsonValue(sv.get_total_space()));
        Jobj.insert("price_per_metr", QJsonValue(sv.get_price_per_metr()));
        Jobj.insert("number_of_rooms", QJsonValue(sv.get_number_of_rooms()));
        Jobj.insert("address", QJsonValue(sv.get_address()));
        Jobj.insert("id", QJsonValue(sv.getId()));
        Jobj.insert("m_username", QJsonValue(sv.get_m_username()));
        Jobj.insert("nu_username", QJsonValue(sv.get_nu_username()));
        Jobj.insert("state", QJsonValue(sv.get_state()));
        Jobj.insert("area_of_yard", QJsonValue(sv.get_area_of_yard()));
        Jobj.insert("area_of_parkingd", QJsonValue(sv.get_area_of_parking()));
        Jobj.insert("total_price", QJsonValue(sv.get_total_price()));

        all.push_back(Jobj);
    }
    doc.setArray(all);
}

void toJsonUser(QJsonDocument & doc)
{
    QJsonArray all;
    qDebug() <<"now in toJsonUser" << endl;
    for(int i=0 ; i< v_user.size();i++)
    {
        user u = v_user[i];
        QJsonObject Jobj;
        Jobj.insert("state", QJsonValue(u.get_state()));
        Jobj.insert("type", QJsonValue(u.get_type()));
        Jobj.insert("name", QJsonValue(u.get_name()));
        Jobj.insert("family", QJsonValue(u.get_family()));
        Jobj.insert("username", QJsonValue(u.get_username()));
        Jobj.insert("password", QJsonValue(u.get_password()));
        Jobj.insert("birthday.year", QJsonValue(u.get_birthday().year));
        Jobj.insert("birthday.month", QJsonValue(u.get_birthday().month));
        Jobj.insert("birthday.day", QJsonValue(u.get_birthday().day));
        Jobj.insert("time_in.hour", QJsonValue(u.get_time_in().hour));
        Jobj.insert("time_in.minute", QJsonValue(u.get_time_in().minute));
        Jobj.insert("time_in.second", QJsonValue(u.get_time_in().second));
        Jobj.insert("time_out.hour", QJsonValue(u.get_time_out().hour));
        Jobj.insert("time_out.minute", QJsonValue(u.get_time_out().minute));
        Jobj.insert("time_out.second", QJsonValue(u.get_time_out().second));
        Jobj.insert("cash", QJsonValue(u.get_cash()));

        all.push_back(Jobj);
    }
    doc.setArray(all);
}

void toJsonRent(QJsonDocument & doc)
{
    QJsonArray all;
    for(int i=0 ; i< v_rent.size();i++)
    {
        rent r = v_rent[i];
        QJsonObject Jobj;
        Jobj.insert("type", QJsonValue(r.get_type()));
        Jobj.insert("commission", QJsonValue(r.get_commission()));
        Jobj.insert("mortgage", QJsonValue(r.get_mortgage()));
        Jobj.insert("corent", QJsonValue(r.get_corent()));
        Jobj.insert("final_price", QJsonValue(r.get_final_price()));
        Jobj.insert("dorent", QJsonValue(r.get_dorent()));
        Jobj.insert("id", QJsonValue(r.get_id()));

        all.push_back(Jobj);
    }
    doc.setArray(all);
}

void toJsonSale(QJsonDocument & doc)
{
    QJsonArray all;
    for(int i=0 ; i< v_sale.size();i++)
    {
        sale s = v_sale[i];
        QJsonObject Jobj;
        Jobj.insert("type", QJsonValue(s.get_type()));
        Jobj.insert("payment", QJsonValue(s.get_payment()));
        Jobj.insert("commission", QJsonValue(s.get_commission()));
        Jobj.insert("final_price", QJsonValue(s.get_final_price()));
        Jobj.insert("id", QJsonValue(s.get_id()));

        all.push_back(Jobj);
    }
    doc.setArray(all);
}

void start()
{
    QFile json1(QString("ApartmentDoc"));
    json1.open(QFile::ReadOnly);
    QJsonDocument jsdoc1=QJsonDocument().fromJson(json1.readAll());
    makeV_apartment(jsdoc1);
    json1.close();

    QFile json2(QString("NorthVillaDoc"));
    json2.open(QFile::ReadOnly);
    QJsonDocument jsdoc2=QJsonDocument().fromJson(json2.readAll());
    makeV_apartment(jsdoc2);
    json2.close();

    QFile json3(QString("SouthVillaDoc"));
    json3.open(QFile::ReadOnly);
    QJsonDocument jsdoc3=QJsonDocument().fromJson(json3.readAll());
    makeV_apartment(jsdoc3);
    json3.close();

    QFile json4(QString("UserDoc"));
    json4.open(QFile::ReadOnly);
    QJsonDocument jsdoc4=QJsonDocument().fromJson(json4.readAll());
    makeV_apartment(jsdoc4);
    json4.close();

    QFile json5(QString("RentDoc"));
    json5.open(QFile::ReadOnly);
    QJsonDocument jsdoc5=QJsonDocument().fromJson(json5.readAll());
    makeV_apartment(jsdoc5);
    json5.close();

    QFile json6(QString("SaleDoc"));
    json6.open(QFile::ReadOnly);
    QJsonDocument jsdoc6=QJsonDocument().fromJson(json6.readAll());
    makeV_apartment(jsdoc6);
    json6.close();
}

void end()
{
    qDebug() <<"now in end" << endl;

    QJsonDocument doc1;
    toJsonApartment(doc1);
    QFile json1(QString("ApartmentDoc"));
    json1.open(QFile::WriteOnly);
    json1.write(doc1.toJson());
    json1.close();

    QJsonDocument doc2;
    toJsonNorthVilla(doc2);
    QFile json2(QString("NorthVillaDoc"));
    json2.open(QFile::WriteOnly);
    json2.write(doc2.toJson());
    json2.close();

    QJsonDocument doc3;
    toJsonSouthVilla(doc3);
    QFile json3(QString("SouthVillaDoc"));
    json3.open(QFile::WriteOnly);
    json3.write(doc3.toJson());
    json3.close();

    QJsonDocument doc4;
    toJsonUser(doc4);
    QFile json4(QString("UserDoc"));
    json4.open(QFile::WriteOnly);
    json4.write(doc4.toJson());
    json4.close();

    QJsonDocument doc5;
    toJsonRent(doc4);
    QFile json5(QString("RentDoc"));
    json5.open(QFile::WriteOnly);
    json5.write(doc5.toJson());
    json5.close();

    QJsonDocument doc6;
    toJsonSale(doc6);
    QFile json6(QString("SaleDoc"));
    json6.open(QFile::WriteOnly);
    json6.write(doc6.toJson());
    json6.close();
}
