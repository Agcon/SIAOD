/*
���� ���������� �������. ����� ����������� �������� ����� ���������, ������������� ��� �������� ����������.
*/

/*
����� ������� ������� �������� �������������� ��������� ������� ������.
*/


#include "stdlib.h"
#include <vector>
#include "time.h"
#include <iostream> 
using namespace std;

void create_matrix_stat(int a[10][10]) //���������� ����� ��������� ����������� ������
{
	srand(time(0)); // ������������� ��������� ��������� �����
	//���������� ����� ��������� ������ �� 10x10 ��������
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			a[i][j] = -1000 + rand() % 10000;
		}
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << a[i][j] << " "; // ����� ���������� �� ������
		}
		cout << "\n";
	}
}

void create_matrix_dyn(int** a, int n) { //���������� ����� ��������� ������������ ������
	srand(time(0)); // ������������� ��������� ��������� �����
	//���������� ����� ��������� ������ �� 10x10 ��������
	for (int i = 0; i < n; i++) a[i] = new int[n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = -1000 + rand() % 10000;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " "; // ����� ���������� �� ������
		}
		cout << "\n";
	}
}

int find_min(int a[10][10]) {
	int minn = 10000000;
	for (int i = 0; i < 10; i++) {
		for (int j = (10 - i); j < 10; j++) {
			if (a[i][j] < minn) minn = a[i][j];
		}
	}
	return minn;
}

int find_min(int** a, int n) {
	int minn = 10000000;
	for (int i = 0; i < n; i++) {
		for (int j = (n - i); j < n; j++) {
			if (a[i][j] < minn) minn = a[i][j];
		}
	}
	return minn;
}
void gauss_slau() {
	int num, d, s;
	srand(time(0));
	cout << "������� ���������� ����������� � ����:" << endl;
	cin >> num;
	vector < vector <double> > a(num, vector <double>(num + 1));
	double* x = new double[num];
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num + 1; j++) {
			a[i][j] = (-1000 + rand() % 100000) / 100.0;
			if (j == num) cout << "= " << a[i][j];
			else cout << a[i][j] << "x" << j + 1 << " ";		
		}
		cout << endl;
	}
	for (int i = 0; i < num; i++){ // ������ ���
		for (int j = i + 1; j < num; j++){
			d = a[j][i] / a[i][i];
			for (int k = i; k < num; k++){
				a[j][k] = a[j][k] - d * a[i][k]; 
			}
			a[j][num] = a[j][num] - d * a[i][num]; 
		}
	}
	x[0] = a[num - 1][num] / a[num - 1][num - 1];

	for (int i = num - 1; i >= 0; i--){ // �������� ���
		d = 0;
		for (int j = i + 1; j < num; j++){
			s = a[i][j] * x[j];
			d += s;
		}
		x[i] = (a[i][num] - d) / a[i][i]; 
	}

	cout << "����� �������: " << endl;

	for (int i = 0; i < num; i++)
		cout << "x[" << i + 1 << "]=" << x[i] << " " << endl;
}

int main()
{
	setlocale(LC_ALL, "");
	cout << "������������ ������ �1 ����������� �������� " << endl;
	int arr[10][10];
	vector<int> vect;

	cout << "�������� ������:" << endl << "1 - �����������" << endl << "2 - ������������" << endl;
	int mode;
	cin >> mode;

	switch (mode)
	{
	case 1:
	{//����������� ������

		int index = 0;
		create_matrix_stat(arr); //������� ������������� ������ ������� 10x10
		cout << "����������� �����:" << find_min(arr) << endl;

		break;
	}
	case 2:
	{ //������������ ������

		int n = 10;
		int** arrdin = new int* [n];
		create_matrix_dyn(arrdin, n); //������� ������������� ������ ������� 10x10
		cout << "����������� �����:" << find_min(arrdin, n) << endl;

		break;
	}
	}
	gauss_slau();
	system("pause");
	return 0;
}