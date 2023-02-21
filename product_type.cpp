#include "product_type.h"

void product_type::_get_update_from(const base_unit* what_i_link_to)
{
    try
    {
        
        my_data_is_updated();
    }
    catch (cex ex)
    {
        error("product_type::_get_update_from()", ex);
    }
}