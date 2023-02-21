#pragma once
#include "access.h"

/*public ref*/ class user
{
	char _age;
	//string _name;
	bool ishuman{ false };

public:
	user();
	user(const string&);

	/*property char age {
		void set(char age) { _age = age; }
		char get() { return _age; }
	}*/

	/*property string name {
		void set(string n) { _name = n; }
		string get() { return _name; }
	}*/

	bool is_human() { return ishuman; }

	//void set_name(const string&);
};

