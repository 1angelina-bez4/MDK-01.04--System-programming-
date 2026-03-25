// PR15.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");

    printf("Задание 1\n");
    printf("\nПроверить истинность высказывания: Квадратное уравнение A·x2 + B·x + C = 0 с данными коэффициентами A(A не равно 0), B, C не имеет вещественных корней.\n");
    double A, B, C;
    double D;

m1:
    printf("Введите коэффициент A (A != 0): ");
    scanf_s("%lf", &A);

    if (A == 0)
    {
        printf("Ошибка! Коэффициент A не может быть равен 0.\n");
        goto m1;
    }

    printf("Введите коэффициент B: ");
    scanf_s("%lf", &B);
    printf("Введите коэффициент C: ");
    scanf_s("%lf", &C);

    D = B * B - 4 * A * C;

    printf("Уравнение: %.2lf*x^2 + %.2lf*x + %.2lf = 0\n", A, B, C);
    printf("Дискриминант D = %.2lf\n", D);

    if (D > 0)
    {
        printf("\nВысказывание ИСТИННО: уравнение имеет два различных вещественных корня.\n");
    }
    else
    {
        printf("\nВысказывание ЛОЖНО: уравнение НЕ имеет двух различных вещественных корней.\n");
        if (D == 0)
            printf("(Дискриминант равен 0 - один корень)\n");
        else
            printf("(Дискриминант меньше 0 - нет вещественных корней)\n");
    }

m2:
    printf("\nЗадание 2\n");
    printf("С некоторого момента прошло N недель (N > 0). Сколько полных дней прошло за этот период?\n");

    int N;
    int day;
    printf("Введите количество пройденных недель N (N > 0):\n");
    scanf_s("%d", &N);

    if (N < 0)
    {
        printf("Ошибка!Количество недель должно быть больше 0.\n");
        goto m2;
    }
    else
    {
        day = N * 7;
        printf("Всего дней прошло: %d", day);
    }

m3:
    printf("\nЗадание 3\n");
    printf("Дан целочисленный массив, состоящий из N элементов (N > 0). Поменять местами минимальный и максимальный элемент этого массива. Вывести новый полученный массив.\n");

    int N1 = 0;
    int* array = new int[N1];
    int min_idx = 0;
    int max_idx = 0;
    printf("Введите  число  элементов массива N (N > 0):\n");
    scanf_s("%d", &N1);

    if (N1 <= 0)
    {
        printf("Ошибка! N должно быть больше 0.\n");
        goto m3;
    }

    for (int i = 0; i < N1; i++)
    {
        printf("Введите элемент %d: \n", i + 1);
        scanf_s("%d", &array[i]);
    }

    for (int i = 1; i < N1; i++) {
        if (array[i] < array[min_idx]) {
            min_idx = i;
        }
        if (array[i] > array[max_idx]) {
            max_idx = i;
        }
    }

    int temp = array[min_idx];
    array[min_idx] = array[max_idx];
    array[max_idx] = temp;

    // Вывод результата
    for (int i = 0; i < N1; i++) {
        printf("%d ", array[i]);
    }


    printf("\n Задание 4\n");
    char str4[1024];
    int replacements = 0;

    printf("Введите строку-предложение: ");
    scanf_s("%s1023", str4, 1024);

    printf("Исходное предложение: \"%s\"\n", str4);

    int len = strlen(str4);
    // Цикл идет по каждому второму символу (индексы 1, 3, 5...)
    for (int i = 1; i < len; i += 2) {
        str4[i] = '%';
        replacements++;
    }

    printf("Измененное предложение: \"%s\"\n", str4);
    printf("Общее количество замен: %d\n", replacements);

    printf("\n Задание 5\n");
    printf("Вводится строка, слова через _. Определить кол-во слов, где 2-й и последний символы совпадают.\n");

    char str5[1024];
    int wordCount = 0;

    printf("Введите строку: ");
    scanf_s("%s1023", str5, 1024);
    // Убираем символ переноса строки \n, который добавляет fgets
    str5[strcspn(str5, "\n")] = '\0';

    int i = 0;
    int n = strlen(str5);

    while (i < n) {
        // 1. Пропускаем ведущие подчеркивания
        while (i < n && str5[i] == '_') {
            i++;
        }

        // Если дошли до конца строки
        if (i >= n) break;

        // 2. Нашли начало слова
        int start = i;
        while (i < n && str5[i] != '_') {
            i++;
        }
        // Теперь i указывает на символ после слова (разделитель или \0)
        int end = i - 1;
        int len = end - start + 1;

        // 3. Проверяем условие задачи для найденного слова
        if (len >= 2) {
            // str5[start + 1] — второй символ слова
            // str5[end] — последний символ слова
            if (str5[start + 1] == str5[end]) {
                wordCount++;
            }
        }
    }

    printf("Количество подходящих слов: %d\n", wordCount);
}
