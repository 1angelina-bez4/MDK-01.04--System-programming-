// Task03.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
   //. Дан массив целых чисел. 
   // Размер массива может быть разный. 
   // Найти и сохранить в регистр AX сумму 
   // всех положительных элементов массива, 
   // отбросив при этом значения 2 и 5.
	
	int arr[25] = { 1, 0, 5, 10, 0, 3, 4, 0, 7, 8, 11, 33, 365, 32, 12, 89, 21, 2, 55, 88, 100, 82, 111, 222 };

	__asm
	{
		xor ebx, ebx //сумма
		mov ecx, 25
		lea eax, arr

m1:

		cmp [eax], 02
		je m2

		cmp [eax], 05
		je m3

		add  ebx, [eax]
		add eax, 4 //переходим  к  другому элементу 
		dec ecx
		cmp ecx, 0
		je end
		jmp m1

m2:
m3:
		add eax, 4 
		dec ecx
		cmp ecx, 0 
		je end
		jmp m1

end:
		nop
	}
}
