#pragma once
#include "base_unit.h"

//base_unit::base_unit(base_unit* what_links_to_me)
//{
//	try
//	{
//		will_send_upds_to(what_links_to_me);
//	}
//	catch (cex ex)
//	{
//		error("base_unit::base_unit()", ex);
//	}
//}

base_unit::~base_unit()
{
	try
	{
		while (s_what_links_to_me.size())
			will_not_send_upds_to(*s_what_links_to_me.rbegin());
		while (s_i_link_to.size())
			(*s_i_link_to.rbegin())->will_not_send_upds_to(this);
		cut_me();
	}
	catch (cex ex)
	{
		error("base_unit::~base_unit()", ex);
	}
}

//зв'язує об'єкти посиланнями на одне одного
bool base_unit::will_send_upds_to(base_unit* what_links_to_me)
{
	try
	{//TODO: додати рекурсивну перевірку контейнерів для запобігання взаємної залежності та рекурсивного циклу при оновленні
		if (what_links_to_me)
		{//не перероблювати, прибираючі булеві змінні - вони потрібні для гарантованого виконання функцій!
			bool a = s_what_links_to_me.insert(what_links_to_me).second;
			bool b = what_links_to_me->s_i_link_to.insert(this).second;
			return a && b;
		}
	}
	catch (cex ex)
	{
		error("base_unit::will_send_upds_to()", ex);
	}
	return false;
}

//видаляє посилання між об'єктами
bool base_unit::will_not_send_upds_to(base_unit* what_links_to_me)
{
	try
	{
		if (what_links_to_me)
		{//не перероблювати, прибираючі булеві змінні - вони потрібні для гарантованого виконання функцій!
			bool a = s_what_links_to_me.erase(what_links_to_me);
			bool b = what_links_to_me->s_i_link_to.erase(this);
			return a && b;
		}
	}
	catch (cex ex)
	{
		error("base_unit::will_not_send_upds_to()", ex);
	}
	return false;
}

//сповіщує про своє оновлення всі об'єкти, що посилаються на нас
void base_unit::my_data_is_updated()
{
	try
	{
		for (auto it : s_what_links_to_me)
			it->_get_update_from(this);
	}
	catch (cex ex)
	{
		error("base_unit::my_data_is_updated()", ex);
	}
}

