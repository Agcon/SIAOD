/*
Дано предложение, состоящее из слов, разделенных запятой или пробелами, среди которых есть группы цифр, определяющих целые числа из диапазона [0..19].
Отредактировать введенную строку, заменив каждое число, на последовательность, заключенную в круглые скобки, символа +,
(если число четное) или на – (если число нечетное), длина которой равна найденному числу.
*/


#include "stdlib.h"
#include <vector>
#include "time.h"
#include <iostream> 
#include <string>
#include <iomanip>
using namespace std;

string transformer(const char* str) 
{
	string otvet = "", symbol;
	int num;
	if (isdigit(str[0]) and !isdigit(str[1])) {
		num = str[0] - '0';
		otvet += "(";
		if (num % 2 == 0) symbol = "+";
		else symbol = "-";
		for (int i = 0; i < num; i++) {
			otvet += symbol;
		}
		otvet += ")";
	}
	for (int i = 1; i < strlen(str); i++) {
		if (!isdigit(str[i])) otvet += str[i];
		else {
			if (isdigit(str[i - 1])) {
				num = (str[i - 1] - '0') * 10 + (str[i] - '0');
				otvet += "(";
				if (num % 2 == 0) symbol = "+";
				else symbol = "-";
				for (int j = 0; j < num; j++) {
					otvet += symbol;
				}
				otvet += ")";
			}
			else {
				if (i + 1 == strlen(str) or !isdigit(str[i + 1])) {
					num = str[i] - '0';
					otvet += "(";
					if (num % 2 == 0) symbol = "+";
					else symbol = "-";
					for (int j = 0; j < num; j++) {
						otvet += symbol;
					}
					otvet += ")";
				}
			}
		}
	}

	return otvet;
}

string transformer(string str)
{
	string otvet = "", symbol;
	int num;
	if (isdigit(str[0]) and !isdigit(str[1])) {
		num = str[0] - '0';
		otvet += "(";
		if (num % 2 == 0) symbol = "+";
		else symbol = "-";
		for (int i = 0; i < num; i++) {
			otvet += symbol;
		}
		otvet += ")";
	}
	for (int i = 1; i < str.length(); i++) {
		if (!isdigit(str[i])) otvet += str[i];
		else {
			if (isdigit(str[i - 1])) {
				num = (str[i - 1] - '0') * 10 + (str[i] - '0');
				otvet += "(";
				if (num % 2 == 0) symbol = "+";
				else symbol = "-";
				for (int j = 0; j < num; j++) {
					otvet += symbol;
				}
				otvet += ")";
			}
			else {
				if (i + 1 == str.length() or !isdigit(str[i + 1])) {
					num = str[i] - '0';
					otvet += "(";
					if (num % 2 == 0) symbol = "+";
					else symbol = "-";
					for (int j = 0; j < num; j++) {
						otvet += symbol;
					}
					otvet += ")";
				}
			}
		}
	}

	return otvet;
}

int main()
{
	setlocale(LC_ALL, "");
	string s;
	cout << "Практическая работа №3 Заводченков Вячеслав " << endl;
	cout << "Выберите, что используем:" << endl << "1 - нуль терминальная строка" << endl << "2 - строка типа string" << endl;
	int mode;
	cin >> mode;

	switch (mode)
	{
	case 1:
	{//Нуль терминальная строка

		cout << "advjsp 17sggsg, 8sgsg sgvxvxv 6" << endl;
		const char* nullter = "advjsp 17sggsg, 8sgsg sgvxvxv 6";
		cout << transformer(nullter) << endl;
		break;
	}
	case 2:
	{ //Строка типа string
		cout << "advjsp 17sggsg, 8sgsg sgvxvxv 6" << endl;
		string str = "advjsp 17sggsg, 8sgsg sgvxvxv 6";
		cout << transformer(str) << endl;
		break;
	}
	}
	system("pause");
	return 0;
}
