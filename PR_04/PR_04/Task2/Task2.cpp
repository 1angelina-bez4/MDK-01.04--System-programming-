// Task2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
	//ƒан массив целых чисел. –азмер массива может быть разный. Ќайти и сохранить в регистр AL количество элементов,
	// расположенных после последнего максимального элемента в массиве.

	int arr[25] = { 1, 0, 5, 10, 0, 3, 4, 0, 7, 8, 11, 33, 365, 32, 12, 89, 21, 2, 55, 88, 100, 82, 111, 222 };

	_asm
	{
		xor esi
		lea ebx, arr //переносим массив 
		mov ecx, 25

		m1:
		add eax, 4
		cmp

	}

}
