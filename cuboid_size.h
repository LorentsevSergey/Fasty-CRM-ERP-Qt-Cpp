#pragma once
#include "user.h"

typedef cuboid_size c_s;
typedef cuboid_size& cs;
typedef const cuboid_size& ccs;

class cuboid_size : public base_unit
{
	ush length	{ 0 },//довжина у см
		width	{ 0 },//ширина у см
		height	{ 0 };//висота у см

public:
	cuboid_size() {}
	cuboid_size(ccs copy);
	cuboid_size(ush length, ush width, ush height);

	//скоп≥ювати розм≥ри з об'Їкту (update ≥н≥ц≥юЇ оновленн€ у вс≥х залежних об'Їкт≥в)
	bool set(ccs copy);
	//встановити розм≥ри ƒхЎх¬ (update ≥н≥ц≥юЇ оновленн€ у вс≥х залежних об'Їкт≥в)
	bool set(ush length, ush width, ush height);

	ush get_length() const;	//отримати довжину
	ush get_width()  const;	//отримати ширину
	ush get_height() const;	//отримати висоту
	ush get_volume() const;	//отримати куб≥чний об'Їм

	operator bool() const;

	bool operator== (ccs) const;
	bool operator!= (ccs) const;
	bool operator<= (ccs) const;
	bool operator>= (ccs) const;
	bool operator<  (ccs) const;
	bool operator>  (ccs) const;

	ush operator/  (ccs) const;
	cs  operator=  (ccs);
	cs  operator+= (ccs);
	cs  operator-= (ccs);
	c_s operator+  (ccs)	  const;
	c_s operator+  (ush) const;
	c_s operator-  (ccs)	  const;
	c_s operator-  (ush) const;
	//c_s operator-  (short val) const;
	cs  operator++ ();
	c_s operator++ (int value);
	cs  operator-- ();
	c_s operator-- (int value);

private:
	//к≥льк≥сть об'Їм≥в, що вм≥щуютьс€ у наш розм≥р зг≥дно пор€дку аргумент≥в
	ush _vol_count(ush x, ush y, ush z) const;
	void _get_update_from(const base_unit*) override {};
	friend ostream& operator<< (ostream&, ccs);
};