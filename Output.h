#pragma once

#ifndef _OUTPUT_H_

#define _OUTPUT_H_

#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include "Sys_10_2.h"
#include "Code.h"
#include "Letter.h"


using namespace std;

string common();																		// Запись строки для вывода в файл.
void output(const Code& code, const string& str, const string& path);		// Система вывода в файл.

#endif