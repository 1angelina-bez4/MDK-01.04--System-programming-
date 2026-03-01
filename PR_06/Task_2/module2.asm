; module2.asm - расчет по формуле (Y + 3.54/X) * (X - 6.31*Y) - (1.67*X - Y)
.586
.MODEL FLAT, C
.DATA
    c354    dq 3.54
    c631    dq 6.31
    c167    dq 1.67

.CODE
CalculateFormula PROC
    push    ebp
    mov     ebp, esp
    
    finit
    
    fld     qword ptr [esi]      ; X
    fld     qword ptr [edi]      ; Y, X
    
    ; (Y + 3.54/X)
    fld     st(1)                ; Y, Y, X
    fld     qword ptr [c354]     ; 3.54, Y, Y, X
    fdiv    st(0), st(3)         ; 3.54/X, Y, Y, X
    faddp   st(1), st(0)         ; Y+3.54/X, Y, X
    
    ; (X - 6.31*Y)
    fld     qword ptr [c631]     ; 6.31, Y+3.54/X, Y, X
    fmul    st(0), st(2)         ; 6.31*Y, Y+3.54/X, Y, X
    fld     st(3)                ; X, 6.31*Y, Y+3.54/X, Y, X
    fsub    st(0), st(1)         ; X-6.31*Y, 6.31*Y, Y+3.54/X, Y, X
    
    ; Перемножаем
    fmulp   st(2), st(0)         ; 6.31*Y, (Y+3.54/X)*(X-6.31*Y), Y, X
    fstp    st(0)                ; (Y+3.54/X)*(X-6.31*Y), Y, X
    
    ; (1.67*X - Y)
    fld     qword ptr [c167]     ; 1.67, результат1, Y, X
    fmul    st(0), st(3)         ; 1.67*X, результат1, Y, X
    fsub    st(0), st(2)         ; 1.67*X - Y, результат1, Y, X
    
    ; Вычитаем
    fsubp   st(1), st(0)         ; окончательный результат, Y, X
    
    ; Сохраняем
    fstp    qword ptr [ebx]
    
    fstp    st(0)                ; очищаем стек
    fstp    st(0)
    
    pop     ebp
    ret
CalculateFormula ENDP
END