#pragma once
#include "glob_func.h"

class merging
{
	set<merging*> merged;

public:
	bool merge(merging* copy);
	bool demerge(merging* copy);

	//������ ���� 䳿 ��� ���� ���������� ��'������, �� ������� ��'�������
	void for_merged(function<void(merging*)>);

protected:
	//����� ��� ��'��� �� ������ ��������� ��'����, ��'������� � ��� - ������� ���� ������ � ���������� ����� ��'���� 
	//�� ������ ��� ������ ��������� ��'���� � �������������� ������� �� ����� ������
	void cut_me();

private:
	//bool merged_add(merging* same_unit);//������ �� ���������� ��������� �����
	//bool _merged_del(merging* same_unit);//�������� � ���������� ��������� �����
	
	//������ ���� 䳿 ��� ���� ���������� ��'������, �� ������� ��'�������
	void _for_merged(function<void(merging*)>, set<merging*>&);

	bool _find_in_my_merged(merging*);
	bool _find_in_all_merged(merging*);
	 
	//������� ��������� ����� ��������� ��'����
	const set<merging*>& _get_same_units() const;
};

