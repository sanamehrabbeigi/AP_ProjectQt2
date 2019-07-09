#include "normaluserpanel.h"
#include "startandend.h"


normaluserpanel::normaluserpanel(QWidget *parent) :
    QWidget(parent)
{
    setWindowTitle("Normal User Panel");

    btn_1 = new QPushButton("Show habitation (x,y)");
    btn_2 = new QPushButton("Show habitation (in street z)");
    btn_3 = new QPushButton("Show apartment (at least n houses)");
    btn_4 = new QPushButton("Show apartment empty house(x)");
    btn_5 = new QPushButton("Show apartment empty house(at least r rooms)");
    btn_6 = new QPushButton("Show habitations seperatly");
    btn_7 = new QPushButton("Show sorted habitations");
    L1 = new QVBoxLayout();
    L2 = new QVBoxLayout();
    L3 = new QVBoxLayout();
    L4 = new QVBoxLayout();
    L5 = new QHBoxLayout();
    L6 = new QHBoxLayout();
    L7 = new QHBoxLayout();
    la_result = new QLabel("Result :");
    li_result = new QListWidget();
    btn_select = new QPushButton("Ok");
    btn_exit = new QPushButton("Exit");
    la_input = new QLabel("Input :");
    input1 = new QLineEdit();
    input2 = new QLineEdit();
    la_id = new QLabel("Id : ");
    li_id = new QLineEdit();
    btn_showPicture = new QPushButton("Show picture");

    L1 -> addWidget(btn_1);
    L1 -> addWidget(btn_2);
    L1 -> addWidget(btn_3);
    L1 -> addWidget(btn_4);
    L1 -> addWidget(btn_5);
    L1 -> addWidget(btn_6);
    L1 -> addWidget(btn_7);
    L2 -> addWidget(la_input);
    L2 -> addWidget(input1);
    L2 -> addWidget(input2);
    L3 -> addWidget(la_result);
    L3 -> addWidget(li_result);
    L7 -> addWidget(la_id);
    L7 -> addWidget(li_id);
    L3 -> addLayout(L7);
    L4 -> addWidget(btn_select);
    L4 -> addWidget(btn_showPicture);
    L4 -> addWidget(btn_exit);
    L5 -> addLayout(L3);
    L5 -> addLayout(L4);
    L2 -> addLayout(L5);
    L6 -> addLayout(L1);
    L6 -> addLayout(L2);

    setLayout(L6);

    // SIGNALS
    connect(btn_1,SIGNAL(clicked()),this,SLOT(btn_1_pressed()));
    connect(btn_2,SIGNAL(clicked()),this,SLOT(btn_2_pressed()));
    connect(btn_3,SIGNAL(clicked()),this,SLOT(btn_3_pressed()));
    connect(btn_4,SIGNAL(clicked()),this,SLOT(btn_4_pressed()));
    connect(btn_5,SIGNAL(clicked()),this,SLOT(btn_5_pressed()));
    connect(btn_6,SIGNAL(clicked()),this,SLOT(btn_6_pressed()));
    connect(btn_7,SIGNAL(clicked()),this,SLOT(btn_7_pressed()));
    connect(btn_select,SIGNAL(clicked()),this,SLOT(btn_select_pressed()));
    connect(btn_exit,SIGNAL(clicked()),this,SLOT(btn_exit_pressed()));
    connect(btn_showPicture,SIGNAL(clicked()),this,SLOT(btn_showPicture_pressed()));
}

normaluserpanel::~normaluserpanel()
{

}

