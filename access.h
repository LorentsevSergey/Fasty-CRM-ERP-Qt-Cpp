#pragma once
#include "element.h"
class user;

class access : public base_unit
{
public:
	access();
	//access(base_unit* parent) : base_unit(parent) {};
	~access();

	bool verify(user& , user&);

private:

};