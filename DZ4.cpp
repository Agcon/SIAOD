/*
���������� �������. ��������� ������ � ����������: �������, ���, ���� ��������, ���, ����, ���, ��� ������.
��������
1)	��������� ������ �� ������ ����������.
2)	�������� ������ � ����� ��������� ������� � ������������ � ����� ������.
3)	������� ������ � �����������, ���� ������� ������ ���������.
4)	������������ ������ ����������� ������� ������ ���� ������.
*/

#include "stdlib.h"
#include <vector>
#include "time.h"
#include <iostream> 
#include <string>
#include <iomanip>
using namespace std;

struct Sportsman {
	string surname, name, birthday, kind_of_sport, sex, weight, height;
};

Sportsman addSportsman(){
	Sportsman sportsman;
	cout << "������� ������� ����������:" << endl;
	cin >> sportsman.surname;
	cout << "������� ��� ����������:" << endl;
	cin >> sportsman.name;
	cout << "������� ���� �������� ����������:" << endl;
	cin >> sportsman.birthday;
	cout << "������� ��� ������ ����������:" << endl;
	cin >> sportsman.kind_of_sport;
	cout << "������� ��� ����������:" << endl;
	cin >> sportsman.sex;
	cout << "������� ��� ����������:" << endl;
	cin >> sportsman.weight;
	cout << "������� ���� ����������:" << endl;
	cin >> sportsman.height;
	cout << endl;

	return sportsman;
}

void addSportsmanInArray(Sportsman sportsman, vector<vector<vector<string>>>& array) {
	vector<string> sportsmanData(7);
	vector<vector<string>> temp;
	sportsmanData[0] = sportsman.surname;
	sportsmanData[1] = sportsman.name;
	sportsmanData[2] = sportsman.birthday;
	sportsmanData[3] = sportsman.kind_of_sport;
	sportsmanData[4] = sportsman.sex;
	sportsmanData[5] = sportsman.weight;
	sportsmanData[6] = sportsman.height;

	bool flag = true;
	
	for (int i = 0; i < array.size(); i++)
	{
		if (array[i][0][3] == sportsmanData[3]) 
		{
			array[i].push_back(sportsmanData);
			flag = false;
			break;
		}
	}
	if (flag) 
	{
		temp.push_back(sportsmanData);
		array.push_back(temp);
	}
}

void deletesportsman(vector<vector<vector<string>>>& array, int h) {
	for (int i = 0; i < array.size(); i++)
	{
		for (int j = 0; j < array[i].size(); j++) {
			if (stoi(array[i][j][6]) > h) {
				array[i].erase(array[i].begin() + j);
			}
			if (array[i].size() == 0) array.erase(array.begin() + i);
		}
	}
}

void printArray(vector<vector<vector<string>>> victorchuck) {
	for (int i = 0; i < victorchuck.size(); i++)
	{
		for (int j = 0; j < victorchuck[i].size(); j++) {
			for (int k = 0; k < 7; k++) {
				cout << victorchuck[i][j][k] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "");
	vector<vector<vector<string>>> data;
	int n;
	cout << "������������ ������ �4 ����������� �������� " << endl;
	cout << "������� ���������� ���������: " << endl;
	cin >> n;
	for (int i = 0; i < n; i++) {
		Sportsman sportsman = addSportsman();
		addSportsmanInArray(sportsman, data);
	}
	printArray(data);
	int critical_height;
	cout << "������� ���������� ����:" << endl;
	cin >> critical_height;
	cout << endl;
	deletesportsman(data, critical_height);
	printArray(data);
	system("pause");
	return 0;
}