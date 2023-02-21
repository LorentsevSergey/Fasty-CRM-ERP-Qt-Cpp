#pragma once
#include "cuboid_size.h"

cuboid_size::cuboid_size(ccs copy) :
	length	( copy.length ),
	width	( copy.width  ),
	height	( copy.height ) {}
cuboid_size::cuboid_size(ush l, ush w, ush h)
{
	set(l, w, h);
}

bool cuboid_size::set(ccs copy)
{
	return set(copy.length, copy.width, copy.height);
}
bool cuboid_size::set(ush l, ush w, ush h)
{	
	try
	{
		if (length == l && width == w && height == h)
			return false;

		length = l;
		width = w;
		height = h;

		my_data_is_updated();
		return true;
	}
	catch (cex ex)
	{
		error("cuboid_size::set()", ex);
		return false;
	}
}

ush cuboid_size::get_length() const
{
	return length;
}
ush cuboid_size::get_width()  const
{
	return width;
}
ush cuboid_size::get_height() const
{
	return height;
}
ush cuboid_size::get_volume() const
{
	return length * width * height;
}

cuboid_size::operator bool() const
{
	return length || width || height;
}

bool cuboid_size::operator==(ccs s) const
{
	return length == s.length && width == s.width && height == s.height;
}
bool cuboid_size::operator!=(ccs s) const
{
	return !operator==(s);
}
bool cuboid_size::operator<=(ccs s) const
{
	return length <= s.length
		&& width  <= s.width
		&& height <= s.height;
}
bool cuboid_size::operator>=(ccs s) const
{
	return length >= s.length
		&& width  >= s.width
		&& height >= s.height;
}
bool cuboid_size::operator< (ccs s) const
{
	return length < s.length
		&& width  < s.width
		&& height < s.height;
}
bool cuboid_size::operator> (ccs s) const
{
	return length > s.length
		&& width  > s.width
		&& height > s.height;
}

ush cuboid_size::operator/(ccs s) const
{
	try
	{
		if (!(length && width && height && s.length && s.width && s.height))
			return 0;

		ush max_count (_vol_count(s.length, s.width, s.height));
		max_count = max(_vol_count(s.width, s.length, s.height), max_count);
		max_count = max(_vol_count(s.height, s.width, s.length), max_count);
		max_count = max(_vol_count(s.length, s.height, s.width), max_count);
		max_count = max(_vol_count(s.width, s.height, s.length), max_count);
		max_count = max(_vol_count(s.height, s.length, s.width), max_count);

		return max_count;
	}
	catch (cex ex)
	{
		error("cuboid_size::operator/", ex);
		return 0;
	}
}
ush cuboid_size::_vol_count(ush x, ush y, ush z) const
{
	return ush( round(length / x) * round(width / y) * round(height / z) );
}

cs  cuboid_size::operator= (ccs s)
{
	set(s.length, s.width, s.height);
	return *this;
}
cs  cuboid_size::operator+=(ccs s)
{
	set(length + s.length, width + s.width, height + s.height);
	return *this;
}
cs  cuboid_size::operator-=(ccs s)
{
	set(length - s.length, width - s.width, height - s.height);
	return *this;
}
c_s cuboid_size::operator+ (ccs s)	const
{
	try
	{
		return { ush(length + s.length), ush(width + s.width), ush(height + s.height) };
	}
	catch (cex ex)
	{
		error("cuboid_size::operator+", ex);
		return {};
	}
}
c_s cuboid_size::operator+ (ush val)const
{
	try
	{
		return { ush(length + val), ush(width + val), ush(height + val) };
	}
	catch (cex ex)
	{
		error("cuboid_size::operator+", ex);
		return {};
	}
}
c_s cuboid_size::operator- (ccs s)	const
{
	try
	{
		return { ush(length - s.length), ush(width - s.width), ush(height - s.height) };
	}
	catch (cex ex)
	{
		error("cuboid_size::operator-", ex);
		return {};
	}
}
c_s cuboid_size::operator- (ush val)const
{
	try
	{
		return { ush(length - val), ush(width - val), ush(height - val) };
	}
	catch (cex ex)
	{
		error("cuboid_size::operator-", ex);
		return {};
	}
}
//c_s cuboid_size::operator- (short val)		const
//{
//	try
//	{
//		int	l(length - val),
//			w(width - val),
//			h(height - val);
//
//		if (l < 0) l = 0;
//		if (w < 0) w = 0;
//		if (h < 0) h = 0;
//
//		return { ush(l), ush(w), ush(h) };
//	}
//	catch (cex ex)
//	{
//		error("cuboid_size::operator-", ex);
//		return {};
//	}
//}
cs  cuboid_size::operator++()
{
	set(length+1, width+1, height+1);
	return *this;
}
c_s cuboid_size::operator++(int value)
{
	cs temp (*this);
	++(*this);
	return temp;
}
cs  cuboid_size::operator--()
{
	set(length-1, width-1, height-1);
	return *this;
}
c_s cuboid_size::operator--(int value)
{
	cs temp(*this);
	--(*this);
	return temp;
}

ostream& operator<<(ostream& os, ccs s)
{
	return os << "l " << s.length << ", w " << s.width << ", h " << s.height;
}
