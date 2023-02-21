#pragma once
#include "cuboid_size.h"

typedef box_size b_s;
typedef box_size& bs;
typedef const box_size& cbs;

class box_size : public base_unit
{
	ind in{ 0 }, out{ 0 };

public:
	box_size() {}
	box_size(cbs);
	box_size(ccs out, ccs in);
	box_size(ccs out, ush thickness = 1);

	bool set(cbs);
	bool set(ind out, ind in);
	//bool set_in(ccs in);
	//bool set_out(ccs out);

	cs  get_in()		const;
	cs  get_out()		const;
	ush get_vol_in()	const;
	ush get_vol_out()	const;

	operator bool () const;

	bool operator == (cbs) const;
	bool operator != (cbs) const;
	bool operator <= (cbs) const;
	bool operator >= (cbs) const;
	bool operator <  (cbs) const;
	bool operator >  (cbs) const;

	bs   operator =  (cbs);
	//bs   operator += (cbs);
	//bs   operator -= (cbs);
	//b_s  operator +  (cbs) const;
	//b_s  operator -  (cbs) const;

private:
	virtual void _get_update_from(const base_unit*) override;
	friend ostream& operator<<(ostream&, cbs);
	//~box_size();
};

