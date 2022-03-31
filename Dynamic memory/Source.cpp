// Персональный шаблон проекта С++
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

template <typename T> void showArr(T arr[], int length) {
	cout << "[";
	for (int i = 0; i < length; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\n";
}
template <typename T> void fillArr(T arr[], int length, int min = 0, int max = 100) {
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (max - min) + min;
}
template <typename T> T* addEl(T arr[], unsigned int &length, int n) {
	if (n <= 0) 
		return arr;
	T* tmp = new T[length];
	for (int i = 0; i < length; i++)
		tmp[i] = arr[i];
	delete[] arr;
	arr = new T[length + n];
	length += n;
	for (int i = 0; i < length - n; i++)
		arr[i] = tmp[i];
	delete[] tmp;
	return arr;
}
template <typename T> T* delEl(T arr[], unsigned int& length, int n) {
	if (n <= 0 || n >= length)
		return arr;
	length -= n;
	T* tmp = new T[length];
	for (int i = 0; i < length; i++)
		tmp[i] = arr[i];
	delete[] arr;
	arr = new T[length];
	for (int i = 0; i < length; i++)
		arr[i] = tmp[i];
	delete[] tmp;
	return arr;
}



int main() {
	setlocale(LC_ALL, "Russian");

	int X;
	int* px = &X; // обычный указатель

	int* pn = new int; // оператор выделения памяти new
	*pn = 10;

	cout << pn << " - " << *pn << endl;

	delete pn; // ячейка оперативной памяти освобождается, но указатель продолжает хранить адрес ячейки
	// 0, NULL, nullptr
	pn = nullptr;
	if (pn != nullptr)
		cout << pn << " - " << *pn << endl;


	const int L = 5;
	int arr[L];
	unsigned int n;
	cout << "Введите длину массива: ";
	cin >> n;
	int* dArr = new int[n];
	for (int i = 0; i < n; i++)
		dArr[i] = i + 1;
	showArr(dArr, n);

	delete[] dArr;
	dArr = nullptr;

	cout << "Задача 1\nВведите длину массива: ";
	unsigned int length;
	cin >> length;
	int* z1 = new int[length];
	fillArr(z1, length);
	showArr(z1, length);
	cout << "Насколько увеличить массив? ";
	int a;
	cin >> a;
	z1 = addEl(z1, length, a);
	showArr(z1, length);
	delete[] z1;

	cout << "Задача 2\nВведите длину массива: ";
	unsigned int length2;
	cin >> length2;
	int* z2 = new int[length2];
	fillArr(z2, length2, 10, 50);
	showArr(z2, length2);
	z2 = delEl(z2, length2, 3);
	showArr(z2, length2);





	return 0;
}