void normaluserpanel::btn_1_pressed()
{
    /*****  SHOW HABITATIONS WITH PRICE LESS THAN X AND AREA MORE THAN Y   ******/
//gheymat paye kamtar x va metraj bishtar az y
  li_result ->clear();
  li_result ->addItem("SHOW HABITATIONS WITH PRICE LESS THAN X AND AREA MORE THAN Y");
  double x = input1 ->text().toDouble();
  int y = input2 -> text().toInt();

  li_result ->addItem("Apartment : ");
  for (int i = 0; i < v_apartment.size(); i++)
  {
      li_result ->addItem("House : ");
      for(int j=0; j< v_apartment[i].get_v_house_for_apartment().size();j++)
      {
          house h = v_apartment[i].get_v_house_for_apartment()[j];
          if ( v_apartment[i].getPricePerMetr() < x && h.getBuildingSpace() > y && h.get_state() != 3 && h.get_state() != 0)
          {
              li_result ->addItem("id : " + h.getId());
              li_result ->addItem("PricePerMetr : " + QString::number(v_apartment[i].getPricePerMetr()));
              li_result ->addItem("BuildingSpace : " + QString::number(h.getBuildingSpace()));
          }
       }
  }
//
  li_result ->addItem("NorthVilla : ");
   for (int i = 0; i < v_northVilla.size(); i++)
   {
       if (v_northVilla[i].get_price_per_metr() < x && v_northVilla[i].get_building_space() > y && v_northVilla[i].get_state() != 3 &&v_northVilla[i].get_state() != 0)
       {
           li_result ->addItem("id : " + v_northVilla[i].getId());
           li_result ->addItem("PricePerMetr : " + QString::number(v_northVilla[i].get_price_per_metr()));
           li_result ->addItem("BuildingSpace : " + QString::number(v_northVilla[i].get_building_space()));
       }
   }
//
   li_result ->addItem("SouthVilla : ");
  for (int i = 0; i < v_southVilla.size(); i++)
  {
      if (v_southVilla[i].get_price_per_metr() < x && v_southVilla[i].get_building_space() > y && v_southVilla[i].get_state() == 0)
      {
          li_result ->addItem("id : " + v_southVilla[i].getId());
          li_result ->addItem("PricePerMetr : " + QString::number(v_southVilla[i].get_price_per_metr()));
          li_result ->addItem("BuildingSpace : " + QString::number(v_southVilla[i].get_building_space()));
      }
  }
}

void normaluserpanel::btn_2_pressed()
{
    /********  SHOW HABITATIONS LOCATED IN STREET Z ********/
    li_result ->clear();
    QString z = input1 ->text();
    li_result ->addItem("SHOW HABITATIONS LOCATED IN STREET Z");
    li_result ->addItem("Apartment : ");
    for (int i = 0; i < v_apartment.size(); i++)
    {
        if (v_apartment[i].getAddress().contains(z))
        {
            li_result ->addItem("address : " + v_apartment[i].getAddress());
            li_result ->addItem("House : ");
            for(int j=0; j< v_apartment[i].get_v_house_for_apartment().size();j++)
            {
                house h = v_apartment[i].get_v_house_for_apartment()[j];
                if (h.get_state() != 3 && h.get_state() != 0)
                    li_result ->addItem("id : " + h.getId());
            }
        }
    }
//
    li_result ->addItem("NorthVilla : ");
    for (int i = 0; i < v_northVilla.size(); i++)
    {
        if (v_northVilla[i].get_address().contains(z) && v_northVilla[i].get_state() != 3 && v_northVilla[i].get_state() != 0)
        {
            li_result ->addItem("id : " + v_northVilla[i].getId());
            li_result ->addItem("address : " + v_northVilla[i].get_address());
        }
    }
//
    li_result ->addItem("SouthVilla : ");
    for (int i = 0; i < v_southVilla.size(); i++)
    {
        if (v_southVilla[i].get_address().contains(z) && v_southVilla[i].get_state() != 3 && v_southVilla[i].get_state() != 0)
        {
            li_result ->addItem("id : " + v_southVilla[i].getId());
            li_result ->addItem("address : " + v_southVilla[i].get_address());
        }
    }

}

