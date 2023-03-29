#include "Code.h"

Code::Code(const string& str)
{
	m_multi = 0;
	cout << "Укажите x-число: ";
	while (true)
	{
		cin >> s_n;
		if (s_n < -1000)
		{
			cout << "Выберите число больше -1000." << endl;
		}
		else if (s_n > 1000)
		{
			cout << "Выберите число меньше 1000." << endl;
		}
		else
		{
			break;
		}
	}

	m_code = str;
	for (int i = 0; i < (int)str.size(); i++)
		m_multi += m_code[i];
}

string Code::getCode() const
{
	return this->m_code;
}

Code::Code()
{
	m_multi = s_n = 0;
	m_code = "";
}

ostream& operator<<(ostream& os, const Code& code)
{
	os << per_10_2((int)code.m_code.size() * 13) << " ";
	for (int i = 0; i < (int)code.m_code.size(); i++)
	{
		os << per_10_2((int)code.m_code[i] * 13) << " ";
	}
	os << endl;
	os << per_10_2(code.m_multi * 24) << " ";
	os << per_10_2(code.s_n * 5) << endl;
	return os;
}

istream& operator>>(istream& is, Code& code)
{
	string s1;
	is >> s1;
	int size = per_2_10(s1) / 13;
	char* code1 = new char[size + 1];
	for (int i = 0; i < size; i++)
	{
		string let;
		is >> let;
		int j = per_2_10(let) / 13;
		code1[i] = j;
	}
	code1[size] = '\0';
	code.m_code = code1;
	string mul1;
	is >> mul1;
	code.m_multi = per_2_10(mul1) / 24;
	string s;
	is >> s;
	code.s_n = per_2_10(s) / 5;
	return is;
}

int Code::getSn() const
{
	return s_n;
}

int Code::getParts() const
{
	return (int)this->m_code.size();
}

int Code::getMulti() const
{
	return this->m_multi;
}