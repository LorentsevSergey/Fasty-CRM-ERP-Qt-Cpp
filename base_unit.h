#pragma once
#include "merging.h"
#include "state.h"

class base_unit : public merging {
	//set of pointers to the objects refers to me
	//I will send my updates to them
	set<base_unit*> s_what_links_to_me;

	//set of pointers to the objects I link to
	//I will get updates from them
	set<base_unit*> s_i_link_to;

public:
	base_unit() {}

	//base_unit(base_unit* what_links_to_me);

	//��'��� � ��'�����, ������� ������ ����������� ��������� � ���� ��'����
	bool will_send_upds_to(base_unit* what_links_to_me);

	//������� ��'���� � ��'�����, ��� �� ��������� ���� �������� �� ����� ��'����
	bool will_not_send_upds_to(base_unit* what_links_to_me);

	void my_data_is_updated();

	state state;

protected:
	~base_unit();

private:
	//��������� ����� � ��`����, �� ������ � ���������
	//���������: �������� �������� ������ � ��������, ���������� ����� � ��, ������� ����� �����������, �������� ��������� ���
	virtual void _get_update_from(const base_unit*) = 0;
};