// task03 - z = cos(pi*0.5*A) + cos((B-A)/8) + 0.25*2*ctg(pi/4)


#include <stdio.h>
#include <tchar.h>

extern "C" void CalculateTrig();

int _tmain(int argc, _TCHAR* argv[])
{
    char vPrompt1[] = "\nVvedite A:\n";
    char vPrompt2[] = "Vvedite B:\n";
    char vFormat[] = "%lf";
    double vA = 0, vB = 0;
    double vResult = 0;
    char vOutput[] = "\nRezultat Z: %lf\n";

    _asm
    {
        finit

        //Ввод A
        lea     eax, vPrompt1
        push    eax
        call    printf
        add     esp, 4

        lea     eax, vA
        push    eax
        lea     eax, vFormat
        push    eax
        call    scanf
        add     esp, 8

        //Ввод B
        lea     eax, vPrompt2
        push    eax
        call    printf
        add     esp, 4

        lea     eax, vB
        push    eax
        lea     eax, vFormat
        push    eax
        call    scanf
        add     esp, 8

        //Вызов процедуры расчета
        lea     esi, vA
        lea     edi, vB
        lea     ebx, vResult
        call    CalculateTrig

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