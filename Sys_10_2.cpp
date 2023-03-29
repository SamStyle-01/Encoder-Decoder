#include "Sys_10_2.h"

string per_10_2(int i)
{
	if (i > 0)
	{
		string k;
		while (i > 0)
		{
			k += to_string(i % 2);
			i /= 2;
		}
		for (int j = 0; j < (int)k.size() / 2; j++)
		{
			char ch = k[j];
			k[j] = k[k.size() - j - 1];
			k[k.size() - j - 1] = ch;
		}
		k = "0" + k;
		return k;
	}
	else if (i == 0)
		return "0";
	else
	{
		i = -i;
		string k;
		while (i > 0)
		{
			k += to_string(i % 2);
			i /= 2;
		}
		for (int j = 0; j < (int)k.size() / 2; j++)
		{
			char ch = k[j];
			k[j] = k[k.size() - j - 1];
			k[k.size() - j - 1] = ch;
		}
		k = "1" + k;
		return k;
	}
}

int per_2_10(string k)
{
	int result = 0;
	for (int i = (int)k.size() - 1; i > 0; i--)
	{
		if (k[i] == '1')
		{
			result += degree(2, k.size() - i - 1);
		}
	}
	if (k[0] == '1')
	{
		result = -result;
	}
	return result;
}

int degree(int i, const int& deg)
{
	int result = i;
	if (deg > 0)
	{
		for (int j = 1; j < deg; j++)
			result *= i;
		return result;
	}
	else if (deg == 0)
	{
		return 1;
	}
	else
	{
		throw exception("Функция не предназначена для подсчёта отрицательных степеней.");
	}
}
