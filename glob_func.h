#pragma once
#include "global_includes.h"

//������ ���������� ��� ������� �� �������� �� � �������
void bug_report(const char* func_name, cex ex);
//������ ����������� ��� ������� �� �������� ���� � �������
void bug_report(const char* func_name, const char* error_message);

//������ ����������� ��� ������� �� �������� ���� � �������
void error(const char* func_name, cex ex);
//������ ����������� ��� ������� �� �������� ���� � �������
void error(const char* func_name, const char* error_message);
//������ ����������� ��� ������� �� �������� ���� � �������
void error(const char* func_name, cex ex, const char* error_message);

//�������� ���������� ����� � ������
string itos(const unsigned int& val);
//�������� ������� ����� � ������
string itos(const int& val);

class timer
{
	milliseconds start = clock();
public:
	inline void reset(void) { start = clock(); }
	inline milliseconds elapse(void) { return clock() - start; }
};