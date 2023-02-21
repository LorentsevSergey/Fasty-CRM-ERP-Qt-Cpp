#include "Property.h"

Property::Property()
{
    v.resize(1);
}
Property::Property(const property_type& type) : Property()
{
    prop_t_id = dict.prop_t.add(type, this);
}
Property::Property(const ush type_id) : Property()
{
    if (0 < type_id && type_id < dict.prop_t.size())
    {
        prop_t_id = type_id;
        my_type().will_send_upds_to(this);
    }
    else
        error("Property(type_id)", "wrong id - out of range");
}
Property::Property(const Property& p)
{
    prop_t_id = p.prop_t_id;
    v = p.v;
    if(prop_t_id) my_type().will_send_upds_to(this);
}

queue<string> Property::get() const
{
    queue<string> res;
    
    if (!v.size()) res.push("");
    else switch (my_type().get_type())
        {
        case property_type::STR: 
        {
            if (my_type().is_multiply() && v.size() > 1)
                for (size_t i = 0; i < v.size(); ++i)
                    res.push(v[i].STR);
            else
                res.push(v.front().STR);
            break; 
        }
        case property_type::INT: 
        {
            if (my_type().is_multiply() && v.size() > 1)
                for (size_t i = 0; i < v.size(); ++i)
                    res.push(itos(v[i].INT));
            else
                res.push(itos(v.front().INT));
            break; 
        }
        case property_type::DBL: 
        {
            if (my_type().is_multiply() && v.size() > 1)
                for (size_t i = 0; i < v.size(); ++i)
                    res.push(to_string(v[i].DBL));
            else
                res.push(to_string(v.front().DBL));
            break; 
        }
        case property_type::BOOL: 
        {
            if (my_type().is_multiply() && v.size() > 1)
                for (size_t i = 0; i < v.size(); ++i)
                    res.push(itos(v[i].BOOL));
            else
                res.push(itos(v.front().BOOL));
            break; 
        }
        case property_type::LIST: 
        {
            if (my_type().is_multiply() && v.size() > 1)
                for (size_t i = 0; i < v.size(); ++i)
                    res.push(get_val_list()[v[i].VAL_ID]);
            else
                res.push(get_val_list()[v.front().VAL_ID]);
            break; 
        }
        default: 
        {
            error("Property::get()", "wrong property type");
            break; 
        }
        }

    return res;
}

const vector<string>& Property::get_val_list() const
{
    return my_type().get_val_list();
}
property_type& Property::my_type() const
{
    return dict.prop_t.at(prop_t_id);
}

bool Property::set(const string& val)
{
    switch (my_type().get_type())
    {
        case property_type::STR:
        {
            if (my_type().is_multiply())
            {
                if (find_if(v.begin(), v.end(), [&val](const union_val& a) { return a.STR == val; }) != v.end())
                    return false;
                v.resize(v.size() + 1);
                copy(begin(val), end(val), v.back().STR);
            }
            else
            {
                if (val == v.front().STR)
                    return false;
                //якщо будуть помилки при копіюванні нижче, то використовувати цей кінцевий ітератор
                //auto end_it = begin(val) + (val.size() > size(v.front().STR) ? size(v.front().STR) : val.size());
                copy(begin(val), end(val), v.front().STR);
            }
            break;
        }
        case property_type::INT: 
        {
            int value = stoi(val);
            if (my_type().is_multiply())
            {
                if (find_if(v.begin(), v.end(), [&value](const union_val& a) { return a.INT == value; }) != v.end())
                    return false;
                v.resize(v.size() + 1);
                v.back().INT = value;
            }
            else
            {
                if (value == v.front().INT)
                    return false;
                v.front().INT = value;
            }
            break; 
        }
        case property_type::DBL:
        {
            double value = stod(val);
            if (my_type().is_multiply())
            {
                if (find_if(v.begin(), v.end(), [&value](const union_val& a) { return a.DBL == value; }) != v.end())
                    return false;
                v.resize(v.size() + 1);
                v.back().DBL = value;
            }
            else
            {
                if (value == v.front().DBL)
                    return false;
                v.front().DBL = value;
            }
            break;
        }
        case property_type::BOOL:
        {
            bool value = stoi(val);
            if (my_type().is_multiply())
            {
                if (find_if(v.begin(), v.end(), [&value](const union_val& a) { return a.BOOL == value; }) != v.end())
                    return false;
                v.resize(v.size() + 1);
                v.back().BOOL = value;
            }
            else
            {
                if (value == v.front().BOOL)
                    return false;
                v.front().BOOL = value;
            }
            break;
        }
        case property_type::LIST: 
        {
            const vector<string>& val_list = get_val_list();
            if (my_type().is_multiply())//множинне
            {
                if (find_if(v.begin(), v.end(), [&](const union_val& a) { return val_list[a.VAL_ID] == val; }) != v.end())
                    return false;

                v.resize(v.size() + 1);

                auto fnd_res = find(val_list.begin(), val_list.end(), val);
                if (fnd_res == val_list.end()) //якщо не знайшли у списку можливих значень, то додаємо до списку та встановлюємо його id до значень union
                {
                    my_type().set_val_list(val);
                    v.back().VAL_ID = int(get_val_list().size() - 1);
                }
                else //якшо знайшли, то встановлюємо його id до значень union
                    v.back().VAL_ID = int(fnd_res - val_list.begin());
            }
            else//одинарне
            {
                if (val_list[v.front().VAL_ID] == val)
                    return false;

                auto fnd_res = find(val_list.begin(), val_list.end(), val);
                if (fnd_res == val_list.end()) //якщо не знайшли у списку можливих значень, то додаємо до списку та встановлюємо його id до значень union
                {
                    my_type().set_val_list(val);//якщо сетер буде повертати індекс встановленого елементу, то це спростить код і нівелює залежність від контейнеру val_list
                    v.front().VAL_ID = int(get_val_list().size() - 1);
                }
                else //якшо знайшли, то встановлюємо його id до значень union
                    v.front().VAL_ID = int(fnd_res - val_list.begin());
            }
            break;
        }
        default:
        {
            error("Property::set()", "wrong property type");
            return false; 
        }
    }

    my_data_is_updated();
    return true;
}
void Property::set_val_from_list(const ush& val_id)
{
    if (val_id >= get_val_list().size()) return;

    if (!my_type().is_multiply())
        v.front().VAL_ID = val_id;
    else if (find_if(v.begin(), v.end(), [val_id](const union_val& val) { return val.VAL_ID == val_id; }) == v.end())
    {
        v.resize(v.size() + 1);
        v[v.size() - 1].VAL_ID = val_id;
    };

    my_data_is_updated();
}
bool Property::set_val_from_list(const string& val)
{
    auto it = find(get_val_list().begin(), get_val_list().end(), val);
    if ( it == get_val_list().end())
        return false;

    v.front().VAL_ID = ush(it - get_val_list().begin());

    my_data_is_updated();
    return true;
}

void Property::_get_update_from(const base_unit* p)
{
    try
    {
        my_data_is_updated();
    }
    catch (cex ex)
    {
        error("property_value::_get_update_from()", ex);
    }
}

//bool operator==(const vector<char*> lval, const Property& rval)
//{
//    bool res;
//    for (size_t i = 0; i < lval.size(); ++i)
//        for (size_t t = 0; t < rval.v.size(); ++t)
//        {
//            lval == rval.get_val_from_list();
//
//        }
//    return res;
//}
