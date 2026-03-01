// task03.cpp - Шифрование ФИО двухсловным ROL (вариант 5)
#include <stdio.h>
#include <tchar.h>

// Ваше ФИО (те же данные, что и в task01)
char vMyMessage[] = "Безрукова_Ангелина_Олеговна";

// Ключ для ROL (количество битов для сдвига)
unsigned short vShiftKey = 3; // сдвиг на 3 бита

int _tmain(int argc, _TCHAR* argv[])
{
	printf("Исходное сообщение: %s\n", vMyMessage);

	_asm
	{
		sub ecx, ecx
		mov edx, 27		// длина сообщения(количество байт)
		lea esi, vMyMessage		// адрес первого кодируемого символа
		mov cx, vShiftKey		// это ключ шифрования
		sub eax, eax
m100 :
		mov ax, word ptr[esi]	// загружаем 2 байта на регистр
		rol ax, cl		//шифруем(циклический сдвиг влево)
		mov word ptr[esi], ax		// зашифрованное слово на место
		add esi, 2					// продвигаем адрес на 2 байта
		sub edx, 2				// уменьшаем счетчик на 2
		cmp edx, 1				// остался 1 байт ?
		je m101					// если да - обрабатываем отдельно
		cmp edx, 0				// все обработали ?
		jne m100				// если нет - продолжаем цикл
		jmp m200				// если да - переходим к расшифровке

m101 :
		mov al, byte ptr[esi]			// последний байт на регистр
		rol al, cl					// шифруем
		mov byte ptr[esi], al			// зашифрованный байт на место
		sub edx, 1				// уменьшаем счетчик
m200 :
		nop

		//расшифровка ROR(циклический сдвиг вправо)
		mov edx, 27				// восстанавливаем длину
		lea esi, vMyMessage			// адрес первого символа
		mov cx, vShiftKey			// тот же ключ
		sub eax, eax
m300 :
		mov ax, word ptr[esi]			// загружаем 2 байта
		ror ax, cl						// расшифровываем(циклический сдвиг вправо)
		mov word ptr[esi], ax			// расшифрованное слово на место
		add esi, 2						// продвигаем адрес на 2 байта
		sub edx, 2						// уменьшаем счетчик на 2
		cmp edx, 1						// остался 1 байт ?
		je m301							// если да - обрабатываем отдельно
		cmp edx, 0						// все обработали ?
		jne m300						// если нет - продолжаем цикл
		jmp m400						// если да - завершаем

m301 :
		mov al, byte ptr[esi]			// последний байт
		ror al, cl						//расшифровываем
		mov byte ptr[esi], al			//расшифрованный байт на место
		sub edx, 1						// уменьшаем счетчик
m400 :
		nop

	printf("Расшифрованное сообщение: %s\n", vMyMessage);

	getchar();
	return 0;
}