#pragma once
#include "storage_type.h"

typedef const storage& cstorage;

class storage : public base_unit
{
	inline static const char* std_name{ "noname_storage" };
	string name{ std_name };//назва сховища
	ind type_ind{ 0 };		//індекс типу сховища, що зберігається у словнику

public:
	storage() {};
	storage(cstr name, ind type_index);
	storage(cstr name, cst st);
	
	bool set_name(cstr name);
	bool set_type(ind type_index);
	bool set_type(cst st);

	cstr	get_name()		const;
	string	get_full_name() const;
	cbs		get_size();
	ush		get_weight();
	ush		get_max_net_weight();

	st	my_type();
	cst my_type() const;
	/*st	my_type(ind i);
	cst my_type(ind i)	const;*/


	operator bool() const;

	bool operator == (cstorage) const;
	bool operator != (cstorage) const;
	bool operator <= (cstorage) const;
	bool operator >= (cstorage) const;
	bool operator <  (cstorage) const;
	bool operator >  (cstorage) const;

	storage& operator = (cstorage);

private:
	virtual void _get_update_from(const base_unit*) override;
	friend ostream& operator<< (ostream&, cstorage);
};

