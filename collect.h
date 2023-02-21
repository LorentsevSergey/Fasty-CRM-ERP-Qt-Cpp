#pragma once
//#include <list>
//#include <algorithm>
#include "base_unit.h"
#include "filter.h"

template<typename T>
class collect : private vector<T>
{
	typedef const T& cT;
	typedef vector<T> v;
	typedef collect<T> col;
	typedef const col ccol;
	typedef filter<T> flt;
	typedef const flt cflt;

public:
	collect(bool is_empty = false);
	//переміщує об'єкти з черги до колекції (копіюючі їх)
	collect(queue<T>& copy);

    ind add(cT copy);
	ind add(cT copy, base_unit* what_links_to_copy);
	ind fnd(cT val) const;
	collect<T*> filter(flt& f) ;
	uint size() const;

	T& at(ind i);
	const T& at(ind i) const;
	bool operator == (const col& c) const;

private:
	friend ostream& operator<< (ostream& os, const col& c)
	{
		os << endl << "Collection size = " << c.size() << "\n\n";
		for (size_t i = 0; i < c.size(); ++i)
			os << "# " << i << endl << c[i] << "\n\n";
		os << "\n\n";
		return os;
	};
};

template<typename T>
inline collect<T>::collect(bool is_empty)
{
	if (!is_empty)
	{
		v::push_back(T());
		//?????? v::front().state.
	}
}
template<typename T>
inline collect<T>::collect(queue<T>& copy)
{
	v::resize(copy.size());
	for (size_t i = 0; i < v::size(); ++i)
	{
		v::operator[](i) = copy.front();
		copy.pop();
	}
}

template<typename T>
ind collect<T>::add(cT copy)
{
	try
	{
		ind i;
		auto it = find(v::begin(), v::end(), copy);

		if (it == v::end())
		{
			v::push_back(copy);
			i = size() - 1;
		}
		else
			i = ind(it - v::begin());

		return i;
	}
	catch (cex ex)
	{
		error("collect<T>::add()", ex);
		return 0;
	}
}
template<typename T>
ind collect<T>::add(cT copy, base_unit* p)
{
	try
	{
		ind i = add(copy);
		if (i) at(i).will_send_upds_to(p);
		return i;
	}
	catch (cex ex)
	{
		error("collect<T>::add()", ex);
		return 0;
	}
}

template<typename T>
ind collect<T>::fnd(cT val) const
{
	try
	{
		auto it = find(v::begin(), v::end(), val);
		return (it == v::end()) ? 0 : (it - v::begin());
	}
	catch (cex ex)
	{
		error("collect<T>::fnd()", ex);
		return 0;
	}
}

template<typename T>
collect<T*> collect<T>::filter(flt& f)
{
	queue<T*> res;
	try
	{
		ind i = f.get_start_ind();		//next of the last index from last search (or 0 if it`s new search)
		size_t t = f.get_res_p_page();	//count of results per page

		for (; i < size() && t; ++i, --t)
			if (f.check(v::operator[](i)))
				res.push(&(v::operator[](i)));

		f.set_start_ind(res.size() ? i : 0);
	}
	catch (cex ex)
	{
		error("collect<T>::filter()", ex);
	}
	return res;
}

template<typename T>
inline uint collect<T>::size() const
{
	return uint(v::size());
}

template<typename T>
T& collect<T>::at(ind i)
{
	return v::at(i);
}
template<typename T>
const T& collect<T>::at(ind i) const
{
	return v::at(i);
}

template<typename T>
bool collect<T>::operator==(const col& c) const
{
	return static_cast<v>(*this) == static_cast<v>(c);
}
