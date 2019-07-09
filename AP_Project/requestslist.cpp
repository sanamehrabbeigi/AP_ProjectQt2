#include "requestslist.h"


requestsList::requestsList(QWidget *parent) :
    QDialog(parent)
{
    titleLabel = new QLabel("Requests List");
    IDLabel = new QLabel("ID");

    acceptButton = new QPushButton ("Accept");
    declineButton = new QPushButton("Decline");

    li_result = new QListWidget();


    connect(acceptButton, SIGNAL(clicked(bool)), this, SLOT(acceptButtonClicked()));
    connect(declineButton, SIGNAL(clicked(bool)), this, SLOT(declineButtonClicked()));


    li_result ->clear();
    li_result ->addItem("SHOW ALL REQUESTS");
    for(int i=0; i< v_apartment.size();i++)
    {
        li_result ->addItem("House : ");
        for(int j=0; j< v_apartment[i].get_v_house_for_apartment().size();j++)
        {
            house h = v_apartment[i].get_v_house_for_apartment()[j];
            if( h.getIsInList() == 1 && v_apartment[i].get_m_username() == current_user)
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
        if (v_northVilla[i].getIsInList() == 1 && v_northVilla[i].get_m_username() == current_user)
        {
            li_result -> addItem("Id : " + v_northVilla[i].getId());
            li_result ->addItem("Total price : " + QString::number(v_northVilla[i].get_total_price()));
            li_result ->addItem("Building space : " + QString::number(v_northVilla[i].get_building_space()));
            li_result ->addItem("Number of rooms : " + QString::number(v_northVilla[i].get_number_of_rooms()));
            li_result ->addItem("Area of front yard : " + QString::number(v_northVilla[i].get_area_of_front_yard()));
            li_result ->addItem("Area of back yard : " + QString::number(v_northVilla[i].get_area_of_back_yard()));
        }
    }
    //
    li_result ->addItem("SouthVilla : ");
    for(int i=0; i< v_southVilla.size();i++)
    {
        if (v_southVilla[i].getIsInList() == 1 && v_northVilla[i].get_m_username() == current_user)
        {
            li_result -> addItem("Id : " + v_southVilla[i].getId());
            li_result ->addItem("Total price : " + QString::number(v_southVilla[i].get_total_price()));
            li_result ->addItem("Building space : " + QString::number(v_southVilla[i].get_building_space()));
            li_result ->addItem("Number of rooms : " + QString::number(v_southVilla[i].get_number_of_rooms()));
            li_result ->addItem("Area of yard : " + QString::number(v_southVilla[i].get_area_of_yard()));
            li_result ->addItem("Area of parking : " + QString::number(v_southVilla[i].get_area_of_parking()));
        }
    }



    IDLineEdit = new QLineEdit();

    QVBoxLayout * vBox = new QVBoxLayout();
    vBox->addWidget(titleLabel);
    vBox->addWidget(li_result);
    QHBoxLayout * hBox = new QHBoxLayout();
    hBox->addWidget(IDLabel);
    hBox->addWidget(IDLineEdit);
    hBox->addWidget(declineButton);
    hBox->addWidget(acceptButton);

    QVBoxLayout * mainLayout = new QVBoxLayout();
    mainLayout->addLayout(vBox);
    mainLayout->addLayout(hBox);

    setLayout(mainLayout);
}

requestsList::~requestsList()
{

}

void requestsList::declineButtonClicked()
{
    QString id = IDLineEdit->text();
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
                    if( v_apartment[i].get_v_house_for_apartment()[j].getId() == id)
                    {
                        v_apartment[i].get_v_house_for_apartment()[j].setIsInList(0);
                        v_apartment[i].get_v_house_for_apartment()[j].set_nu_username("-1");
                    }
                }
            }
        }
        else if( id[0] == '1' && id[1] == '0')
        {
            for(int i=0; i<v_northVilla.size();i++)
            {
                if( v_northVilla[i].getId() == id)
                {
                    v_northVilla[i].setIsInList(0);
                    v_northVilla[i].set_nu_username("-1");
                }
            }
        }
        else if( id[0] == '1'  && id[1] == '1')
        {
            for(int i=0; i<v_southVilla.size();i++)
            {
                if( v_southVilla[i].getId() == id)
                {
                    v_southVilla[i].setIsInList(0);
                    v_southVilla[i].set_nu_username("-1");
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
    else
    {
        QMessageBox * msg = new QMessageBox;
        msg->setText("Please Enter ID!");
        msg->setIcon(QMessageBox::Information);
        msg->setWindowTitle("ERROR!");
        msg->exec();
    }
    end();
}

void requestsList::acceptButtonClicked()
{
    QString id = IDLineEdit->text();
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
                           if ( h.get_state() == 1 && h.getIsInList() == 1 )
                           {
                               for(int k=0; k < v_rent.size();k++)
                               {
                                   if (v_rent[k].get_id() == id)
                                   {
                                       for(int l =0;l < v_user.size();l++)
                                       {
                                           if( v_user[l].get_username() == h.get_nu_username() && v_rent[k].get_final_price() <= v_user[l].get_cash())
                                           {
                                               v_user[l].set_cash(v_user[l].get_cash() - v_rent[k].get_final_price());
                                               v_apartment[i].get_v_house_for_apartment()[j].set_state(3);
                                               v_apartment[i].get_v_house_for_apartment()[j].setIsInList(0);
                                               v_user[index_of_current_user].set_cash(  v_user[index_of_current_user].get_cash() + v_rent[k].get_final_price());
                                               l = v_user.size();
                                               k = v_rent.size();
                                               QMessageBox * msg = new QMessageBox;
                                               msg->setText("Rent Done!");
                                               msg->setIcon(QMessageBox::Information);
                                               msg->setWindowTitle("Hoooooraaaaa!");
                                               msg->exec();
                                           }
                                           else if(v_user[l].get_username() == h.get_nu_username() && v_rent[k].get_final_price() > v_user[l].get_cash())
                                           {
                                               QMessageBox * msg = new QMessageBox;
                                               msg->setText("Not enough money!");
                                               msg->setIcon(QMessageBox::Information);
                                               msg->setWindowTitle("ERROR!");
                                               msg->exec();
                                           }
                                       }
                                   }
                               }
                           }
                           else if (h.get_state() == 2 && h.getIsInList() == 1)
                           {
                               for(int k=0; k < v_sale.size();k++)
                               {
                                   if (v_sale[k].get_id() == id)
                                   {
                                       for(int l =0;l < v_user.size();l++)
                                       {
                                           if( v_user[l].get_username() == h.get_nu_username() && v_sale[k].get_final_price() <= v_user[l].get_cash())
                                           {
                                               v_user[l].set_cash(v_user[l].get_cash() - v_sale[k].get_final_price());
                                               v_apartment[i].get_v_house_for_apartment()[j].set_state(3);
                                               v_apartment[i].get_v_house_for_apartment()[j].setIsInList(0);
                                               v_user[index_of_current_user].set_cash(  v_user[index_of_current_user].get_cash() + v_sale[k].get_final_price());
                                               l = v_user.size();
                                               k = v_sale.size();
                                               QMessageBox * msg = new QMessageBox;
                                               msg->setText("Sale Done!");
                                               msg->setIcon(QMessageBox::Information);
                                               msg->setWindowTitle("Hoooooraaaaa!");
                                               msg->exec();
                                           }
                                           else if(v_user[l].get_username() == h.get_nu_username() && v_sale[k].get_final_price() > v_user[l].get_cash())
                                           {
                                               QMessageBox * msg = new QMessageBox;
                                               msg->setText("Not enough money!");
                                               msg->setIcon(QMessageBox::Information);
                                               msg->setWindowTitle("ERROR!");
                                               msg->exec();
                                           }
                                       }
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
                       if ( v_northVilla[i].get_state() == 1 && v_northVilla[i].getIsInList() == 1)
                       {
                           for(int j=0; j< v_rent.size();j++)
                           {
                               for(int k =0; k< v_user.size();k++)
                               {
                                   if( id == v_rent[j].get_id() && v_northVilla[i].get_nu_username() == v_user[k].get_username()  && v_user[k].get_cash() >= v_rent[j].get_final_price() )
                                   {
                                       v_northVilla[i].set_state(3);
                                       v_user[k].set_cash(v_user[k].get_cash() - v_rent[j].get_final_price());
                                       v_user[index_of_current_user].set_cash(v_user[index_of_current_user].get_cash() + v_rent[j].get_final_price());
                                       k = v_user.size();
                                       j = v_rent.size();
                                       QMessageBox * msg = new QMessageBox;
                                       msg->setText("Rent Done!");
                                       msg->setIcon(QMessageBox::Information);
                                       msg->setWindowTitle("Hoooooraaaaa!");
                                       msg->exec();
                                   }
                                   else if (id == v_rent[j].get_id() && v_northVilla[i].get_nu_username() == v_user[k].get_username() && v_user[k].get_cash() < v_rent[j].get_final_price() )
                                   {
                                       QMessageBox * msg = new QMessageBox;
                                       msg->setText("Not enough money!");
                                       msg->setIcon(QMessageBox::Information);
                                       msg->setWindowTitle("ERROR!");
                                       msg->exec();
                                   }
                               }
                           }
                       }
                       else if (v_northVilla[i].get_state() == 2 && v_northVilla[i].getIsInList() == 1)
                       {
                           for(int j=0; j< v_sale.size();j++)
                           {
                               for(int k =0; k< v_user.size();k++)
                               {
                                   if( id == v_sale[j].get_id() && v_northVilla[i].get_nu_username() == v_user[k].get_username()  && v_user[k].get_cash() >= v_sale[j].get_final_price() )
                                   {
                                       v_northVilla[i].set_state(3);
                                       v_user[k].set_cash(v_user[k].get_cash() - v_sale[j].get_final_price());
                                       v_user[index_of_current_user].set_cash(v_user[index_of_current_user].get_cash() + v_sale[j].get_final_price());
                                       k = v_user.size();
                                       j = v_sale.size();
                                       QMessageBox * msg = new QMessageBox;
                                       msg->setText("Sale Done!");
                                       msg->setIcon(QMessageBox::Information);
                                       msg->setWindowTitle("Hoooooraaaaa!");
                                       msg->exec();
                                   }
                                   else if (id == v_sale[j].get_id() && v_northVilla[i].get_nu_username() == v_user[k].get_username() && v_user[k].get_cash() < v_sale[j].get_final_price() )
                                   {
                                       QMessageBox * msg = new QMessageBox;
                                       msg->setText("Not enough money!");
                                       msg->setIcon(QMessageBox::Information);
                                       msg->setWindowTitle("ERROR!");
                                       msg->exec();
                                   }
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
                       if ( v_southVilla[i].get_state() == 1 && v_southVilla[i].getIsInList() == 1)
                       {
                           for(int j=0; j< v_rent.size();j++)
                           {
                               for(int k =0; k< v_user.size();k++)
                               {
                                   if( id == v_rent[j].get_id() && v_southVilla[i].get_nu_username() == v_user[k].get_username()  && v_user[k].get_cash() >= v_rent[j].get_final_price() )
                                   {
                                       v_southVilla[i].set_state(3);
                                       v_user[k].set_cash(v_user[k].get_cash() - v_rent[j].get_final_price());
                                       v_user[index_of_current_user].set_cash(v_user[index_of_current_user].get_cash() + v_rent[j].get_final_price());
                                       k = v_user.size();
                                       j = v_rent.size();
                                       QMessageBox * msg = new QMessageBox;
                                       msg->setText("Rent Done!");
                                       msg->setIcon(QMessageBox::Information);
                                       msg->setWindowTitle("Hoooooraaaaa!");
                                       msg->exec();
                                   }
                                   else if (id == v_rent[j].get_id() && v_southVilla[i].get_nu_username() == v_user[k].get_username() && v_user[k].get_cash() < v_rent[j].get_final_price() )
                                   {
                                       QMessageBox * msg = new QMessageBox;
                                       msg->setText("Not enough money!");
                                       msg->setIcon(QMessageBox::Information);
                                       msg->setWindowTitle("ERROR!");
                                       msg->exec();
                                   }
                               }
                           }
                       }
                       else if (v_southVilla[i].get_state() == 2 && v_southVilla[i].getIsInList() == 1)
                       {
                           for(int j=0; j< v_sale.size();j++)
                           {
                               for(int k =0; k< v_user.size();k++)
                               {
                                   if( id == v_sale[j].get_id() && v_southVilla[i].get_nu_username() == v_user[k].get_username()  && v_user[k].get_cash() >= v_sale[j].get_final_price() )
                                   {
                                       v_southVilla[i].set_state(3);
                                       v_user[k].set_cash(v_user[k].get_cash() - v_sale[j].get_final_price());
                                       v_user[index_of_current_user].set_cash(v_user[index_of_current_user].get_cash() + v_sale[j].get_final_price());
                                       k = v_user.size();
                                       j = v_sale.size();
                                       QMessageBox * msg = new QMessageBox;
                                       msg->setText("Sale Done!");
                                       msg->setIcon(QMessageBox::Information);
                                       msg->setWindowTitle("Hoooooraaaaa!");
                                       msg->exec();
                                   }
                                   else if (id == v_sale[j].get_id() && v_southVilla[i].get_nu_username() == v_user[k].get_username() && v_user[k].get_cash() < v_sale[j].get_final_price() )
                                   {
                                       QMessageBox * msg = new QMessageBox;
                                       msg->setText("Not enough money!");
                                       msg->setIcon(QMessageBox::Information);
                                       msg->setWindowTitle("ERROR!");
                                       msg->exec();
                                   }
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
                       i = v_southVilla.size();
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
       else
       {
           QMessageBox * msg = new QMessageBox;
           msg->setText("Please Enter ID!");
           msg->setIcon(QMessageBox::Information);
           msg->setWindowTitle("ERROR!");
           msg->exec();
       }
       end();
}
