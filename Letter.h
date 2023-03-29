#pragma once

#ifndef _LETTER_H_

#define _LETTER_H_

#include <iostream>
#include <string>
#include "Output.h"
#include "Sys_10_2.h"
#include "Code.h"

using namespace std;

class Code;

class Letter		// Является кодируемым символом.
{
public:
	Letter(const char k, const Code& cont);
	Letter(const Code& cont);
	~Letter();
	friend ostream& operator<<(ostream& os, const Letter& let);
	friend void operator>>(istream& is, Letter& let);
	char getChar() const;
	void printIt() const;
private:
	int* parts;		// Преобразованные части символа.
	int np;		// Количество разбитых частей
	int s_n;	// Множитель.
	char sym;	// Основной символ. Главная часть.
	int maxcof;	// Общее количество коэффициентов.
};

#endif