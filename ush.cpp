#include "ush.h"

//ush::ush(const ush& copy)
//{
//	i = copy.i;
//}
//ush::ush(const unsigned short val)
//{
//	i = (val < 0 ? 0 : (val > USHRT_MAX ? USHRT_MAX : val));
//}
//ush::ush(const short val)
//{
//	i = (val < 0 ? 0 : (val > USHRT_MAX ? USHRT_MAX : val));
//}
//ush::ush(const int& val)
//{
//	i = (val < 0 ? 0 : (val > USHRT_MAX ? USHRT_MAX : val));
//}
//ush::ush(int& val)
//{
//	i = (val < 0 ? 0 : (val > USHRT_MAX ? USHRT_MAX : val));
//}
//ush::ush(const float val)
//{
//	i = (val < 0 ? 0 : (val > USHRT_MAX ? USHRT_MAX : val));
//}
//ush::ush(const size_t& val)
//{
//	i = (val < 0 ? 0 : (val > USHRT_MAX ? USHRT_MAX : val));
//}
//ush::ush(const char* str)
//{
//	i = ush(atoi(str));
//}
//
//ush::operator bool() const
//{
//	return i;
//}
//ush::operator unsigned short()
//{
//	return i;
//}
//
//ush& ush::operator= (const ush copy)
//{
//	i = copy.i;
//	return *this;
//}
//ush& ush::operator+=(const ush val)
//{
//	i = (i + val.i >= USHRT_MAX ? USHRT_MAX : i + val.i);
//	return *this;
//}
//ush& ush::operator-=(const ush val)
//{
//	i = (i - val.i <= 0 ? 0 : i - val.i);
//	return *this;
//}
//
//ush& ush::operator++()
//{
//	if (i < USHRT_MAX) ++i;
//	return *this;
//}
//ush  ush::operator++(int)
//{
//	unsigned short t = i;
//	if (i < USHRT_MAX) ++i;
//	return t;
//}
//ush& ush::operator--()
//{
//	if (i) --i;
//	return *this;
//}
//ush  ush::operator--(int)
//{
//	unsigned short t = i;
//	if (i) --i;
//	return t;
//}
//
//ush ush::operator+(const ush val) const
//{
//	return i + val.i >= USHRT_MAX ? USHRT_MAX : i + val.i;
//}
//ush ush::operator-(const ush val) const
//{
//	return i - val.i <= 0 ? 0 : i - val.i;
//}
//
//int ush::operator*(const ush val) const
//{
//	unsigned int t = i * val.i;
//	return t >= USHRT_MAX ? USHRT_MAX : t;
//}
//float ush::operator/(const ush val) const
//{
//	return i / val.i;
//}
//ush ush::operator%(const ush val) const
//{
//	return i % val.i;
//}
//
//bool ush::operator==(const ush val) const
//{
//	return i == val.i;
//}
//bool ush::operator!=(const ush val) const
//{
//	return i != val.i;
//}
//bool ush::operator>=(const ush val) const
//{
//	return i >= val.i;
//}
//bool ush::operator<=(const ush val) const
//{
//	return i <= val.i;
//}
//bool ush::operator>(const ush val) const
//{
//	return i > val.i;
//}
//bool ush::operator<(const ush val) const
//{
//	return i < val.i;
//}
//
//ostream& operator<<(ostream& os, const ush& val)
//{
//	return os << val.i;
//}
//istream& operator>>(istream& is, ush& val)
//{
//	return is >> val.i;
//}
