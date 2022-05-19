//Бинарный однородный без использования дополнительной таблицы
//Железнодорожная справка: номер поезда, пункт отправления, пункт назначения, время отправления


#include <iostream>
#include <Windows.h>
#include <string>
#include <algorithm>
#include <random>
#include <chrono>
#include <ctime>
using namespace std;

string a = "йцукенгшщзхъфывапролджэячсмитьбю";
const char* letters[] = { "а", "б", "в", "г", "д", "е", "ё", "ж", "з", "и", "й", "к", "л", "м", "н", "о", "п", "р", "с",
        "т", "у", "ф", "х", "ц", "ч", "ш", "щ", "ъ", "ы", "ь", "э", "ю", "я" };
const string times[] = {"8:00", "9:00", "10:00", "11:00", "12:00", "13:00", "14:00", "15:00"};

struct Railway
{
public:
    int train_number;
    string departure;
    string destination;
    string time_of_departure;

};

void fillRailway(Railway* arr, int size) 
{
    srand(time(0));
    for (int i = 0; i < size; i++) {
        arr[i].train_number = 0 + rand() % 1000;
        for (int i1 = 0; i1 < 8; i1++)
            arr[i].departure += letters[rand() % (sizeof letters / sizeof(char*))];
        for (int i1 = 0; i1 < 8; i1++)
            arr[i].destination += letters[rand() % (sizeof letters / sizeof(char*))];
        arr[i].time_of_departure += times[0 + rand() % 7];
        cout << arr[i].train_number << "   " << arr[i].departure << "   " << arr[i].destination << "   " << arr[i].time_of_departure << endl;
    }
}

void create_heapify(Railway* arr, int n, int i)
{
    int most = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left].train_number > arr[most].train_number)
        most = left;
    if (right < n && arr[right].train_number > arr[most].train_number)
        most = right;
    if (most != i)
    {
        swap(arr[i], arr[most]);
        create_heapify(arr, n, most);
    }
}

void HeapSort(Railway* arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        create_heapify(arr, n, i);
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        create_heapify(arr, i, 0);
    }
}

void LinearSearch(Railway* arr, int size, int key)
{
    bool flag = true;
    for (int i = 0; i < size; i++)
        if (arr[i].train_number == key)
        {
            cout << "Найденный поезд" << endl;
            cout << arr[i].train_number << "   " << arr[i].departure << "   " << arr[i].destination << "   " << arr[i].time_of_departure << endl;
            flag = false;
            break;
        }
    if (flag)
        cout << "Номер поезда не найден" << endl;
}

void BarrierSearch(Railway* arr, int size, int key) 
{
    Railway last = arr[size - 1];
    arr[size - 1].train_number = key;
    int i = 0;
    for (i; arr[i].train_number != key; i++);
    if (i != size - 1 or last.train_number == key)
        cout << "Найденный поезд" << endl << arr[i].train_number << "   " << arr[i].departure << "   " << arr[i].destination << "   " << arr[i].time_of_departure << endl;
    else
        cout << "Номер поезда не найден" << endl;
}

void BinarySearch(Railway* arr, int size, int key)
{
    int left = 0;
    int right = size;
    int midd = 0;
    HeapSort(arr, size);
    while (true)
    {
        midd = (left + right) / 2;
        if (key < arr[midd].train_number)       
            right = midd - 1;     
        else if (key > arr[midd].train_number)  
            left = midd + 1;    
        else {                       
            cout << "Найденный поезд" << endl << arr[midd].train_number << "   " << arr[midd].departure << "   " << arr[midd].destination << "   " << arr[midd].time_of_departure << endl;
            break;
        }
        if (left > right) {       
            cout << "Номер поезда не найден" << endl;
            break;
        }

    }
}


int main()
{
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int size, key;
    Railway* arr;
    cin >> size;
    arr = new Railway[size];
    fillRailway(arr, size);
    cin >> key;
    double start_time = clock();
    LinearSearch(arr, size, key);
    cout << "На линейный поиск потребовалось: " << endl << (double)(clock() - start_time) / CLOCKS_PER_SEC << " сек." << endl;
    start_time = clock();
    BarrierSearch(arr, size, key);
    cout << "На линейный поиск с барьером потребовалось: " << endl << (double)(clock() - start_time) / CLOCKS_PER_SEC << " сек." << endl;
    start_time = clock();
    BinarySearch(arr, size, key);
    cout << "На бинарный поиск потребовалось: " << endl << (double)(clock() - start_time) / CLOCKS_PER_SEC << " сек." << endl;
    system("pause");
    return 0;
}
