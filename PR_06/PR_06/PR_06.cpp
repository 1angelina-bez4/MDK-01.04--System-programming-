// PR_06.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdio.h>
#include <tchar.h>

extern "C" void CalculateSum();

int _tmain(int argc, _TCHAR* argv[])
{
    //Определить, сколько последовательных вещественных чисел начиная с 3.31 
    //дадут в сумме этих чисел 378.4 или больше?

    char vOutInfo[] = "\nВведите начальное значение для задания ( 3.31 ):\n";
    char vFormat[] = "%lf"; //указываеим формат
    double vStartValue = 0; //стартовое значение 
    double vTargetSum = 378.4;  //число для сравнения
    double vResult = 0;     // сюда получим количество чисел
    char vOutput[] = "\nКоличество чисел: %lf\n";

    _asm
    {
        finit

        lea eax, vOutInfo
        push eax
        call printf  //выводим строку приглашение
        add esp, 4

        lea eax, vStartValue //получаем адрес перeменной
        push eax
        lea eax, vFormat  //адрес формата
        push eax
        call scanf  //ввод начального значения
        add esp, 8 //отчищаем

        lea esi, vStartValue //адрес начального значения
        lea edi, vTargetSum //адрес суммы
        lea ebx, vResult //адрес результата
        call CalculateSum //вызов ассемблерной процедуры
        fld qword ptr [vResult] //загружаем результат
        sub esp, 8 //отчищаем место в стеке
        fstp qword ptr [esp] //помещаем результат в стек
        lea eax, vOutput
        push eax
        call printf
        add esp, 0Ch // т.к использовали 12 байтов в стеке, то "балансируем" его
        jmp m100

m100:
        nop
        fwait
    }
}
