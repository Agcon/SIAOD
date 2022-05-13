// Простого обмена (пузырек) с условием Айверсона -- Шейкерная сортировка -- TimSort - гибридный алгоритм

#include <iostream>
#include <vector>
#include <ctime>
#include <random>
#include <chrono>
#include <ctime>
using namespace std;

void random_arr(int* arr, int n) 
{
	srand(time(0));
	for (int i = 0; i < n; i++) {
		arr[i] = 1 + rand() % 1000;
	}
}

void arr_out(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int BubbleSort_Iverson(int* array, int len)
{
	int i, j, c;
	int k = 0;
	for (i = len; i > 1; i--)
	{
		k = 0;
		for (j = 1; j < i; j++)
			if (array[j] < array[j - 1])
			{
				c = array[j];
				array[j] = array[j - 1];
				array[j - 1] = c;
				k = 1;
			}
		if (k == 0) return 0;
	}
}

void Swap(int* arr, int i)
{
	int temp;
	temp = arr[i];
	arr[i] = arr[i - 1];
	arr[i - 1] = temp;
}

void ShakerSort(int* arr, int start, int n)
{
	int left, right, i;
	left = start;
	right = n - 1;
	while (left <= right)
	{
		for (i = right; i >= left; i--)
			if (arr[i - 1] > arr[i]) Swap(arr, i);
		left++;
		for (i = left; i <= right; i++)
			if (arr[i - 1] > arr[i]) Swap(arr, i);
		right--;
	}
}

int getMinrun(int n)
{
	int r = 0;
	while (n >= 64)
	{
		r |= n & 1;
		n >>= 1; 
	}
	return n + r;
}

struct sRange {
	int start;
	int length;
};

typedef sRange Range;


void sortInsertionPart(int* array, int start, int end)
{
	for (int i = start + 1; i < end; ++i)
	{
		int current = array[i];
		int j = i - 1;
		while ((j >= start) && (current < array[j]))
		{
			swap(array[j], array[j + 1]);
			--j;
		}
	}
}

void merge(int* array, int fStart, int fLength, int sStart, int sLength)
{
	int* tmp = new int[fLength];

	memcpy(tmp, &array[fStart], sizeof(int) * (fLength));
	int fIndex = 0;
	int sIndex = sStart;
	int i = fStart;

	while (i < sStart + sLength - 1)
	{
		if (array[sIndex] > tmp[fIndex])
		{
			array[i] = tmp[fIndex];
			++fIndex;
			fIndex = std::min(fIndex, fLength);
		}
		else if (array[sIndex] <= tmp[fIndex])
		{
			array[i] = array[sIndex];
			++sIndex;
			sIndex = std::min(sIndex, sStart + sLength);
		}
		if (sIndex == sStart + sLength)
		{
			if (fIndex != fLength)
			{
				memcpy(&array[i + 1], &tmp[fIndex], sizeof(int) * (fLength - fIndex));
				i = sStart + sLength;
			}
		}
		if (fIndex == fLength)
		{
			i = sStart + sLength;
		}
		++i;
	}
	delete[] tmp;
}

void Timsort(int* array, int n)
{
	int minrun = getMinrun(n);

	vector <Range> minrunStack;

	int currentIndex = 0;

	while (currentIndex < n - 1)
	{
		int currentRunIndex = currentIndex;
		int nextIndex = currentRunIndex + 1;

		if (array[currentRunIndex] > array[nextIndex])
		{
			swap(array[currentRunIndex], array[nextIndex]);
		}

		bool goNext = true;
		while (goNext)
		{
			if (array[currentRunIndex] > array[nextIndex])
				goNext = false;
			if (!(goNext) && (currentRunIndex - currentIndex < minrun))
				goNext = true;
			if (currentRunIndex == n - 1)
				goNext = false;
			if (goNext)
			{
				++currentRunIndex;
				++nextIndex;
			}
		}
		sortInsertionPart(array, currentIndex, currentRunIndex + 1);

		Range r;
		r.start = currentIndex;
		r.length = currentRunIndex - currentIndex;

		minrunStack.push_back(r);

		currentIndex = currentRunIndex;
	}

	while (minrunStack.size() > 1)
	{
		Range x = minrunStack.at(0);
		minrunStack.erase(minrunStack.begin());
		Range y = minrunStack.at(0);
		minrunStack.erase(minrunStack.begin());
		if (x.start > y.start)
		{
			swap(x.start, y.start);
			swap(x.length, y.length);
		}
		if (y.start != x.start + x.length)
		{
			minrunStack.push_back(y);
			minrunStack.push_back(x);
			continue;
		}
		merge(array, x.start, x.length, y.start, y.length);
		x.length = x.length + y.length;
		minrunStack.push_back(x);
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int n;
	cin >> n;
	int* arr = new int[n];
	random_arr(arr, n);
	int* arr1 = arr;
	int* arr2 = arr;
	//arr_out(arr, n);
	double start_time = clock();
	BubbleSort_Iverson(arr, n);
	//arr_out(arr, n);
	cout << endl;
	cout << "На сортировку простого обмена (пузырек) с условием Айверсона потребовалось: " << endl << (double)(clock() - start_time) / CLOCKS_PER_SEC << " сек." << endl;
	start_time = clock();
	ShakerSort(arr1, 1, n);
	//arr_out(arr1, n);
	cout << "На шейкерную сортировку потребовалось: " << endl << (double)(clock() - start_time) / CLOCKS_PER_SEC << " сек." << endl;
	start_time = clock();
	Timsort(arr2, n);
	//arr_out(arr2, n);
	cout << "На TimSort потребовалось: " << endl << (double)(clock() - start_time) / CLOCKS_PER_SEC << " сек." << endl;
}
