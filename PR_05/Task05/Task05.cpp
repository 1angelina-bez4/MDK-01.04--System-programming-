//#include <iostream>
//
//int main()
//{
//    double A_deg = 60.0;      // A = 60° для нечётных вариантов
//    double B_deg = 45.0;      // B = 45° (фиксированное значение)
//    double pi = 3.14159265358979323846;
//    double z = 0.0;           // результат вычислений
//
//    // Константы для вычислений
//    double const_025 = 0.25;
//    double const_200 = 2.00;
//    double const_180 = 180.0;
//
//    __asm
//    {
//        finit                   // Инициализация сопроцессора FPU
//
//        // === Шаг 1: Перевод A из градусов в радианы (A_rad = A_deg * pi / 180) ===
//        fld qword ptr[A_deg]   // st(0) = A_deg
//        fld qword ptr[pi]      // st(1) = pi
//        fmul                    // st(0) = A_deg * pi
//        fld qword ptr[const_180] // st(1) = 180.0
//        fdiv                    // st(0) = A_deg * pi / 180 → A_rad
//        fstp qword ptr[A_deg]  // Сохраняем A_rad, очищаем стек
//
//        // === Шаг 2: Перевод B из градусов в радианы (аналогично) ===
//        fld qword ptr[B_deg]   // st(0) = B_deg
//        fld qword ptr[pi]      // st(1) = pi
//        fmul                    // st(0) = B_deg * pi
//        fld qword ptr[const_180] // st(1) = 180.0
//        fdiv                    // st(0) = B_deg * pi / 180 → B_rad
//        fstp qword ptr[B_deg]  // Сохраняем B_rad, очищаем стек
//
//        // === Шаг 3: Вычисляем часть1 = 0.25 * cos(B_rad / pi) ===
//        fld qword ptr[B_deg]   // st(0) = B_rad
//        fld qword ptr[pi]      // st(1) = pi
//        fdiv                    // st(0) = B_rad / pi
//        fcos                    // st(0) = cos(B_rad / pi)
//        fld qword ptr [const_025] // st(1) = 0.25
//        fmul                    // st(0) = 0.25 * cos(B_rad / pi) → часть1
//
//        // === Шаг 4: Вычисляем часть2 = 1 + ctg(2 * A_rad) ===
//        fld qword ptr[A_deg]   // st(1) = A_rad
//        fld qword ptr[const_200] // st(2) = 2.0
//        fmul                    // st(1) = 2 * A_rad
//        ftan                    // st(1) = tan(2 * A_rad)
//        fld1                    // st(2) = 1.0
//        fdiv                    // st(1) = 1 / tan(2 * A_rad) = ctg(2 * A_rad)
//        fld1                    // st(2) = 1.0
//        fadd                    // st(1) = 1 + ctg(2 * A_rad) → часть2
//
//        // === Шаг 5: Деление часть1 / часть2 ===
//        fdivr                   // st(0) = часть1 / часть2 (правильный порядок операндов)
//
//        // === Шаг 6: Вычисляем часть3 = 0.25 * 2 * ctg(pi/4) ===
//        // Примечание: tan(pi/4) = 1 → ctg(pi/4) = 1
//        fld qword ptr[const_025] // st(1) = 0.25
//        fld qword ptr[const_200] // st(2) = 2.0
//        fmul                    // st(1) = 0.5
//        // ctg(pi/4) = 1, поэтому умножение на 1 пропускаем
//        // Результат: 0.5
//
//        // === Шаг 7: Сложение результатов: (часть1/часть2) + 0.5 ===
//        fadd                    // st(0) = итоговый результат
//
//        // === Шаг 8: Сохранение результата ===
//        fstp qword ptr[z]      // z = результат вычислений
//
//        fwait                   // Синхронизация сопроцессора
//    }
//
//    std::cout << "Результат z = " << z << std::endl;
//    return 0;
//}