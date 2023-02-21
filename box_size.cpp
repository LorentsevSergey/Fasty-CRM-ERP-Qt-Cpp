#pragma once
#include "box_size.h"

box_size::box_size(cbs copy)
{
	set(copy.out, copy.in);
}
box_size::box_size(ccs out, ccs in)
{
	set(dict.cs.add(out, this), dict.cs.add(in, this));
}
box_size::box_size(ccs out, ush th)
{
	set(dict.cs.add(out, this), dict.cs.add(out-th, this));
}

//box_size::~box_size()
//{
//	get_out().will_not_send_upds_to(this);
//	get_in().will_not_send_upds_to(this);
//}

bool box_size::set(cbs bs)
{
	return set(bs.out, bs.in);
}
bool box_size::set(ind i_out, ind i_in)
{
	try
	{
		if ((in == i_in && out == i_out) ||
			in >= dict.cs.size() || out >= dict.cs.size() ||
			dict.cs.at(i_in) >= dict.cs.at(i_out))
			return false;

		get_out().will_not_send_upds_to(this);
		get_in().will_not_send_upds_to(this);

		out = i_out;
		in = i_in;

		get_out().will_send_upds_to(this);
		get_in().will_send_upds_to(this);

		my_data_is_updated();
		return true;
	}
	catch (cex ex)
	{
		error("box_size::set()", ex);
		return false;
	}
}
//bool box_size::set_in (ccs in)
//{
//	return set(get_out(), in);
//}
//bool box_size::set_out(ccs out)
//{
//	return set(out, get_in());
//}

cs	box_size::get_in()		const
{
	return dict.cs.at(in);
}
cs	box_size::get_out()		const
{
	return dict.cs.at(out);
}
ush	box_size::get_vol_in()	const
{
	return get_in().get_volume();
}
ush	box_size::get_vol_out()	const
{
	return get_out().get_volume();
}

box_size::operator bool() const
{
	return get_in() || get_out();
}

bool box_size::operator==(cbs val)	const
{
	return in == val.in && out == val.out;
}
bool box_size::operator!=(cbs val)	const
{
	return !operator==(val);;
}

bool box_size::operator<=(cbs val)	const
{
	return get_in() <= val.get_in() && get_out() <= val.get_out();
}
bool box_size::operator>=(cbs val)	const
{
	return get_in() >= val.get_in() && get_out() >= val.get_out();
}
bool box_size::operator< (cbs val)	const
{
	return get_in() < val.get_in() && get_out() < val.get_out();
}
bool box_size::operator> (cbs val)	const
{
	return get_in() > val.get_in() && get_out() > val.get_out();
}

bs  box_size::operator= (cbs copy)
{
	set(copy.out, copy.in);
	return *this;
}

void box_size::_get_update_from(const base_unit* what_i_link_to)
{
	try
	{
		//if (what_i_link_to == &get_in())
		//{
		//	//cout << "\nОновили дані у box_size::in за адресою:\t" << what_i_link_to << "\n\n";
		//}
		//else if (what_i_link_to == &get_out())
		//{
		//	//cout << "\nОновили дані у box_size::out за адресою:\t" << what_i_link_to << "\n\n";
		//}
		my_data_is_updated();
	}
	catch (cex ex)
	{
		error("box_size::get_update_from()", ex);
	}
}

//bs  box_size::operator+=(cbs val)
//{
//	set(out + val.out, in + val.in);
//	return *this;
//}
//bs  box_size::operator-=(cbs val)
//{
//	set(out - val.out, in - val.in);
//	return *this;
//}
//b_s box_size::operator+ (cbs val)	const
//{
//	return { out + val.out, in + val.in };
//}
//b_s box_size::operator- (cbs val)	const
//{
//	return { out - val.out, in - val.in };
//}

ostream& operator<<(ostream& os, cbs val)
{
	return os << "out: " << val.get_out() << "  in: " << val.get_in();
}
