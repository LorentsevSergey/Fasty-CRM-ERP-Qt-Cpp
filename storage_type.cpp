#pragma once
#include "storage_type.h"

storage_type::storage_type()
{
    //create_name();
}
storage_type::storage_type(cbs b_s, ush w, ush max_n_w) :
    boxsize_i       ( dict.bs.add(b_s) ),
    weight          ( w ),
    max_net_weight  ( max_n_w )
{
    //create_name();
};

bool storage_type::set_size(ind i)
{
    try
    {
        //if (!state.changing()) return false;

        if (i == boxsize_i || i >= dict.bs.size())
            return false;

        get_size().will_not_send_upds_to(this);
        boxsize_i = i;
        get_size().will_send_upds_to(this);

        //create_name();

        my_data_is_updated();
        return true;
    }
    catch (cex ex)
    {
        error("storage_type::set_size()", ex);
        return false;
    }
}
bool storage_type::set_size(cbs s)
{
    try
    {
        return set_size(dict.bs.add(s));
    }
    catch (cex ex)
    {
        error("storage_type::set_size()", ex);
        return false;
    }
}
bool storage_type::set_weight(ush w)
{
    try
    {
        if (weight == w) return false;

        weight = w;
        //create_name();

        my_data_is_updated();
        return true;
    }
    catch (cex ex)
    {
        error("storage_type::set_weight()", ex);
        return false;
    }
}
bool storage_type::set_max_net_weight(ush w)
{
    try
    {
        if (max_net_weight == w) return false;

        max_net_weight = w;

        my_data_is_updated();
        return true;
    }
    catch (cex ex)
    {
        error("storage_type::set_max_net_weight()", ex);
        return false;
    }
}

string  storage_type::get_name()            const
{
    try
    {
        return itos(get_weight()) + " kg, " +
            itos(get_size().get_out().get_length()) + '*' +
            itos(get_size().get_out().get_width()) + '*' +
            itos(get_size().get_out().get_height());
    }
    catch (cex ex)
    {
        error("storage_type::get_name()", ex);
        return std_name;
    }
}
cbs     storage_type::get_size()            const
{
    return dict.bs.at(boxsize_i);
}
bs      storage_type::get_size()
{
    return dict.bs.at(boxsize_i);
}
ush     storage_type::get_weight()          const
{
    return weight;
}
uint    storage_type::get_max_net_weight()  const
{
    return max_net_weight;
}

storage_type::operator bool() const
{
    try
    {
        return /*name != std_name 
            ||*/ get_size()
            || weight 
            || max_net_weight;
    }
    catch (cex ex)
    {
        error("storage_type::operator bool()", ex);
        return false;
    }
}

bool storage_type::operator==(cst val) const
{
    try
    {
        return get_size()       == val.get_size()
            && weight           == val.weight
            && max_net_weight   == val.max_net_weight;
    }
    catch (cex ex)
    {
        error("storage_type::operator==()", ex);
        return false;
    }
}
bool storage_type::operator!=(cst val) const
{
    return !operator==(val);
}
bool storage_type::operator<=(cst val) const
{
    try
    {
        return get_size()       <= val.get_size()
            && weight           <= val.weight
            && max_net_weight   <= val.max_net_weight;
    }
    catch (cex ex)
    {
        error("storage_type::operator<=()", ex);
        return false;
    }
}
bool storage_type::operator>=(cst val) const
{
    try
    {
        return get_size()       >= val.get_size()
            && weight           >= val.weight
            && max_net_weight   >= val.max_net_weight;
    }
    catch (cex ex)
    {
        error("storage_type::operator>=()", ex);
        return false;
    }
}
bool storage_type::operator< (cst val) const
{
    try
    {
        return get_size()       < val.get_size()
            && weight           < val.weight
            && max_net_weight   < val.max_net_weight;
    }
    catch (cex ex)
    {
        error("storage_type::operator<()", ex);
        return false;
    }
}
bool storage_type::operator> (cst val) const
{
    try
    {
        return get_size()       > val.get_size()
            && weight           > val.weight
            && max_net_weight   > val.max_net_weight;
    }
    catch (cex ex)
    {
        error("storage_type::operator>()", ex);
        return false;
    }
}

st storage_type::operator= (cst val)
{
    try
    {
        weight          = val.weight;
        max_net_weight  = val.max_net_weight;
        set_size(val.boxsize_i);
    }
    catch (cex ex)
    {
        error("storage_type::operator=()", ex);
    }
    return *this;
}
st storage_type::operator+=(cst val)
{
    try
    {
        weight          += val.weight;
        max_net_weight  += val.max_net_weight;
        set_size( get_size() + val.get_size() );
    }
    catch (cex ex)
    {
        error("storage_type::operator+=()", ex);
    }
    return *this;
}
st storage_type::operator-=(cst val)
{
    try
    {
        weight          -= val.weight;
        max_net_weight  -= val.max_net_weight;
        set_size( get_size() - val.get_size() );
    }
    catch (cex ex)
    {
        error("storage_type::operator-=()", ex);
    }
    return *this;
}
//storage_type  storage_type::operator+ (const storage_type& val) const
//{
//    return{ name,
//            get_size()      + val.get_size(),
//            weight          + val.weight,
//            max_net_weight  + val.max_net_weight };
//}
//storage_type  storage_type::operator- (const storage_type& val) const
//{
//    return{ name,
//            get_size()      - val.get_size(),
//            weight          - val.weight,
//            max_net_weight  - val.max_net_weight };
//}

void storage_type::_get_update_from(const base_unit* what_i_link_to)
{
    try
    {
        //if (what_i_link_to == &get_size())
        //{
        //    //cout << "\nSTORAGE TYPE - " << get_name() << "\nbox size is updated!" << endl;
        //}
        my_data_is_updated();
    }
    catch (cex ex)
    {
        error("storage::get_update_from()", ex);
    }
}

//void storage_type::create_name()
//{
//    try
//    {
//        name = itos(get_weight()) + " kg, " +
//            itos(get_size().get_outside().get_length()) + '*' + 
//            itos(get_size().get_outside().get_width()) + '*' +
//            itos(get_size().get_outside().get_height());
//    }
//    catch (cex ex)
//    {
//        error("storage_type::create_name()", ex);
//    }
//}
ostream& operator<< (ostream& os, cst st)
{
    try
    {
        return os 
            << "Storage type name: "    << st.get_name()
            << "\t\tsize "              << st.get_size()
            << "\nweight: "             << st.weight 
            << "\t\tmax_net_weight: "   << st.max_net_weight;
    }
    catch (cex ex)
    {
        error("storage_type::operator<<()", ex);
        return os;
    }
}