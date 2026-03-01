// PR_04.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
	_asm
	{
		//Сложить с числом 14 последовательность вида 9, 13, 17, ..., пока результат станет 289 или больше. 
		// Определить, сколько членов последовательности было использовано.

		mov eax, 14 //начала счета
		mov ebx, 9 //хранит последовательность 
		mov ecx, 0 //счетчик

		m1:

		add eax, ebx
		cmp eax, 289
		jge m2
		inc ecx
		add ebx, 4
		jmp m1

		m2:

		nop

	}
}