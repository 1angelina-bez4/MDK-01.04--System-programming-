; module3.asm - тригонометрические вычисления
.586
.MODEL FLAT, C
.DATA
    pi      dq 3.141592653589793
    half    dq 0.5
    eight   dq 8.0
    quarter dq 0.25
    two     dq 2.0
    four    dq 4.0

.CODE
CalculateTrig PROC
    push    ebp
    mov     ebp, esp
    
    finit
    
    ; cos(pi*0.5*A)
    fld     qword ptr [pi]
    fld     qword ptr [half]
    fmulp   st(1), st(0)        ; pi*0.5
    fld     qword ptr [esi]     ; A
    fmulp   st(1), st(0)        ; pi*0.5*A
    fcos                        ; cos(pi*0.5*A)
    
    ; cos((B-A)/8)
    fld     qword ptr [edi]     ; B
    fld     qword ptr [esi]     ; A
    fsubp   st(1), st(0)        ; B-A
    fld     qword ptr [eight]   ; 8
    fdivp   st(1), st(0)        ; (B-A)/8
    fcos                        ; cos((B-A)/8)
    
    ; Суммируем первые два
    faddp   st(1), st(0)        ; сумма первых двух
    
    ; 0.25*2*ctg(pi/4) = 0.5*1 = 0.5
    fld     qword ptr [quarter] ; 0.25
    fld     qword ptr [two]     ; 2
    fmulp   st(1), st(0)        ; 0.5
    
    ; Суммируем всё
    faddp   st(1), st(0)        ; окончательный результат
    
    fstp    qword ptr [ebx]     ; сохраняем
    
    pop     ebp
    ret
CalculateTrig ENDP
END