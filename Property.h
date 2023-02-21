#pragma once
#include "property_type.h"

union union_val
{
	char	STR[32];
	int		INT;
	double	DBL;
	bool	BOOL;
	int		VAL_ID;
};

class Property : public base_unit
{
	ush prop_t_id{ 0 };	//index of property type in dictionary
	vector<union_val> v;

public:
	Property();
	Property(const property_type& type);
	Property(const ush type_id);
	Property(const Property& p);

	queue<string>			get()			const;
	const vector<string>&	get_val_list()	const;
	property_type&			my_type()		const;
	
	bool set(const string& val);
	void set_val_from_list(const ush& val_id);
	bool set_val_from_list(const string& val);


	bool operator==(const Property& val) const { return prop_t_id == val.prop_t_id /*&& v == val.v*/; }

private:
	/*friend bool operator==(const string& lval,			const Property& rval)	{ return lval == rval.STR; }
	friend bool operator==(const int& lval,				const Property& rval)	{ return lval == rval.INT; }
	friend bool operator==(const double& lval,			const Property& rval)	{ return lval == rval.DBL; }
	friend bool operator==(const bool& lval,			const Property& rval)	{ return lval == rval.BOOL; }
	friend bool operator==(const vector<char*> lval,	const Property& rval);*/

	//Отримання даних з об`екту, на котрий я посилаюсь
	void _get_update_from(const base_unit*) override;
};

