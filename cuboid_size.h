#pragma once
#include "user.h"

typedef cuboid_size c_s;
typedef cuboid_size& cs;
typedef const cuboid_size& ccs;

class cuboid_size : public base_unit
{
	ush length	{ 0 },//������� � ��
		width	{ 0 },//������ � ��
		height	{ 0 };//������ � ��

public:
	cuboid_size() {}
	cuboid_size(ccs copy);
	cuboid_size(ush length, ush width, ush height);

	//��������� ������ � ��'���� (update ������ ��������� � ��� �������� ��'����)
	bool set(ccs copy);
	//���������� ������ ����� (update ������ ��������� � ��� �������� ��'����)
	bool set(ush length, ush width, ush height);

	ush get_length() const;	//�������� �������
	ush get_width()  const;	//�������� ������
	ush get_height() const;	//�������� ������
	ush get_volume() const;	//�������� ������� ��'��

	operator bool() const;

	bool operator== (ccs) const;
	bool operator!= (ccs) const;
	bool operator<= (ccs) const;
	bool operator>= (ccs) const;
	bool operator<  (ccs) const;
	bool operator>  (ccs) const;

	ush operator/  (ccs) const;
	cs  operator=  (ccs);
	cs  operator+= (ccs);
	cs  operator-= (ccs);
	c_s operator+  (ccs)	  const;
	c_s operator+  (ush) const;
	c_s operator-  (ccs)	  const;
	c_s operator-  (ush) const;
	//c_s operator-  (short val) const;
	cs  operator++ ();
	c_s operator++ (int value);
	cs  operator-- ();
	c_s operator-- (int value);

private:
	//������� ��'���, �� ��������� � ��� ����� ����� ������� ���������
	ush _vol_count(ush x, ush y, ush z) const;
	void _get_update_from(const base_unit*) override {};
	friend ostream& operator<< (ostream&, ccs);
};