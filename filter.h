#pragma once
#include "global_includes.h"
typedef uint ind;
typedef const ind& cind;

template<typename T>
class filter
{
	inline static ush res_p_p{ 20 };	//count of results per page for all class
	ush res_p_page{ res_p_p };			//count of results per page for that filter
	ind start{ 0 };						//start index for searching

	bool f{ false }, ex{ false };		//trigger on/off
	T f_min, f_max, ex_min, ex_max;		//[min-max] positions for filtering & excepting

public:
	filter() {}
	//filter for check value in [fmin, fmax] range
	filter(const T& fmin, const T& fmax)
	{
		set_filter(fmin, fmax);
	}
	//filter for check value in [fmin, fmax] range, except [exmin, exmax] range
	filter(const T& fmin, const T& fmax, const T& exmin, const T& exmax) : filter(fmin, fmax)
	{
		set_except(exmin, exmax);
	}
	//make a copy of filter
	filter(const filter& copy)
	{
		*this = copy;
	}

	void set_res_p_page(ush count)
	{
		if(count) res_p_page = count;
	}
	//вмикаємо та зберігаємо фільтр по мін/макс значенням
	void set_filter(const T& fmin, const T& fmax)
	{
		f = true;
		f_min = fmin;
		f_max = fmax;
	}
	//вмикаємо та зберігаємо виключення по мін/макс значенням
	void set_except(const T& exmin, const T& exmax)
	{
		ex = true;
		ex_min = exmin;
		ex_max = exmax;
	}
	//set last index from last searching (to start next iteration of search)
	void set_start_ind(ind i)
	{
		start = i;
	}

	ush		get_res_p_page()		const
	{
		return res_p_p;
	}
	bool	check(const T& val) const
	{
		try
		{
			if (f && ex) 
				return f_min <= val && val <= f_max 
				&& !(ex_min <= val && val <= ex_max);

			if (f) 
				return f_min <= val && val <= f_max;

			if (ex)
				return !(ex_min <= val && val <= ex_max);
		}
		catch (cex ex)
		{
			error("filter::check()", ex);
		}
		return false;
	}
	ind		get_start_ind()		const
	{
		return start;
	}

	operator bool() { return f || ex; }

	filter& operator = (pair<const T&, const T&> p)
	{
		try
		{
			f = true;
			f_min = p.first();
			f_max = p.second();
		}
		catch (cex ex)
		{
			error("filter::operator=", ex);
		}
		return *this;
	}
	filter& operator = (const filter& copy)
	{
		try
		{
			res_p_page = copy.res_p_page;
			start = 0;

			f = copy.f;
			f_min = copy.f_min;
			f_max = copy.f_max;

			ex = copy.ex;
			ex_min = copy.ex_min;
			ex_max = copy.ex_max;
		}
		catch (cex ex)
		{
			error("filter::operator=", ex);
		}
		return *this;
	}

private:
	friend ostream& operator<< (ostream& os, const filter& f)
	{
		return os
			<< "Filter on: " << f.f << "\n\nmin:\n" << f.f_min << "\n\nmax:\n" << f.f_max << "\n\n"
			<< "Except on: " << f.ex << "\n\nmin:\n" << f.ex_min << "\n\nmax:\n" << f.ex_max << "\n\n";
	}
};