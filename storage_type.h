#pragma once
#include "box_size.h"

typedef storage_type& st;
typedef const storage_type& cst;

class storage_type : public base_unit
{
	inline static const char* std_name{ "noname_type" };
	//string		name		{ std_name };//назва типу сховища
	ind		boxsize_i		{ 0 };	//розміри сховища
	ush		weight			{ 0 };	//вага сховища
	uint	max_net_weight	{ 0 };	//максимальна місткість сховища у кг

public:
	storage_type();
	storage_type(cbs boxsize, ush weight, ush max_net_weight);

	bool set_size(ind boxsize_ind);
	bool set_size(cbs size);
	bool set_weight(ush storage_weight);
	bool set_max_net_weight(ush max_net_weight);

	string	get_name()				const;
	cbs		get_size()				const;
	bs		get_size();				//отримати посилання на розмір для його зміни
	ush		get_weight()			const;
	uint	get_max_net_weight()	const;

	operator bool() const;

	bool operator == (cst) const;
	bool operator != (cst) const;
	bool operator <= (cst) const;
	bool operator >= (cst) const;
	bool operator <  (cst) const;
	bool operator >  (cst) const;

	st operator =  (cst);
	st operator += (cst);
	st operator -= (cst);
	/*storage_type  operator +  (const storage_type&) const;
	storage_type  operator -  (const storage_type&) const;*/

private:
	//void create_name();
	virtual void _get_update_from(const base_unit*) override;
	friend ostream& operator<< (ostream&, cst);
};
