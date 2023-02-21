#pragma once
#include "global_includes.h"
class user;

class state
{
	const user* who_ch { nullptr };
	enum state_of_change{
		NEW			= 0,
		NOT_CHANGED	= 0,
		CHANGING	= 1,
		CHANGED		= 2
	} change{ NEW };
	enum state_of_deleting {
		NOT_DELETED = 0,
		//READY_TO_DELETING = 1,
		DELETING	= 1,
		DELETED		= 2,
		ERASE		= 3
	} del{ NOT_DELETED };
	/*enum state_of_changed_by {
		SYS			= 0,
		BOT			= 1,
		HUMAN		= 2
	};
	state_of_changed_by	changed_by{ SYS };*/

public:
	bool ok() const
	{ 
		return change != CHANGING && !del; 
	}
	const user* who_changing() const
	{ 
		return who_ch; 
	}

	bool is_changed() const
	{ 
		return change == CHANGED; 
	}
	bool changing(const user* u = 0)
	{
		if (!ok()) return false;

		change = CHANGING;
		who_ch = u;
		return  true;
	}
	bool changed()
	{
		if (change != CHANGING) return false;

		change = CHANGED;
		return true;
	}
	bool not_changed()
	{
		if (change != CHANGING) return false;

		change = NOT_CHANGED;
		return true;
	}

	bool is_deleted() const
	{ 
		return del && del != DELETING; 
	}
	bool deleting(const user* u = 0)
	{
		if (!ok()) return false;

		del = DELETING;
		who_ch = u;
		return true;
	}
	bool deleted()
	{
		if (del != DELETING) return false;

		del = DELETED;
		return true;
	}
	bool not_deleleted()
	{
		if (del != DELETING) return false;

		del = NOT_DELETED;
		return true;
	}
	bool erase()
	{
		if (del != DELETED) return false;

		del = ERASE;
		return true;
	}

	//bool is_human_changed() const		{ return changed_by; }
	//bool human_changed()				{ return changed_by = HUMAN; }
private:
	friend ostream& operator<< (ostream& os, const state& s)
	{ 
		return os << "state: " << s.change << ", " << s.del;
	}
};
//
//bool state::changing(const user* u)
//{
//	if (!ok()) return false;
//
//	change = CHANGING;
//	who_ch = u;
//	return  true;
//}
//
//bool state::changed()
//{
//	if (change != CHANGING) return false;
//
//	change = CHANGED;
//	return true;
//}
//
//bool state::not_changed()
//{
//	if (change != CHANGING) return false;
//
//	change = NOT_CHANGED;
//	return true;
//}
//
//bool state::deleting(const user* u)
//{
//	if (!ok()) return false;
//
//	del = DELETING;
//	who_ch = u;
//	return true;
//}
//
//bool state::deleted()
//{
//	if (del != DELETING) return false;
//
//	del = DELETED;
//	return true;
//}
//
//bool state::not_deleleted()
//{
//	if (del != DELETING) return false;
//
//	del = NOT_DELETED;
//	return true;
//}
//
//bool state::erase()
//{
//	if (del != DELETED) return false;
//
//	del = ERASE;
//	return true;
//}
