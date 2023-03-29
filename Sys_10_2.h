#pragma once

#ifndef _SYS_10_2_H_

#define _SYS_10_2_H_

#include <iostream>
#include <string>
#include "Output.h"

using namespace std;

string per_10_2(int i);					// Из 10-чной в 2-чную систему счисления.
int per_2_10(string k);					// Из 2-чной в 10-чную систему счисления.
int degree(int i, const int& deg);		// Возведение в степень.

#endif