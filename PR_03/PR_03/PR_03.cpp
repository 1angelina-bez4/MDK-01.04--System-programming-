// PR_03.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{
    char vItog[10] = { 0 }; // Инициализируем нулями, размер 10
    int v4 = 76; // Десятичное число
    int vBase = 8; // Основание системы счисления (8)

    char vItog2[10] = "177"; // Исходное восьмеричное число (строка)
    int result = 0; // Хранит результат
    char vItog3[10] = { 0 }; // Результат (пятеричное число, строка)
    int vTemp = 0; // Промежуточное десятичное значение
    int vBase3 = 5; // Основание целевой системы (5)

    _asm {
        // Задание 1: 10 в 8
        lea esi, vItog + 9
        mov eax, v4
        m1 :
        xor edx, edx
            div vBase
            add dl, '0'
            mov[esi], dl
            dec esi
            cmp eax, 0
            jne m1
            mov byte ptr[esi], 0
            nop

            // Задание 2: 8 в 10
            lea esi, vItog2
            mov ebx, 0
            mov ecx, 0
            m3:
        mov al, [esi + ecx]
            cmp al, 0
            je m4
            sub al, '0'
            mov edx, ebx
            shl edx, 3
            add edx, eax
            mov ebx, edx
            inc ecx
            jmp m3
            m4 :
        mov result, ebx
            nop

            // Задание 3: 10 в 5
            mov eax, result
            lea esi, vItog3 + 9
            m9:
        xor edx, edx
            div vBase3
            add dl, '0'
            dec esi
            mov[esi], dl
            cmp eax, 0
            jne m9
            inc esi; Корректируем esi на первый символ
            mov edi, esi
            find_end :
        cmp byte ptr[edi], 0
            je add_terminator
            inc edi
            jmp find_end
            add_terminator :
        mov byte ptr[edi], 0
            nop
    }

}

