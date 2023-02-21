#pragma once
#include "storage.h"
#include "settings.h"
#include "product_type.h"

class product : public base_unit
{
	set <base_unit*> s_prod_part;		//сховища, в котрих партіями зберігається товар (клас product_part)
	cuboid_size prod_size{ 1, 1, 1 };	//розмір продукту в упаковці
	ush brutto_weight{ 0 };				//вага продукту з упаковкою

public:
	product() {};
	product(const product&);
	
	bool add_product_part(base_unit* prod_part);
	bool set_size(const cuboid_size& prod_size);
	void set_brutto_weight(ush new_brutto_weight);

	const set <base_unit*>& get_product_parts() const;
	const cuboid_size& get_size() const;
	ush get_brutto_weight();

	//видаляє адресу партії продукту, викликається в деструкторі класу product_part
	bool del_product_part(base_unit* prod_part);

private:
	//Отримання даних з об`екту, на котрий я посилаюсь
	void _get_update_from(const base_unit*) override;

	friend ostream& operator<< (ostream&, const product&);
};