#include "property_type.h"

property_type::property_type(char id) : type(val_t(id > 0 && id <= property_type_maxcount ? id : 0) ) {}

property_type::val_t property_type::get_type() const
{
    return type;
    /*switch (type)
    {
    case WRONG_TYPE:
        return "WRONG TYPE";
    case STR:
        return "STR";
    case INT:
        return "INT";
    case DBL:
        return "DBL";
    case BOOL:
        return "BOOL";
    case LIST:
        return "LIST";
    default:
        return "WRONG TYPE";
    }*/
}

const vector<string>& property_type::get_val_list() const
{
    if (type != LIST)
        error("property_type::get_val_list()", "wrong type (type != LIST)");
    return val_list;
}

void property_type::set_name(string new_name)
{
    name = new_name;
    my_data_is_updated();
}

void property_type::set_description(string new_description)
{
    description = new_description;
    my_data_is_updated();
}

void property_type::set_type(char id)
{
    if (type == id) return;

    type = val_t(id > 0 && id <= property_type_maxcount ? id : 0);
    my_data_is_updated();
}

void property_type::set_val_list(const vector<string>& v)
{
    if (type != LIST || val_list == v) return;
    
    val_list = v; 
    my_data_is_updated();
}
bool property_type::set_val_list(const string& s)
{
    if (type != LIST || find(val_list.begin(), val_list.end(), s) != val_list.end())
        return false;

    val_list.push_back(s);
    my_data_is_updated();
}

void property_type::set_multiply(bool val)
{
    if (multiply == val) return;

    multiply = val;
    my_data_is_updated();
}

bool property_type::operator==(const property_type& val)
{
    return
        name        == val.name &&
        description == val.description &&
        type        == val.type &&
        multiply    == val.multiply &&
        (type == LIST ? val_list == val.val_list : true) ;
}
bool property_type::operator!=(const property_type& val)
{
    return !operator==(val);
}
//bool property_type::operator>=(const property_type& val)
//{
//    return operator==(val);
//}
//
//bool property_type::operator<=(const property_type& val)
//{
//    return operator==(val);
//}
bool operator==(const property_type& lval, const property_type& rval)
{
    return
        lval.name           == rval.name &&
        lval.description    == rval.description &&
        lval.type           == rval.type &&
        lval.multiply       == rval.multiply &&
        (lval.type == lval.LIST ? lval.val_list == rval.val_list : true);
}

void property_type::_get_update_from(const base_unit* p)
{
    try
    {
        my_data_is_updated();
    }
    catch (cex ex)
    {
        error("property_type::_get_update_from()", ex);
    }
}

