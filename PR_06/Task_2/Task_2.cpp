// task02 - Выполнить расчет по формуле: (Y + 3.54/X) * (X - 6.31*Y) - (1.67*X - Y)

#include <stdio.h>
#include <tchar.h>

extern "C" void CalculateFormula();

int _tmain(int argc, _TCHAR* argv[])
{
    char vPrompt1[] = "\nVvedite X:\n";
    char vPrompt2[] = "Vvedite Y:\n";
    char vFormat[] = "%lf";
    double vX = 0, vY = 0;
    double vResult = 0;
    char vOutput[] = "\nRezultat: %lf\n";

    _asm
    {
        finit

        //Ввод X
        lea     eax, vPrompt1
        push    eax
        call    printf
        add     esp, 4

        lea     eax, vX
        push    eax
        lea     eax, vFormat
        push    eax
        call    scanf
        add     esp, 8

        //Ввод Y
        lea     eax, vPrompt2
        push    eax
        call    printf
        add     esp, 4

        lea     eax, vY
        push    eax
        lea     eax, vFormat
        push    eax
        call    scanf
        add     esp, 8

        //Вызов процедуры расчета
        lea     esi, vX
        lea     edi, vY
        lea     ebx, vResult
        call    CalculateFormula

        //Вывод результата
        fld     qword ptr[vResult]
        sub     esp, 8
        fstp    qword ptr[esp]
        lea     eax, vOutput
        push    eax
        call    printf
        add     esp, 0Ch
        jmp m100
m100 :
        nop
        fwait
    }
    return 0;
}