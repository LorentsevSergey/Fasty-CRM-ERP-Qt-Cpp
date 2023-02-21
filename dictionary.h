#pragma once
#include "collect.h"
class cuboid_size;
class box_size;
class storage_type;
class storage;

class property_type;

class product_type;
class product;
class product_part;

class user;

struct dictionary
{
    collect<cuboid_size>    cs; //cuboid size
    collect<box_size>       bs; //box size
    collect<storage_type>   st; //storage type
    collect<storage>        s;  //storage

    collect<property_type>  prop_t; //property_type

    collect<product_type>   pt; //product_type
    collect<product>        p;  //product
    collect<product_part>   pp; //product_part

    collect<user>           u;  //user
};

extern dictionary dict;