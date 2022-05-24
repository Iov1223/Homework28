#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Заполнение массива
template <typename T> void fillArr(T arr[], int size, int min, int max) {
	srand(time(NULL));
	for (int i = 0; i < size; i++)
		arr[i] = rand() % (max - min) + max;
}
// Вывод массива
template <typename T> void showArr(T arr[], int size) {
	cout << "[";
	for (int i = 0; i < size; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\n\n";
}

// Задача 2.                                     
template <typename T>void resizeArr(T*& arr, int size, int x) {
	int y;
	if (size == x)
		return;
	if (size > x) {
		y = size - x;
		T* tmp = new T[size - y];
		for (int i = 0; i < size - y; i++)
			tmp[i] = arr[i];
		delete[] arr;
		arr = tmp;
	}
	else {
		y = x - size;
		T* tmp = new T[size + y];
		for (int i = 0; i < size + y; i++)
			tmp[i] = arr[i];
		delete[] arr;
		arr = tmp;
	}


}

int main() {
	setlocale(LC_ALL, "Russian");
	int n, m, a, b;

	// Задача 1.
	cout << "\tЗадача 1.\nВведите размер массива \"А\": ";
	cin >> n;
	int* A = new int[n];
	fillArr(A, n, 100, 0);
	cout << "Массив  \"А\": ";
	showArr(A, n);

	cout << "Введите размер массива \"B\": ";
	cin >> m;
	int* B = new int[m];
	fillArr(B, m, 100, 0);
	cout << "Массив  \"B\": ";
	showArr(B, m);

	int* C = new int[n + m];
	for (int i = 0; i < n; i++)
		C[i] = A[i];
	for (int i = 0; i < m; i++)
		C[i + n] = B[i];
	cout << "Массив  \"C\": ";
	showArr(C, n + m);
	delete[] A;
	delete[] B;

	// Задача 2.
	cout << "\tЗадача 1.\nИзначальный массив: ";
	showArr(C, n + m);
	cout << "Введите желаемую длину массива: ";
	cin >> a;   
	resizeArr(C, n + m, a);
	showArr(C, a);
	

	return 0;
}