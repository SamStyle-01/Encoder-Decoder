#include "Letter.h"

Letter::Letter(const char k, const Code& cont)
{
	this->sym = k;
	np = cont.getCode().size();
	parts = new int[np];
	s_n = cont.getSn();
	int imp = k;
	maxcof = cont.getMulti();
	int isk = imp * s_n;
	for (int i = 0; i < np; i++)
		parts[i] = isk * cont.getCode()[i];
}

void operator>>(istream& is, Letter& let)
{
	string k;
	int result = 0;
	for (int i = 0; i < let.np; i++)
	{
		is >> k;
		result += per_2_10(k);
	}
	result /= (let.maxcof * let.s_n);
	let.sym = result;
}

ostream& operator<<(ostream& os, const Letter& let)
{
	for (int i = 0; i < let.np; i++)
	{
		os << per_10_2(let.parts[i]) << " ";
	}
	os << endl;
	return os;
}

char Letter::getChar() const
{
	return this->sym;
}

void Letter::printIt() const
{
	cout << this->sym;
}

Letter::Letter(const Code& cont)
{
	np = cont.getParts();
	parts = nullptr;
	maxcof = cont.getMulti();
	s_n = cont.getSn();
	sym = '\0';
}

Letter::~Letter()
{
	np = maxcof = s_n = 0;
	sym = '\0';
	delete[] parts;
	parts = nullptr;
}