void normaluserpanel::btn_3_pressed()
{
    /***** SHOW APARTMENTS INCLUDING MORE THAN N HOUSES  ******/
    li_result ->clear();
    int N = input1 -> text().toInt();
    li_result ->addItem("SHOW APARTMENTS INCLUDING MORE THAN N HOUSES");
    for (int i = 0; i < v_apartment.size(); i++)
    {
        if ( v_apartment[i].get_v_house_for_apartment().size() > N)
        {
            li_result ->addItem("Id : " + v_apartment[i].getId());
            li_result ->addItem("Number of houses : " + QString::number(v_apartment[i].get_v_house_for_apartment().size()));
        }
    }

}

void normaluserpanel::btn_4_pressed()
{
    ///*******  SHOW APARTMENT WITH EMPTY HOUSE AT LEAST X AREA******/
    li_result ->clear();
    int x = input1 ->text().toInt();
    li_result ->addItem("SHOW APARTMENT WITH EMPTY HOUSE AT LEAST X AREA");

    for(int i=0; i< v_apartment.size();i++)
    {
        QVector <house> hans;
        for(int j=0; j< v_apartment[i].get_v_house_for_apartment().size();j++)
        {
            house h = v_apartment[i].get_v_house_for_apartment()[j];
            if ( h.get_state() != 0 && h.get_state() != 3 && h.getBuildingSpace() >= x)
                hans.push_back(h);
        }
        if ( hans.size() != 0)
        {
            li_result -> addItem("id of apartment : " + v_apartment[i].getId());
            li_result -> addItem("address : " + v_apartment[i].getAddress());
            li_result -> addItem("total price : " + QString::number(v_apartment[i].getTotalPrice()));
            for(int j =0; j< hans.size();j++)
            {
                li_result -> addItem("id of house : " + hans[j].getId());
                li_result -> addItem("building space : " + QString::number(hans[j].getBuildingSpace()));
            }
        }
    }

}

void normaluserpanel::btn_5_pressed()
{
      ///*******  SHOW APARTMENT WITH EMPTY HOUSE AT LEAST R ROOMS ******/
    li_result ->clear();
    li_result ->addItem("SHOW APARTMENT WITH EMPTY HOUSE AT LEAST R ROOMS");
    int r = input1 ->text().toInt();

    for(int i=0; i< v_apartment.size();i++)
    {
        QVector <house> hans;
        for(int j=0; j< v_apartment[i].get_v_house_for_apartment().size();j++)
        {
            house h = v_apartment[i].get_v_house_for_apartment()[j];
            if ( h.get_state() != 0 && h.get_state() != 3 && h.getNumberOfRooms() >= r)
                hans.push_back(h);
        }
        if ( hans.size() != 0)
        {
            li_result -> addItem("id of apartment : " + v_apartment[i].getId());
            li_result -> addItem("address : " + v_apartment[i].getAddress());
            li_result -> addItem("total price : " + QString::number(v_apartment[i].getTotalPrice()));
            for(int j =0; j< hans.size();j++)
            {
                li_result -> addItem("id of house : " + hans[j].getId());
                li_result -> addItem("number of rooms : " + QString::number(hans[j].getNumberOfRooms()));
            }
        }
    }


}

