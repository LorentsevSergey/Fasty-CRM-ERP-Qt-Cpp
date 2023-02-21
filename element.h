#pragma once
#include "dictionary.h"

template<typename T>
class element : public base_unit
{
	T data;
public:
	element() : data(T()) {};
	//�������������� �����������, ���������� �������� �� ��'��� parent, �� ���������� �� ��� ��'���
	element(base_unit* parent, const T& data) : base_unit(parent), data(data) {};
	//����������� ��������� �� ���������� �� ��'���
	element(const element<T>& elem) : data(elem.data) {};//������� ���������� ���� � ������� �����... ����� ���������.
	//����������� ��������� �� ���������� �� ���
	element(const T& data) : data(data) {};

	bool set (const T& data);
	bool set(const element<T>& elem);
	const T& get () const;
	vector<T>& get(vector<T>&);
	deque<T>& get(deque<T>&);

	operator bool() const;

	bool operator == (const element<T>& elem)	const	{ return data == elem.data; };
	bool operator != (const element<T>& elem)	const	{ return data != elem.data; };
	bool operator <= (const element<T>& elem)	const	{ return data <= elem.data; };
	bool operator >= (const element<T>& elem)	const	{ return data >= elem.data; };
	bool operator <  (const element<T>& elem)	const	{ return data < elem.data; };
	bool operator >  (const element<T>& elem)	const	{ return data > elem.data; };
	bool operator && (const element<T>& elem)	const	{ return data && elem.data; };
	bool operator || (const element<T>& elem)	const	{ return data || elem.data; };
	bool operator ! ()							const	{ return !data; };
	
	T operator * (const element<T>& elem)		const	{ return data * elem.data; };
	T operator * (const T& val)					const	{ return data * val; };
	double operator / (const element<T>& elem)	const	{ return data / elem.data; };
	double operator / (const T& val)			const	{ return data / val; };
	T operator % (const element<T>& elem)		const	{ return data % elem.data; };
	T operator + (const element<T>& elem)		const	{ return data + elem.data; };
	T operator - (const element<T>& elem)		const	{ return data - elem.data; };

	element<T>& operator = (const T& data);
	element<T>& operator = (const element<T>& elem);
	element<T>& operator += (const element<T>& elem);
	element<T>& operator -= (const element<T>& elem);
	element<T>& operator ++ ();
	element<T>  operator ++ (int value);
	element<T>& operator -- ();
	element<T>  operator -- (int value);

private:
	//��������� ���-� ��� ��������� ����� � ��'����, �� ������ � ���������
	virtual void _get_update_from(const base_unit*) override {};

	friend ostream& operator<< (ostream& os, const element<T>& elem) { return os << elem.data; };
};

//������ ���, ������� � ���������
template<typename T>
bool element<T>::set(const T& data)
{
	if (this->data == data) return false;
	this->data = data;
	my_data_is_updated();
	return true;
}

//������ ��� ��'����, ���������� � ���������
template<typename T>
inline bool element<T>::set(const element<T>& elem)
{
	return set(elem.data);
}

//������� ��� � ��'����
template<typename T>
inline const T& element<T>::get() const
{
	return data;
}

//������ � ��������� ��������� ��������� �� ��� � ��� ��������� ��'���� �� ������� ��������� �� ��� ���������
template<typename T>
vector<T>& element<T>::get(vector<T>& v) 
{
	for_merged([&v](merging* same_elem)
		{
			v.push_back( static_cast<element<T>*>(same_elem)->get() );
		});
	return v;
}

template<typename T>
deque<T>& element<T>::get(deque<T>& res)
{
	for_merged([&res](merging* same_elem)
		{
			res.push_back( static_cast<element<T>*>(same_elem)->get() );
		});
	return res;
}

template<typename T>
inline element<T>::operator bool() const
{
	return data;
}


template<typename T>
inline element<T>& element<T>::operator = (const T& data)
{
	set(data);
	return *this;
}

template<typename T>
inline element<T>& element<T>::operator = (const element<T>& elem)
{
	set(elem.data);
	return *this;
}

template<typename T>
inline element<T>& element<T>::operator += (const element<T>& elem)
{
	set(data + elem.data);
	return *this;
}

template<typename T>
inline element<T>& element<T>::operator-=(const element<T>& elem)
{
	set(data - elem.data);
	return *this;
}

template<typename T>
inline element<T>& element<T>::operator ++ ()
{
	set(data + 1);
	return *this;
}

template<typename T>
inline element<T> element<T>::operator ++ (const int value)
{
	element<T> temp(data);
	set(data + 1);
	return temp;
}

template<typename T>
inline element<T>& element<T>::operator -- ()
{
	set(data - 1);
	return *this;
}

template<typename T>
inline element<T> element<T>::operator -- (const int value)
{
	element<T> temp(data);
	set(data - 1);
	return temp;
}


template<typename T>
void print_elements(element<T>& p)
{
	vector<T> vData;
	p.get(vData);
	for (size_t i = 0; i < vData.size(); ++i)
		cout << "sameUnits #" << i << "\tdata: " << vData[i] << endl;
};