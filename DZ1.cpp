/*
1.	Найти индекс элемента массива (первое вхождение), которое является совершенным (число равно сумме своих делителей кроме самого числа: 6, 28).
2.	Вставить новый элемент в массив после элемента, который является совершенным.
3.	Удалить элемент массива, расположенный перед элементом, содержащим совершенное число.
*/

#include "stdlib.h"
#include <vector>
#include "time.h"
#include <iostream> 
using namespace std;

void output(vector<int>& vect) //функция вывода вектора
{
	cout << endl;
	for (int i = 0; i < vect.size(); i++)
		cout << vect[i] << " ";
}

void changetovec(int* mass, int dlina, int index) // функция вставки элемента для статического и динамического массивов
{
	vector<int> vect;
	for (int i = 0; i < dlina; i++) 
		vect.push_back(mass[i]);
	int x = 0 + rand() % 1000;
	vect.insert(vect.begin() + index + 1, x);
	cout << "Случайное число, подлежащее вставке в массив: " << x << endl;
	cout << "Массив со вставленным числом: " << endl;
	output(vect);
	vect.erase(vect.begin() + index - 1);
	cout << "Массив с удаленным числом: " << endl;
	output(vect);
}

void vstavkaudal(vector<int>& vect, int index) {
	srand(time(0));
	int x = 0 + rand() % 1000;
	vect.insert(vect.begin() + index + 1, x);
	cout << "Случайное число, подлежащее вставке в массив: " << x << endl;
	cout << "Массив со вставленным числом: " << endl;
	output(vect);
	vect.erase(vect.begin() + index - 1);
	cout << "Массив с удаленным числом: " << endl;
	output(vect);
}

void int_massiv_stat_dyn(int* a) //генерируем целый случайный СТАТИЧЕСКИЙ ИЛИ ДИНАМИЧЕСКИЙ массив
{
	srand(time(0)); // инициализация генерации случайных чисел
	//генерируем целый случайный массив из 10 элментов
	for (int i = 0; i < 100; i++)
		a[i] = 2 + rand() % 1000;
	for (int i = 0; i < 100; i++)
		cout << a[i] << " "; // вывод результата на экране
	cout << "\n";
}

void input(vector<int>& a)
{
	srand(time(0)); // инициализация генерации случайных чисел
	//генерируем целый случайный вектор из 100 элментов
	for (int i = 0; i < 100; i++)
		a[i] = (2 + rand() % 1000);

	for (int i = 0; i < 100; i++)
		cout << a[i] << " "; // вывод результата на экране
	cout << "\n";
}

bool amazing(int number) {
	int summa = 1;
	for (int i = 2; i < int(pow(number, 0.5)) + 1; i++) {
		if (number % i == 0) {
			summa += (i + number / i);
		}
	}
	if (summa == number) return true;
	return false;
}

int main()
{
	setlocale(LC_ALL, "");
	cout << "Практическая работа №1 Заводченков Вячеслав " << endl;
	int arr[100];
	int arrdin[100];
	vector<int> vect;

	cout << "Выберите массив:" << endl << "1 - статический" << endl << "2 - динамический" << endl << "3 - вектор" << endl;
	int mode;
	cin >> mode;

	switch (mode)
	{
	case 1:
	{//Статический массив

		int index = 0;
		int_massiv_stat_dyn(arr); //создали целочисленный массив размера 10
		for (int i = 0; i < 100; i++) {
			if (amazing(arr[i])) {
				index = i;
				cout << "Индекс первого совершенного числа: " << i << endl;
				break;
			}
		}

		if (index == 0) {
			cout << "Такого числа нет" << endl;
			break;
		}

		changetovec(arr, 100, index);

		break;
	}
	case 2:
	{ //Динамический массив

		int index = 0;
		int_massiv_stat_dyn(arrdin); //создали целочисленный массив размера 10
		for (int i = 0; i < 100; i++) {
			if (amazing(arrdin[i])) {
				index = i;
				cout << "Индекс первого совершенного числа: " << i << endl;
				break;
			}
		}

		if (index == 0) {
			cout << "Такого числа нет" << endl;
			break;
		}

		changetovec(arrdin, 100, index);

		break;
	}
	case 3:
	{//вектор

		vector<int> vectorchuk(100);//инициализируем вектор и заполняем его ста нулями
		int index = 0;
		cout << "Изначальный массив: " << endl;
		input(vectorchuk);

		for (int i = 0; i < 100; i++) {
			if (amazing(vectorchuk[i])) {
				index = i;
				cout << "Индекс первого совершенного числа: " << i << endl;
				break;
			}
		}

		if (index == 0) {
			cout << "Такого числа нет" << endl;
			break;
		}

		vstavkaudal(vectorchuk, index);
		
		break;
	}
	}
	system("pause");
	return 0;
}
