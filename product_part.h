#pragma once
#include "product.h"

class product_part : public base_unit
{
	product* p_prod;
	storage* p_stor{ nullptr };
	uint count;				//������� �������� �������� � �������
	uint max_count{ 0 };	//����������� ������� ������� � �������� ������
	uint net_weight{ 0 };	//���� �������� �������� � �������
	uint brutto_weight{ 0 };//���� �������� �������� ����� �� ��������
	uint volume;			//��'�� �������� ������� � �������

public:
	//product_part() {}
	product_part(product& = dict.p.at(0), uint count = 0);
	product_part(product&, uint count, storage&);
	~product_part();

	bool set_storage(storage& storage);
	bool del_storage();//????????????????????????????
	storage& get_storage() const;
	product& get_product() const;

	//���������� ������� ��������, ��������� ������ ��������
	bool set_count(uint count);
	//���� �������� � ������� �������� ��������
	bool count_plus(const int& count);
	//������� ������ ������� ��������
	uint get_count() const;
	//������� ����������� ������� ������� ��������, �� ���������� � ������
	uint get_max_count() const;
	//������� ����� ���� ������� �������� � ������
	uint get_net_weight() const;
	//������� ������ ���� ������� �������� � �������
	uint get_brutto_weight() const;
	//������� ��'�� ����
	uint get_volume() const;

private:
	bool _calc_max_count();
	bool _calc_net_weight();
	bool _calc_brutto_weight();
	void _calc_volume();

	//��������� ����� � ��`����, �� ������ � ���������
	void _get_update_from(const base_unit*) override;

	friend ostream& operator<< (ostream&, const product_part&);
};

