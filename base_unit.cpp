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

//��'��� ��'���� ����������� �� ���� ������
bool base_unit::will_send_upds_to(base_unit* what_links_to_me)
{
	try
	{//TODO: ������ ���������� �������� ���������� ��� ���������� ������ ��������� �� ������������ ����� ��� ��������
		if (what_links_to_me)
		{//�� �������������, ���������� ����� ���� - ���� ������ ��� ������������� ��������� �������!
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

//������� ��������� �� ��'������
bool base_unit::will_not_send_upds_to(base_unit* what_links_to_me)
{
	try
	{
		if (what_links_to_me)
		{//�� �������������, ���������� ����� ���� - ���� ������ ��� ������������� ��������� �������!
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

//������ ��� ��� ��������� �� ��'����, �� ����������� �� ���
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

