#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include "Sys_10_2.h"
#include "Output.h"
#include "Code.h"

using namespace std;

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");

	while (true)
	{
		cout << "\t\t\t*** Шифратор и дешифратор ***" << endl << endl;
		cout << "Доступные действия:" << endl;
		cout << "0: Инструкция." << endl;
		cout << "1: Добавить новый файл и заполнить его." << endl;
		cout << "2: Дополнить ранее созданный файл." << endl;
		cout << "3: Прочитать закодированный файл." << endl;
		cout << "4: Закодировать файл." << endl;
		cout << "5: Расшифровать файл." << endl;
		cout << "6: Выйти из программы." << endl;
		cout << "Ответ: ";

		int choice; cin >> choice;
		cout << endl;
		
		if (choice == 0)
		{
			while (true)
			{
				cout << "Пункт какого действия вы хотите уточнить?" << endl;
				cout << "1: Общая информация." << endl;
				cout << "2: Добавление файла." << endl;
				cout << "3: Дополнение файла." << endl;
				cout << "4: Считывание закодированного файла." << endl;
				cout << "5: Кодирование файла." << endl;
				cout << "6: Расшифровка файла." << endl;
				cout << "7: Выход из программы." << endl;
				cout << "Чтобы выйти из инструкции, введите 8." << endl;
				cout << "Ответ: ";
				int i; cin >> i;
				cout << endl;
				if (i == 0)
				{
					cout << "Это инструкция. Она может помочь в управлении программой." << endl;
				}
				else if (i == 1)
				{
					cout << "Эта программа кодирует и расшифровывает вводимые файлы." << endl;
					cout << "Все файлы, с которыми работает программа, должны находиться в папке с её файлом расширения exe." << endl;
					cout << "Иначе программа их попросту не сможет увидеть." << endl;
					cout << "\"x-число\" нужно только для кодирования. Его запоминать не нужно." << endl;
					cout << "Не забывайте слова-коды. Без них открыть файл будет почти невозможно." << endl;
				}
				else if (i == 2)
				{
					cout << "При создании файла его расширение указывать не нужно - оно всегда будет txt." << endl;
				}
				else if (i == 3)
				{
					cout << "При дополнении в названии расширение файла указывать не нужно - оно всегда txt." << endl;
				}
				else if (i == 4)
				{
					cout << "С помощью этой команды вы можете расшифровать файл, но при этом его исходник не изменится." << endl;
				}
				else if (i == 5)
				{
					cout << "Этой командой вы зашифруете уже существующий файл, тем самым перепишете его в коде." << endl;
					cout << "Чтобы команда работала корректно, файл должен быть с кодировкой ANSI." << endl;
					cout << "Чтобы сделать таковой кодировку файла txt, откройте файл, нажмите на панель \"Файл\"," << endl;
					cout << "после чего нажмите на \"Сохранить как\". Внизу будет панель с кодировками. Выберите ANSI." << endl;
					cout << "Сохраните." << endl;
				}
				else if (i == 6)
				{
					cout << "Расшифровывает файл расширения txt с кодировкой ANSI." << endl;
				}
				else if (i == 7)
				{
					cout << "Выключает программу." << endl;
				}
				else if (i == 8)
				{
					cout << "Выключение инструкции..." << endl;
					break;
				}
				else
				{
					cout << "Неверно введена команда. Повторите запрос." << endl;
				}
				cout << endl;
			}
		}
		else if (choice == 1)
		{
			cout << "Назовите файл: ";
			string name;
			SetConsoleCP(1251);
			cin >> name;
			SetConsoleCP(866);
			string content;
			cout << "Введите код для файла: ";
			SetConsoleCP(1251);
			cin >> content;
			SetConsoleCP(866);
			Code code(content);
			string out = common();
			string path2 = name + ".txt";
			output(code, out, path2);
			cout << "Файл был создан." << endl << endl;
		}
		else if (choice == 2)
		{
			cout << "Какой из файлов вы хотите дополнить?" << endl;
			cout << "Ответ: ";
			string choice;
			SetConsoleCP(1251);
			cin >> choice;
			SetConsoleCP(866);
			ifstream ist;
			string path = choice + ".txt";
			ist.open(path);
			if (ist.is_open())
			{
				Code one;
				SetConsoleCP(1251);
				ist >> one;
				SetConsoleCP(866);
				Letter two(one);
				cout << "Введите кодовое слово: ";
				string word;
				SetConsoleCP(1251);
				cin >> word;
				SetConsoleCP(866);
				if (one.getCode() == word)
				{
					ofstream ost;
					ost.open(path, ofstream::app);
					if (ost.is_open())
					{
						string out = common();
						for (int i = 0; i < (int)out.size(); i++)
						{
							Letter let(out[i], one);
							ost << let;
						}
						ost.close();
					}
					else
					{
						cout << "Ошибка открытия файла для записи." << endl;
					}
				}
				else
				{
					cout << "В доступе отказано." << endl;
					cout << endl << endl << "Сейчас консоль обновится..." << endl;
					system("pause");
					system("cls");
					ist.close();
					continue;
				}
				ist.close();
			}
			else
			{
				cout << "Ошибка открытия файла. Возможно, название было введено неверно или файл был удалён." << endl;
			}
		}
		else if (choice == 3)
		{
			cout << "Какой из файлов вы хотите прочитать?" << endl;
			cout << "Ответ: ";
			string choice;
			SetConsoleCP(1251);
			cin >> choice;
			SetConsoleCP(866);
			ifstream ist;
			string path = choice + ".txt";
			ist.open(path);
			if (ist.is_open())
			{
				Code one;
				ist >> one;
				Letter two(one);
				cout << "Введите кодовое слово: ";
				string word;
				SetConsoleCP(1251);
				cin >> word;
				SetConsoleCP(866);
				cout << endl;
				if (one.getCode() == word)
				{
					SetConsoleCP(1251);
					while (!ist.eof())
					{
						ist >> two;
						two.printIt();
					}
					SetConsoleCP(866);
				}
				else
				{
					cout << "В доступе отказано." << endl;
					ist.close();
					cout << endl << endl << "Сейчас консоль обновится..." << endl;
					system("pause");
					system("cls");
					continue;
				}
				ist.close();
			}
			else
			{
				cout << "Ошибка открытия файла. Возможно, название было введено неверно или файл был удалён." << endl;
			}
		}
		else if (choice == 4)
		{
			cout << "Какой файл вы хотите закодировать? Он должен быть в кодировке ANSI для правильной работы." << endl;
			cout << "Ответ: ";
			string ans;
			SetConsoleCP(1251);
			cin >> ans;
			SetConsoleCP(866);
			string path = ans + ".txt";
			ifstream ist;
			ist.open(path);
			if (ist.is_open())
			{
				string str, file = "";
				while (!ist.eof())
				{
					str = "";
					SetConsoleCP(1251);
					getline(ist, str);
					SetConsoleCP(866);
					file += str + "\n";
				}
				ist.close();
				ofstream ost;
				ost.open(path);
				if (ost.is_open())
				{
					string content;
					cout << "Введите код для файла: ";
					SetConsoleCP(1251);
					cin >> content;
					SetConsoleCP(866);
					Code code(content);
					output(code, file, path);
					cout << "Файл был закодирован." << endl << endl;
				}
				else
				{
					cout << "Ошибка открытия файла для записи." << endl;
				}
			}
			else
			{
				cout << "Ошибка открытия файла для чтения." << endl;
			}
		}
		else if (choice == 5)
		{
			cout << "Какой из файлов вы хотите расшифровать?" << endl;
			cout << "Ответ: ";
			string choice;
			SetConsoleCP(1251);
			cin >> choice;
			SetConsoleCP(866);
			ifstream ist;
			string path = choice + ".txt";
			ist.open(path);
			if (ist.is_open())
			{
				Code one;
				ist >> one;
				Letter two(one);
				cout << "Введите кодовое слово: ";
				string word;
				SetConsoleCP(1251);
				cin >> word;
				SetConsoleCP(866);
				string kaza = "";
				if (one.getCode() == word)
				{
					SetConsoleCP(1251);
					while (!ist.eof())
					{
						ist >> two;
						kaza += two.getChar();
					}
					SetConsoleCP(866);
				}
				else
				{
					cout << "В доступе отказано." << endl;
					cout << endl << endl << "Сейчас консоль обновится..." << endl;
					system("pause");
					system("cls");
					ist.close();
					continue;
				}
				ist.close();
				ofstream ost;
				ost.open(path);
				if (ost.is_open())
				{
					ost << kaza;
					ost.close();
					cout << "Файл был расшифрован." << endl;
				}
				else
				{
					cout << "Ошибка открытия файла для записи." << endl;
				}
			}
			else
				{
					cout << "Ошибка открытия файла для чтения." << endl;
				}
			}
		else if (choice == 6)
		{
			cout << "Прощайте." << endl;
			system("pause");
			break;
		}
		else
		{
			cout << "Команда введена некорректно. Повторите попытку." << endl << endl;
		}
		cout << endl << endl << "Сейчас консоль обновится..." << endl;
		system("pause");
		system("cls");
	}

	return 0;
}