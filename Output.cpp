#include "Output.h"

void output(const Code& code, const string& str, const string& path)
{
	ofstream ost;
	ost.open(path, ofstream::app);

	ost << code;

	for (int i = 0; i < (int)str.size(); i++)
	{
		Letter let(str[i], code);
		ost << let;
	}

	ost.close();
}

string common()
{
	cout << "Введите текст для записи... Для завершения ввода укажите символ \"'\"." << endl << endl;
	string record;
	SetConsoleCP(1251);
	getline(cin, record, '\'');
	SetConsoleCP(866);
	return record;
}