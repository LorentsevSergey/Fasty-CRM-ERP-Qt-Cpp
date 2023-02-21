#pragma once
#include "storage.h"

storage::storage(cstr n, ind i) : name(n), type_ind(i)
{
    try
    {
        if(i) my_type().will_send_upds_to(this);
    }
    catch (cex ex)
    {
        error("storage::storage()", ex);
    }
}
//зберігає тип сховища у словнику, прив'язує сповіщення оновлень та зберігає індекс типу
storage::storage(cstr n, cst st) : name{ n }
{
    try
    {
        type_ind = dict.st.add(st, this);
    }
    catch (cex ex)
    {
        error("storage::storage()", ex);
    }
}

bool storage::set_name(cstr n)
{
    try
    {
        if (name == n) return false;

        name = n;
        my_data_is_updated();
        return true;
    }
    catch (cex ex)
    {
        error("storage::set_name()", ex);
    }
    return false;
}
bool storage::set_type(ind i)           
{
    try
    {
        if (!i || type_ind == i)
            return false;

        if (type_ind)
            my_type().will_not_send_upds_to(this);

        type_ind = i;
        my_type().will_send_upds_to(this);

        my_data_is_updated();
        return true;
    }
    catch (cex ex)
    {
        error("storage::set_type()", ex);
    }
    return false;
}
bool storage::set_type(cst st)
{
    try
    {
        return set_type(dict.st.add(st));
    }
    catch (cex ex)
    {
        error("storage::set_type()", ex);
    }
    return false;
}

cstr   storage::get_name() const
{
    return name;
}
string storage::get_full_name() const
{
    return name + ' ' + my_type().get_name();
}

cbs storage::get_size()
{
    return my_type().get_size();
}
ush storage::get_weight()
{
    return my_type().get_weight();
}
ush storage::get_max_net_weight()
{
    return my_type().get_max_net_weight();
}

st  storage::my_type()
{
    return dict.st.at(type_ind);
}
cst storage::my_type()      const
{
    return dict.st.at(type_ind);
}
//st  storage::my_type(ind i)
//{
//    return dict.st.at(i);
//}
//cst storage::my_type(ind i) const
//{
//    return dict.st.at(i);
//}

void storage::_get_update_from(const base_unit* what_i_link_to)
{
    try
    {
        //if (what_i_link_to == &my_type())
        //{
        //    //cout << "\nSTORAGE - " << get_name() << " - type updated!\n" << my_type() << endl;
        //}
        my_data_is_updated();
    }
    catch (cex ex)
    {
        error("storage::get_update_from()", ex);
    }
}

storage::operator bool() const
{
    return name != std_name || my_type();
}

bool storage::operator==(cstorage val) const
{
    return name      == val.name
        && my_type() == val.my_type();
}
bool storage::operator!=(cstorage val) const
{
    return !operator==(val);
}
bool storage::operator<=(cstorage val) const
{
    return my_type() <= val.my_type();
}
bool storage::operator>=(cstorage val) const
{
    return my_type() >= val.my_type();
}
bool storage::operator< (cstorage val) const
{
    return my_type() < val.my_type();
}
bool storage::operator> (cstorage val) const
{
    return my_type() > val.my_type();
}

storage& storage::operator=(cstorage copy)
{
    name = copy.name;
    set_type(copy.type_ind);
    return *this;
}

ostream& operator<< (ostream& os, cstorage s)
{
    return os 
        << "Storage full name: "    << s.get_full_name() 
        << "\nStorage name: "               << s.name 
        << "\nType index: "         << s.type_ind
        << endl                     << s.my_type();
}