// Task04.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{
	double x = 2.0; //значение переменной x
	double y = 4.0; //значение переменной y
	// Константы
	double const1 = 2.55;
	double const2 = 5.44;
	double const3 = 5.6;
	double result = 0.0;
	_asm
	{
		//Выполнить расчет по формуле: 
		//(Y + 2.55*X) * (5.44/Y - X) - (Y - 5.6*X)
		finit

		//Выполняем действия из первых скобок
		fld qword ptr [y] // сначала st(0) = y
		fld qword ptr [x] // затем st(1) = y , st(0) = x
		fld qword ptr [const1] // st(0) = 2.55, st(1) = X, st(2) = Y
		fmul st(0), st(2) //в верхний регистр заносим результат от умножения
		faddp st(1), st(0) //складываем и результат будет в st(1)

		//Выполняем действия из вторых скобок
		fld qword ptr [const2] // ST(2) = (Y + 2.55*X), ST(1) = (Y + 2.55*X), ST(0) = 5.44
		fld qword ptr[y]
		fdivr st(0), st(1) // ST(0) = 5.44 / Y
		fld qword ptr[x]
		fsub st(0), st(1) //ST(0) = (5.44/Y) - X (используем ST(3) = X)

		fmulp st(1), st(0) // ST(0) = часть1 * часть2
		
		//выполняем действия из третьих скобок
		fld qword ptr [y] // сначала st(0) = y
		fld qword ptr [x] // затем st(1) = y , st(0) = x
		fld qword ptr [const3] // st(0) = 2.55, st(1) = X, st(2) = Y
		fmul st(0), st(2)
		fsub st(1), st(0) 

		 fsub st(1), st(0)

		fstp qword ptr [result]
		nop
	}
}