void normaluserpanel::btn_6_pressed()
{
    ///*******  SHOW ALL HABITATIONS SEPERATLY ******/
    li_result ->clear();
    li_result ->addItem("SHOW ALL HABITATIONS SEPERATLY");
    li_result ->addItem("Apartment : ");
    for(int i=0; i< v_apartment.size();i++)
    {
        li_result ->addItem("House : ");
        for(int j=0; j< v_apartment[i].get_v_house_for_apartment().size();j++)
        {
            house h = v_apartment[i].get_v_house_for_apartment()[j];
            if( h.get_state() != 0 && h.get_state() != 3)
            {
                li_result ->addItem("Id : " + h.getId());
                li_result ->addItem("Total price : " + QString::number(h.getTotalPriceOfHouse()));
                li_result ->addItem("Building space : " + QString::number(h.getBuildingSpace()));
                li_result ->addItem("Number of rooms : " + QString::number(h.getNumberOfRooms()));
                li_result ->addItem("Floor number : " + QString::number(h.getFloorNumber()));
            }
        }
    }
    //
    li_result ->addItem("NorthVilla : ");
    for(int i=0; i< v_northVilla.size();i++)
    {
        li_result -> addItem("Id : " + v_northVilla[i].getId());
        li_result ->addItem("Total price : " + QString::number(v_northVilla[i].get_total_price()));
        li_result ->addItem("Building space : " + QString::number(v_northVilla[i].get_building_space()));
        li_result ->addItem("Number of rooms : " + QString::number(v_northVilla[i].get_number_of_rooms()));
        li_result ->addItem("Area of front yard : " + QString::number(v_northVilla[i].get_area_of_front_yard()));
        li_result ->addItem("Area of back yard : " + QString::number(v_northVilla[i].get_area_of_back_yard()));
    }
    //
    li_result ->addItem("SouthVilla : ");
    for(int i=0; i< v_southVilla.size();i++)
    {
        li_result -> addItem("Id : " + v_southVilla[i].getId());
        li_result ->addItem("Total price : " + QString::number(v_southVilla[i].get_total_price()));
        li_result ->addItem("Building space : " + QString::number(v_southVilla[i].get_building_space()));
        li_result ->addItem("Number of rooms : " + QString::number(v_southVilla[i].get_number_of_rooms()));
        li_result ->addItem("Area of yard : " + QString::number(v_southVilla[i].get_area_of_yard()));
        li_result ->addItem("Area of parking : " + QString::number(v_southVilla[i].get_area_of_parking()));
    }

}

void normaluserpanel::btn_7_pressed()
{
    /*******  SHOW SORTED HABITATION BY PRICE*****/
    li_result ->clear();
    li_result ->addItem("SHOW SORTED HABITATION BY PRICE");
    QVector < pair<double, QString>> v_ans;
    for (int i = 0; i < v_apartment.size(); i++)
        for(int j=0; j< v_apartment[i].get_v_house_for_apartment().size();j++)
        {
            // push_back apartment ??
            if( v_apartment[i].get_v_house_for_apartment()[j].get_state()  != 0  && v_apartment[i].get_v_house_for_apartment()[j].get_state()  != 3)
                v_ans.push_back(make_pair(v_apartment[i].get_v_house_for_apartment()[j].getTotalPriceOfHouse(), v_apartment[i].get_v_house_for_apartment()[j].getId()));
        }
    for (int i = 0; i < v_northVilla.size(); i++)
        if (v_northVilla[i].get_state() == 0)
            v_ans.push_back(make_pair(v_northVilla[i].get_total_price(), v_northVilla[i].getId()));
    for (int i = 0; i < v_southVilla.size(); i++)
        if (v_southVilla[i].get_state() == 0)
            v_ans.push_back(make_pair(v_southVilla[i].get_total_price(), v_southVilla[i].getId()));

    sort(v_ans.begin(),v_ans.end());

    for(int i=0; i< v_ans.size();i++)
    {
        if ( v_ans[i].second[0] =='0' &&  v_ans[i].second[1] =='0')
            li_result ->addItem( "house id : " + v_ans[i].second  + " price : " + QString::number(v_ans[i].first));
        else if ( v_ans[i].second[0] =='1' &&  v_ans[i].second[1] =='0')
                li_result ->addItem( "north villa id : " + v_ans[i].second  + " price : " + QString::number(v_ans[i].first));
        else if ( v_ans[i].second[0] =='1' &&  v_ans[i].second[1] =='1')
            li_result ->addItem( "south villa id : " + v_ans[i].second  + " price : " + QString::number(v_ans[i].first));
    }

}

