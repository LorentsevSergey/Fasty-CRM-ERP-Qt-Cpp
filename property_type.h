#pragma once
//#include "base_unit.h"
#include "dictionary.h"
class Property;

class property_type : public base_unit
{
public:
	enum val_t {
		WRONG_TYPE = 0,
		STR = 1,
		INT = 2,
		DBL = 3,
		BOOL = 4,
		LIST = 5
	};
	
private:
	static const char property_type_maxcount{ 5 };

	string name{ "noname" };
	string description{"no description"};


	val_t type{ STR };

	//list of values for case type==LIST; Property will save index from vector
	vector<string> val_list;

	bool multiply{ false };

public:
	property_type() {}
	property_type(char id);

	string	get_name()						const { return name; }
	string	get_description()				const { return description; }
	val_t	get_type()						const;
	const vector<string>& get_val_list()	const;
	bool	is_multiply()					const { return multiply; }
	
	void set_name(string new_name);
	void set_description(string new_description);
	void set_type(char id);
	void set_val_list(const vector<string>& v);
	bool set_val_list(const string& s);
	void set_multiply(bool val);

	bool operator==(const property_type& val);
	bool operator!=(const property_type& val);
	//bool operator>=(const property_type& val);
	//bool operator<=(const property_type& val);

private:
	//Отримання даних з об`екту, на котрий я посилаюсь
	void _get_update_from(const base_unit*) override;

	friend bool operator==(const property_type& lval, const property_type& rval);
};

