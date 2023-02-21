#pragma once
#include "product_part.h"

product_part::product_part(product& prod, uint count) : p_prod( &prod ), count( count )
{
    try
    {
        p_prod->add_product_part(this);
        p_prod->will_send_upds_to(this);
        _calc_volume();
    }
    catch (cex ex)
    {
        error("product_part::product_part()", ex);
    }
}
product_part::product_part(product& prod, uint count, storage& stor) : product_part(prod, count)
{
    set_storage(stor);
}
product_part::~product_part()
{
    try
    {
        //видаляє свою адресу з продукту, щоб не брати участь у розрахунках залишків
        p_prod->del_product_part(this);

        //видаляє свою адресу з продукту через базовий клас, щоб не надсилались оновлення
        //p_prod->will_not_send_upds_to(this);              //вже видаляється у ~base_unit()
        //if (p_stor) p_stor->will_not_send_upds_to(this);  //вже видаляється у ~base_unit()
    }
    catch (cex ex)
    {
        error("product_part::~product_part()", ex);
    }
}

bool product_part::set_storage(storage& stor)
{
    try
    {
        if (p_stor) return false;

        p_stor = &stor;
        stor.will_send_upds_to(this);
        _calc_net_weight();
        _calc_brutto_weight();
        _calc_max_count();

        my_data_is_updated();
        return true;
    }
    catch (cex ex)
    {
        error("product_part::set_storage()", ex);
        return false;
    }
}
bool product_part::del_storage() //????????????????????????????????
{
    return false;
}

storage& product_part::get_storage()    const
{
    return *p_stor;
}
product& product_part::get_product()    const
{
    return *p_prod;
}

bool product_part::set_count(uint copy)
{
    try
    {
        if (copy > max_count)
            return false;

        count = copy;
        my_data_is_updated();

        return true;
    }
    catch (cex ex)
    {
        error("product_part::set_count()", ex);
        return false;
    }
}
bool product_part::count_plus(const int& val)
{
    try
    {
        if (!val) return false;

        long long res = count + val;
        if (res < 0) res = 0;
        if (res > max_count) res = max_count;
        
        count = uint(res);
        my_data_is_updated();
        return true;
    }
    catch (cex ex)
    {
        error("product_part::count_plus()", ex);
        return false;
    }
}

uint product_part::get_count()          const
{
    return count;
}
uint product_part::get_max_count()      const
{
    return max_count;
}
uint product_part::get_net_weight()     const
{
    return net_weight;
}
uint product_part::get_brutto_weight()  const
{
    return brutto_weight;
}
uint product_part::get_volume()         const
{
    return volume;
}

bool product_part::_calc_max_count()
{
    try
    {
        uint res = p_stor ? p_stor->get_size().get_in() / p_prod->get_size() : 0U;
        if (res < count || res == max_count)
            return false;

        max_count = res;
        my_data_is_updated();
        return true;
    }
    catch (cex ex)
    {
        error("product_part::calc_max_count()", ex);
        return false;
    }
}
bool product_part::_calc_net_weight()
{
    try
    {
        uint res = count * p_prod->get_brutto_weight();
        if (!p_stor || res > p_stor->get_max_net_weight() || res == net_weight)
            return false;

        net_weight = res;
        my_data_is_updated();
        return true;
    }
    catch (cex ex)
    {
        error("product_part::calc_net_weight()", ex);
        return false;
    }
}
bool product_part::_calc_brutto_weight()
{
    try
    {
        if (!p_stor) return false;

        uint res = net_weight + p_stor->get_weight();

        if(brutto_weight == res) return false;

        brutto_weight = res;
        my_data_is_updated();
        return true;
    }
    catch (cex ex)
    {
        error("product_part::calc_brutto_weight()", ex);
        return false;
    }
}
void product_part::_calc_volume()
{
    volume = count * p_prod->get_size().get_volume();
}

void product_part::_get_update_from(const base_unit* what_i_link_to)
{
    try
    {
        if (what_i_link_to == p_stor)
        {
            _calc_max_count();
            _calc_net_weight();
            _calc_brutto_weight();
            //cout << "\nОновили дані у product_part.p_stor:\n" << *p_stor << "\n\n";
        }
        else if (what_i_link_to == p_prod)
        {
            _calc_net_weight();
            _calc_brutto_weight();
            //cout << "\nОновили дані у product_part.p_prod:\n" << *p_prod << "\n\n";
        }
    }
    catch (cex ex)
    {
        error("product_part::get_update_from()", ex);
    }
}

ostream& operator<<(ostream& os, const product_part& p)
{
    os << "\n=== product part ===\n\nproduct:\n" << *p.p_prod << "\n\nstorage: ";

    if (p.p_stor)
        os << "\n" << *p.p_stor;
    else 
        os << "no storage";

    os << "\n\nproduct count in storage: " << p.count << "\tmax capability " << p.max_count <<
        "\npart weight:\tnet " << p.net_weight << "\t\tbrutto " << p.brutto_weight <<
        "\nvolume " << p.volume <<
        "\n==============\n";
    return os;
}
