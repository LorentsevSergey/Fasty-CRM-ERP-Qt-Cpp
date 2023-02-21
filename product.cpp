#pragma once
#include "product.h"

product::product(const product& copy) : 
    s_prod_part  { copy.s_prod_part },
    prod_size    { copy.prod_size },
    brutto_weight{ copy.brutto_weight } {}

bool product::add_product_part(base_unit* prod_part)
{
    if (!prod_part) return false;

    bool res = s_prod_part.insert(prod_part).second;
    if(res) my_data_is_updated();

    return res;
}

const set <base_unit*>& product::get_product_parts() const
{
    return s_prod_part;
}

bool product::del_product_part(base_unit* prod_part)
{
    if (!prod_part) return false;

    bool res = s_prod_part.erase(prod_part);
    if(res) my_data_is_updated();

    return res;
}

bool product::set_size(const cuboid_size& new_prod_size)
{
    try
    {
        //не можна змінювати розмір продукту після додавання партії або якщо він дорівнює аргументу
        if (s_prod_part.size() || prod_size == new_prod_size)
            return false;

        prod_size = new_prod_size;
        my_data_is_updated();

        return true;
    }
    catch (const exception& ex)
    {
        bug_report("product::set_size()", ex);
    }
    return false;
}

const cuboid_size& product::get_size() const
{
    return prod_size;
}

void product::set_brutto_weight(ush new_brutto_weight)
{
    brutto_weight = new_brutto_weight;
    my_data_is_updated();
}

ush product::get_brutto_weight()
{
    return brutto_weight;
}

void product::_get_update_from(const base_unit* what_i_link_to)
{
    try
    {
        //for (auto it : s_prod_part)
        //    if (what_i_link_to == it)
        //    {
        //        //cout << "\nОновили дані у product.s_prod_part за адресою:\t" << it << "\n\n";
        //    }
        my_data_is_updated();
    }
    catch (cex ex)
    {
        error("product::get_update_from()", ex);
    }
}

ostream& operator<<(ostream& os, const product& p)
{
    return os << "product size: " << p.prod_size << "\tbrutto weight: " << p.brutto_weight << endl <<
        "parts count: " << p.s_prod_part.size() << " part(s)";
}
