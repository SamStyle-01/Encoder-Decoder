#pragma once

#ifndef _CODE_H_

#define _CODE_H_

#include <iostream>
#include <string>
#include "Output.h"
#include "Sys_10_2.h"
#include "Letter.h"

using namespace std;

class Letter;

class Code		// Является кодом для файла и кодированием одновременно.
{
public:
	Code(const string& str);		// Запись строки-кода.
	Code();
	friend ostream& operator<<(ostream& os, const Code& code);
	friend istream& operator>>(istream& is, Code& code);
	int getParts() const;			// Количество частей, на которые разбивается символ.
	int getMulti() const;			// Сумма множителей.
	int getSn() const;
	string getCode() const;
private:
	int m_multi;
	string m_code;
	int s_n;
};

#endif