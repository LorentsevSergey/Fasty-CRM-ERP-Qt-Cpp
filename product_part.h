#pragma once
#include "product.h"

class product_part : public base_unit
{
	product* p_prod;
	storage* p_stor{ nullptr };
	uint count;				//кількість наявного продукту у сховищі
	uint max_count{ 0 };	//Максимальна місткість сховища у одиницях товару
	uint net_weight{ 0 };	//вага наявного продукту у сховищі
	uint brutto_weight{ 0 };//вага наявного продукту разом із сховищем
	uint volume;			//об'єм наявного продуту у сховищі

public:
	//product_part() {}
	product_part(product& = dict.p.at(0), uint count = 0);
	product_part(product&, uint count, storage&);
	~product_part();

	bool set_storage(storage& storage);
	bool del_storage();//????????????????????????????
	storage& get_storage() const;
	product& get_product() const;

	//встановлює кількість продукту, затираючі наявне значення
	bool set_count(uint count);
	//сумує аргумент з кількістю наявного продукту
	bool count_plus(const int& count);
	//повертає наявну кількість продукту
	uint get_count() const;
	//повертає максимально можливу кількість продукту, що поміститься у комірці
	uint get_max_count() const;
	//повертає нетто вагу наявних продуктів у комірці
	uint get_net_weight() const;
	//повертає брутто вагу наявних продуктів з коміркою
	uint get_brutto_weight() const;
	//повертає об'єм партії
	uint get_volume() const;

private:
	bool _calc_max_count();
	bool _calc_net_weight();
	bool _calc_brutto_weight();
	void _calc_volume();

	//отримання даних з об`екту, на котрий я посилаюсь
	void _get_update_from(const base_unit*) override;

	friend ostream& operator<< (ostream&, const product_part&);
};

