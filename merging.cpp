#pragma once
#include "merging.h"

bool merging::merge(merging* copy)
{
	if (!copy || copy == this /*|| same_units_find_in_all(copy)*/) return false;
	try
	{
		merged.insert(copy);
		copy->merged.insert(this);
	}
	catch (cex ex)
	{
		error("merging::merge()", ex);
	}
	return true;
}
bool merging::demerge(merging* copy)
{
	if (!copy) return false;
	bool a, b;
	try
	{
		a = merged.erase(copy);
		b = copy->merged.erase(this);
	}
	catch (cex ex)
	{
		error("merging::demerge()", ex);
	}
	return a || b;
}
void merging::cut_me()
{
	try
	{
		for (auto it : merged)
		{
			if(it != nullptr)
				it->merged.erase(this);
			if(merged.size())
				(*(merged.begin()))->merged.insert(it);
		}
		merged.clear();
	}
	catch (cex ex)
	{
		error("merging::cut_merge()", ex);
	}
}

//bool merging::merged_add(merging* copy)// to delete
//{
//	return merged.insert(copy).second;
//}
//bool merging::_merged_del(merging* pSameUnit)
//{
//	if (pSameUnit)
//		return merged.erase(pSameUnit);
//	return false;
//}

void merging::for_merged(function<void(merging*)> lambda)
{
	set<merging*> done_units;
	_for_merged(lambda, done_units);
}
void merging::_for_merged(function<void(merging*)> lambda, set<merging*>& done_units)
{
	try
	{
		//якщо змогли додати адресу до контейнеру відпрацьованих, то виконуємо лямбду для нашої адреси
		//та запускаємо рекурсію у всіх елементах контейнеру однакових екземплярів
		if (done_units.insert(this).second)
		{
			lambda(this);
			for (auto it : merged)
				it->_for_merged(lambda, done_units);
		};
	}
	catch (cex ex)
	{
		error("merging::for_the_same_units()", ex);
	}
}

bool merging::_find_in_my_merged(merging* p)
{
	return find(merged.begin(), merged.end(), p) != merged.end();
}
bool merging::_find_in_all_merged(merging* pUnit)
{
	bool a = false;
	if (pUnit)
		for_merged([&a, pUnit](merging* p)
			{
				if (!a)	a = p->_find_in_my_merged(pUnit);
			});
	return a;
}

inline const set<merging*>& merging::_get_same_units() const
{
	return merged;
}