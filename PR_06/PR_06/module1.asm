; module1.asm - процедура расчета количества последовательных чисел
.586
.MODEL FLAT, C
.DATA
    step        dq 1.0

.CODE
CalculateSum PROC
    push    ebp
    mov     ebp, esp
    push    ecx
    
    finit
    
    fld     qword ptr [esi]         ; текущее слагаемое
    fldz                            ; сумма = 0
    
    mov     ecx, 0                  ; счетчик
    
sum_loop:
    fadd    st(0), st(1)            ; сумма = сумма + слагаемое
    inc     ecx
    
    fcomp   qword ptr [edi]         ; сравниваем с целевой суммой
    fnstsw  ax
    sahf
    jae     found
    
    fld     qword ptr [step]        ; шаг = 1
    faddp   st(1), st(0)            ; слагаемое = слагаемое + 1
    jmp     sum_loop
    
found:
    fstp    st(0)                   ; очищаем стек
    fstp    st(0)
    
    fild    dword ptr [ecx]         ; счетчик в вещественное
    fstp    qword ptr [ebx]         ; сохраняем результат
    
    pop     ecx
    pop     ebp
    ret
CalculateSum ENDP
END