void normaluserpanel::btn_select_pressed()
{
    QString id = li_id->text();
    if ( id != "" )
    {
        if (id[0] == '0' && id[1] == '0')
        {
            QMessageBox * msg = new QMessageBox;
            msg->setText("You can't choose apartment!");
            msg->setIcon(QMessageBox::Information);
            msg->setWindowTitle("ERROR!");
            msg->exec();
        }
        else if( id[0] == '0' && id[1] == '1')
        {
            for(int i =0; i< v_apartment.size();i++)
            {
                for(int j=0; j< v_apartment[i].get_v_house_for_apartment().size();j++)
                {
                    house h = v_apartment[i].get_v_house_for_apartment()[j];
                    if( h.getId() == id)
                    {
                        if ( h.get_state() == 1)
                        {
                            for(int k=0; k < v_rent.size();k++)
                            {
                                if( v_rent[k].get_id() == id &&  v_rent[k].get_final_price() <= v_user[index_of_current_user].get_cash())
                                {
                                    v_user[index_of_current_user].set_cash(v_user[index_of_current_user].get_cash() - v_rent[k].get_final_price());
                                    h.set_state(3);
                                    h.set_nu_username(v_user[index_of_current_user].get_username());
                                    for(int l =0;l < v_user.size();l++)
                                        if (v_user[l].get_username() == v_apartment[i].get_m_username() )
                                        {
                                            v_user[i].set_cash(  v_user[i].get_cash() + v_rent[k].get_final_price());
                                            l = v_user.size();
                                        }
                                    k = v_rent.size();
                                    QMessageBox * msg = new QMessageBox;
                                    msg->setText("Rent Done!");
                                    msg->setIcon(QMessageBox::Information);
                                    msg->setWindowTitle("Hoooooraaaaa!");
                                    msg->exec();
                                }
                                else if( v_rent[k].get_id() == id &&  v_rent[k].get_final_price() > v_user[index_of_current_user].get_cash())
                                {
                                    QMessageBox * msg = new QMessageBox;
                                    msg->setText("Not enough money!");
                                    msg->setIcon(QMessageBox::Information);
                                    msg->setWindowTitle("ERROR!");
                                    msg->exec();
                                }
                            }
                        }
                        else if (h.get_state() == 2)
                        {
                            for(int k=0; k < v_sale.size();k++)
                            {
                                if( v_sale[k].get_id() == id &&  v_sale[k].get_final_price() <= v_user[index_of_current_user].get_cash())
                                {
                                    v_user[index_of_current_user].set_cash(v_user[index_of_current_user].get_cash() - v_sale[k].get_final_price());
                                    h.set_state(3);
                                    h.set_nu_username(v_user[index_of_current_user].get_username());
                                    for(int l =0;l < v_user.size();l++)
                                        if (v_user[l].get_username() == v_apartment[i].get_m_username() )
                                        {
                                            v_user[i].set_cash(  v_user[i].get_cash() + v_sale[k].get_final_price());
                                            l = v_user.size();
                                        }
                                    QMessageBox * msg = new QMessageBox;
                                    msg->setText("Sale Done!");
                                    msg->setIcon(QMessageBox::Information);
                                    msg->setWindowTitle("Hoooooraaaaa!");
                                    msg->exec();
                                    k = v_sale.size();
                                }
                                else if( v_sale[k].get_id() == id &&  v_sale[k].get_final_price() > v_user[index_of_current_user].get_cash())
                                {
                                    QMessageBox * msg = new QMessageBox;
                                    msg->setText("Not enough money!");
                                    msg->setIcon(QMessageBox::Information);
                                    msg->setWindowTitle("ERROR!");
                                    msg->exec();
                                }
                            }
                        }
                        else
                        {
                            QMessageBox * msg = new QMessageBox;
                            msg->setText("Can't access!");
                            msg->setIcon(QMessageBox::Information);
                            msg->setWindowTitle("ERROR!");
                            msg->exec();
                        }
                        j = v_apartment[i].get_v_house_for_apartment().size();
                        i = v_apartment.size();
                     }
                }
            }
        }
        else if( id[0] == '1' && id[1] == '0')
        {
            for(int i=0; i< v_northVilla.size();i++)
            {
                if ( id == v_northVilla[i].getId() )
                {
                    if (v_northVilla[i].get_state() == 1)
                    {
                        for(int j=0; j< v_rent.size();j++)
                        {
                            if( id == v_rent[j].get_id() && v_user[index_of_current_user].get_cash() >= v_rent[j].get_final_price() )
                            {
                                v_northVilla[i].set_nu_username(v_user[index_of_current_user].get_username());
                                v_northVilla[i].set_state(3);
                                v_user[index_of_current_user].set_cash(v_user[index_of_current_user].get_cash() - v_rent[j].get_final_price());
                                for(int k =0; k< v_user.size();k++)
                                    if( v_user[k].get_username() == v_northVilla[i].get_m_username() )
                                    {
                                        v_user[k].set_cash(v_user[k].get_cash() + v_rent[j].get_final_price());
                                        k = v_user.size();
                                    }
                                QMessageBox * msg = new QMessageBox;
                                msg->setText("Rent Done!");
                                msg->setIcon(QMessageBox::Information);
                                msg->setWindowTitle("Hoooooraaaaa!");
                                msg->exec();
                                j = v_rent.size();
                            }
                            else if (id == v_rent[j].get_id() && v_user[index_of_current_user].get_cash() < v_rent[j].get_final_price() )
                            {
                                QMessageBox * msg = new QMessageBox;
                                msg->setText("Not enough money!");
                                msg->setIcon(QMessageBox::Information);
                                msg->setWindowTitle("ERROR!");
                                msg->exec();
                            }
                        }
                    }
                    else if (v_northVilla[i].get_state() == 2)
                    {
                        for(int j=0; j< v_sale.size();j++)
                        {
                            if( id == v_sale[j].get_id() && v_user[index_of_current_user].get_cash() >= v_sale[j].get_final_price() )
                            {
                                v_northVilla[i].set_nu_username(v_user[index_of_current_user].get_username());
                                v_northVilla[i].set_state(3);
                                v_user[index_of_current_user].set_cash(v_user[index_of_current_user].get_cash() - v_sale[j].get_final_price());
                                for(int k =0; k< v_user.size();k++)
                                    if( v_user[k].get_username() == v_northVilla[i].get_m_username() )
                                    {
                                        v_user[k].set_cash(v_user[k].get_cash() + v_sale[j].get_final_price());
                                        k = v_user.size();
                                    }
                                QMessageBox * msg = new QMessageBox;
                                msg->setText("Sale Done!");
                                msg->setIcon(QMessageBox::Information);
                                msg->setWindowTitle("Hoooooraaaaa!");
                                msg->exec();
                                j = v_sale.size();
                            }
                            else if (id == v_sale[j].get_id() && v_user[index_of_current_user].get_cash() < v_sale[j].get_final_price() )
                            {
                                QMessageBox * msg = new QMessageBox;
                                msg->setText("Not enough money!");
                                msg->setIcon(QMessageBox::Information);
                                msg->setWindowTitle("ERROR!");
                                msg->exec();
                            }
                        }
                    }
                    else
                    {
                        QMessageBox * msg = new QMessageBox;
                        msg->setText("Can't access!");
                        msg->setIcon(QMessageBox::Information);
                        msg->setWindowTitle("ERROR!");
                        msg->exec();
                    }
                    i = v_northVilla.size();
                }
            }
        }
        else if( id[0] == '1' && id[1] == '1')
        {
            for(int i=0; i< v_southVilla.size();i++)
            {
                if ( id == v_southVilla[i].getId() )
                {
                    if (v_southVilla[i].get_state() == 1)
                    {
                        for(int j=0; j< v_rent.size();j++)
                        {
                            if( id == v_rent[j].get_id() && v_user[index_of_current_user].get_cash() >= v_rent[j].get_final_price() )
                            {
                                v_southVilla[i].set_nu_username(v_user[index_of_current_user].get_username());
                                v_southVilla[i].set_state(3);
                                v_user[index_of_current_user].set_cash(v_user[index_of_current_user].get_cash() - v_rent[j].get_final_price());
                                for(int k =0; k< v_user.size();k++)
                                    if( v_user[k].get_username() == v_southVilla[i].get_m_username() )
                                    {
                                        v_user[k].set_cash(v_user[k].get_cash() + v_rent[j].get_final_price());
                                        k = v_user.size();
                                    }
                                QMessageBox * msg = new QMessageBox;
                                msg->setText("Rent Done!");
                                msg->setIcon(QMessageBox::Information);
                                msg->setWindowTitle("Hoooooraaaaa!");
                                msg->exec();
                                j = v_rent.size();
                            }
                            else if (id == v_rent[j].get_id() && v_user[index_of_current_user].get_cash() < v_rent[j].get_final_price() )
                            {
                                QMessageBox * msg = new QMessageBox;
                                msg->setText("Not enough money!");
                                msg->setIcon(QMessageBox::Information);
                                msg->setWindowTitle("ERROR!");
                                msg->exec();
                            }
                        }
                    }
                    else if (v_southVilla[i].get_state() == 2)
                    {
                        for(int j=0; j< v_sale.size();j++)
                        {
                            if( id == v_sale[j].get_id() && v_user[index_of_current_user].get_cash() >= v_sale[j].get_final_price() )
                            {
                                v_southVilla[i].set_nu_username(v_user[index_of_current_user].get_username());
                                v_southVilla[i].set_state(3);
                                v_user[index_of_current_user].set_cash(v_user[index_of_current_user].get_cash() - v_sale[j].get_final_price());
                                for(int k =0; k< v_user.size();k++)
                                    if( v_user[k].get_username() == v_southVilla[i].get_m_username() )
                                    {
                                        v_user[k].set_cash(v_user[k].get_cash() + v_sale[j].get_final_price());
                                        k = v_user.size();
                                    }
                                QMessageBox * msg = new QMessageBox;
                                msg->setText("Sale Done!");
                                msg->setIcon(QMessageBox::Information);
                                msg->setWindowTitle("Hoooooraaaaa!");
                                msg->exec();
                                j = v_sale.size();
                            }
                            else if (id == v_sale[j].get_id() && v_user[index_of_current_user].get_cash() < v_sale[j].get_final_price() )
                            {
                                QMessageBox * msg = new QMessageBox;
                                msg->setText("Not enough money!");
                                msg->setIcon(QMessageBox::Information);
                                msg->setWindowTitle("ERROR!");
                                msg->exec();
                            }
                        }
                    }
                    else
                    {
                        QMessageBox * msg = new QMessageBox;
                        msg->setText("Can't access!");
                        msg->setIcon(QMessageBox::Information);
                        msg->setWindowTitle("ERROR!");
                        msg->exec();
                    }
                    i = v_northVilla.size();
                }
            }
        }
        else
        {
            QMessageBox * msg = new QMessageBox;
            msg->setText("Not Valid!");
            msg->setIcon(QMessageBox::Information);
            msg->setWindowTitle("ERROR!");
            msg->exec();
        }

    }
    end();
}

void normaluserpanel::btn_exit_pressed()
{
    QTime time = QTime ::currentTime();
    Time mytime;
    mytime.hour = time.hour();
    mytime.minute = time.minute();
    mytime.second = time.second();
    v_user[index_of_current_user].set_time_out(mytime);
    qDebug() <<  v_user[index_of_current_user].get_time_out().hour <<":" << v_user[index_of_current_user].get_time_out().minute << endl;
    qDebug() << v_user.size() << endl;
   // end();
    this -> close();
}

void normaluserpanel::btn_showPicture_pressed()
{
    QString id = li_id->text();
    bool b =0;
    QString path;
    for (int i = 0; i < v_apartment.size(); ++i)
    {
        if (id == v_apartment[i].getId())
        {
            path = v_apartment[i].getPicAd();
            b = 1;
            break;
        }
    }
    if ( b == 1)
    {
        showPicture * showDiag = new showPicture(path);
        showDiag->exec();
    }
    else
    {
        QMessageBox * msg = new QMessageBox;
        msg->setText("Not Found!");
        msg->setIcon(QMessageBox::Information);
        msg->setWindowTitle("ERROR!");
        msg->exec();
    }
}

