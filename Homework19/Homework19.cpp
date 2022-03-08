#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int devider(int num1, int num2);
int resurveNumber(int num1);
int returnFirstPositionOfN(int array[], int length, int N);
void showArray(int array[], int length);
void fillArray(int array[], int length, int A, int B);

int main() {
	setlocale(LC_ALL, "Russian");

	int n, m;

	// Задача 1

	cout << "Задача 1.\nВведите два числа a и b -> ";
	cin >> n >> m;

	cout << "Наибольший общий делитель этих чисел: " << devider(n, m) << endl;

	// Задача 2

	cout << "\nЗадача 2.\nВведите число: ";
	cin >> n;
	cout << "Возвращаемое значение: " << resurveNumber(n) << endl;


	// Задача 3

	int array[6] = { 5, 9, 7, 11, -5, 0 };

	cout << "\nЗадача 3.\nИзначальный массив: ";
	showArray(array, 6);

	cout << "Введите число N: ";
	cin >> n;

	cout << "Первая позиция числа N: " << returnFirstPositionOfN(array, 6, n) << endl;

	cout << "Отсортированный массив: ";
	showArray(array, 6);

	// Задача 4

	srand(time(NULL));

	int emptyArray[10];
	cout << "\nЗадача 4.\nВведите числа A и B: ";
	cin >> n >> m;

	if (n > m)
		swap(n, m);

	fillArray(emptyArray, 10, n, m);

	cout << "Заполненный массив: ";
	showArray(emptyArray, 10);

	return 0;
}

// Задача 4

void fillArray(int array[], int length, int A, int B) {
	for (int i = 0; i < length; i++)
		array[i] = rand() % (B+1 - A) + A;
}

// Задача 3

void showArray(int array[], int length) {
	cout << "[";
	for (int i = 0; i < length; i++)
		cout << array[i] << ", ";
	cout << "\b\b]" << endl;
}

int returnFirstPositionOfN(int array[], int length, int N) {
	int start = 0;

	for (int i = 0; i < length; i++) {
		if (N == array[i])
			start = i;
	}

	if (start == 0) {

		for (int i = 0; i < length; i++) {
			for (int j = start + 1; j < length - start - 1; j++) {

				if (array[j] > array[j + 1]) {
					int tmp = array[j];
					array[j] = array[j + 1];
					array[j + 1] = tmp;
				}
			}
		}
	}
	else
		if (start == 1)
			for (int i = 0; i < length; i++) {
				for (int j = start + 1; j < length - start; j++) {
					if (array[j] > array[j + 1]) {
						int tmp = array[j];
						array[j] = array[j + 1];
						array[j + 1] = tmp;
					}
				}
			}
		else 
			if (start == 2)
				for (int i = 0; i < length; i++) {
					for (int j = start + 1; j < length - start + 1; j++) {
						if (array[j] > array[j + 1]) {
							int tmp = array[j];
							array[j] = array[j + 1];
							array[j + 1] = tmp;
						}
					}
				}
			else
				if (start == 3)
					for (int i = 0; i < length; i++) {
						for (int j = start + 1; j < length - start; j++) {
							if (array[j] > array[j + 1]) {
								int tmp = array[j];
								array[j] = array[j + 1];
								array[j + 1] = tmp;
							}
						}
					}
				else
					if (start == 4)
						for (int i = 0; i < length; i++) {
							for (int j = start + 1; j < length - start + 1; j++) {
								if (array[j] > array[j + 1]) {
									int tmp = array[j];
									array[j] = array[j + 1];
									array[j + 1] = tmp;
								}
							}
						}
					else
						if (start == 5)
							for (int i = 0; i < length; i++) {
								for (int j = start + 1; j < length - start; j++) {
									if (array[j] > array[j + 1]) {
										int tmp = array[j];
										array[j] = array[j + 1];
										array[j + 1] = tmp;
									}
								}
							}
	return start;
}

// Задача 2

int resurveNumber(int num1) {
	int length = 1;


	if (num1 % 100000 <= 99999 && num1 % 100000 > 9999)
		length = -1;
	else
		if (num1 % 10000 <= 9999 && num1 % 10000 > 999)
			length = 4;
		else
			if (num1 % 1000 <= 999 && num1 % 1000 > 99)
				length = 3;
			else
				if (num1 % 100 <= 99 && num1 % 100 > 9)
					length = 2;
				else
					if (num1 % 10 <= 9 && num1 % 10 > 0)
						length = 1;



	if (length == -1)
		return -1;


	cout << "Длина числа: " << length << endl;


	if (length == 4) {
		for (int i = 0; i < 1; i++) {
			int tempArray[4];
			tempArray[0] = num1 / 1000 % 10;
			tempArray[1] = num1 / 100 % 10;
			tempArray[2] = num1 / 10 % 10;
			tempArray[3] = num1 % 10;
			num1 = tempArray[3] * 1000 + tempArray[2] * 100 + tempArray[1] * 10 + tempArray[0];
		}
	}
	else
		if (length == 3) {
			for (int i = 0; i < 1; i++) {
				int tempArray[3];
				tempArray[0] = num1 / 100 % 10;
				tempArray[1] = num1 / 10 % 10;
				tempArray[2] = num1 % 10;
				num1 = tempArray[2] * 100 + tempArray[1] * 10 + tempArray[0];
			}
		}
		else
			if (length == 2) {
				for (int i = 0; i < 1; i++) {
					int tempArray[2];
					tempArray[0] = num1 / 10 % 10;
					tempArray[1] = num1 % 10;
					num1 = tempArray[1] * 10 + tempArray[0];
				}
			}
			else
				if (length == 1) {
					int tempArray[1];
					tempArray[0] = num1 % 10;
					num1 = tempArray[0];
				}
	

	return num1;
}

// Задача 1

int devider(int num1, int num2) {
	int max = 0;
	int devider = 0;
	if (num1 >= num2)
		max = num1;
	else
		max = num2;
	for (int i = 1; i <= max/2; i++)
		if (num1 % i == 0 && num2 % i == 0)
			devider = i;
	return devider;
}