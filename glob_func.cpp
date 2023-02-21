#pragma once
#include "glob_func.h"

void bug_report(const char* func_name, cex ex)
{
	cout << "Error in the " << func_name << ":\t" << ex.what() << "\n";
};
void bug_report(const char* func_name, const char* error_message)
{
	cout << "Error in the " << func_name << "\tMessage: " << error_message << "\n";
};

void error(const char* func_name, cex ex)
{
	cout << "Error in the " << func_name << ":\t" << ex.what() << "\n";
}
void error(const char* func_name, const char* error_message)
{
	cout << "Error in the " << func_name << ":\t" << error_message << "\n";
}
void error(const char* func_name, cex ex, const char* error_message)
{
	cout << "Error in the " << func_name << ":\t" << ex.what() << "\n" << error_message << "\n";
}

string itos(const unsigned int& val)
{
	char buffer[_MAX_U64TOSTR_BASE10_COUNT];
	_ultoa_s(val, buffer, _countof(buffer), 10);
	return buffer;
}
string itos(const int& val)
{
	char buffer[_MAX_U64TOSTR_BASE10_COUNT];
	_ultoa_s(val, buffer, _countof(buffer), 10);
	return buffer;
}


