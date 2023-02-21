#pragma once
#include "global_includes.h"

//отримує інформацію про помилку та виводить її в консоль
void bug_report(const char* func_name, cex ex);
//отримує повідомлення про помилку та виводить його в консоль
void bug_report(const char* func_name, const char* error_message);

//отримує повідомлення про помилку та виводить його в консоль
void error(const char* func_name, cex ex);
//отримує повідомлення про помилку та виводить його в консоль
void error(const char* func_name, const char* error_message);
//отримує повідомлення про помилку та виводить його в консоль
void error(const char* func_name, cex ex, const char* error_message);

//конвертує беззнакове число у строку
string itos(const unsigned int& val);
//конвертує знакове число у строку
string itos(const int& val);

class timer
{
	milliseconds start = clock();
public:
	inline void reset(void) { start = clock(); }
	inline milliseconds elapse(void) { return clock() - start; }
};