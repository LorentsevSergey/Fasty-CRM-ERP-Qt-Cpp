#pragma once
#include "Property.h"

class product_type : public base_unit
{
    vector<Property> prop;
public:
    product_type() {}

private:
    //Отримання даних з об`екту, на котрий я посилаюсь
    void _get_update_from(const base_unit*) override;
};

