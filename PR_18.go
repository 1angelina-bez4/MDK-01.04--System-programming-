package main

import (
	"fmt"
	"strings"
)

func main() {

    fmt.Println("Задание 1")
    fmt.Println("Из пяти целых различных ненулевых положительных и отрицательных чисел найти самое наибольшее число.")

    var(
        numb1 int
        numb2 int
        numb3 int
        numb4 int
        numb5 int 

        max int
    )

    fmt.Println("Введите первое целое, ненулевое число:")
    fmt.Scan(&numb1)

    fmt.Println("Введите второе целое, ненулевое число:")
    fmt.Scan(&numb2)

    fmt.Println("Введите третье целое, ненулевое число:")
    fmt.Scan(&numb3)

    fmt.Println("Введите четвертое целое, ненулевое число:")
    fmt.Scan(&numb4)

    fmt.Println("Введите пятое целое, ненулевое число:")
    fmt.Scan(&numb5)
    if numb1==0 || numb2==0 || numb3==0 || numb4==0 || numb5==0{
        fmt.Println("Ошибка! Одно из чисел является нулевым")
        return
    }

    numbers := []int{numb1, numb2, numb3, numb4, numb5}
    for i := 0; i < len(numbers); i++ {
        for j := i + 1; j < len(numbers); j++ {
            if numbers[i] == numbers[j] {
                fmt.Println("Ошибка: числа должны быть различными!")
                return
            }
        }
    }


    max = numb1
    if numb2 > max {
        max = numb2
    }
    if numb3 > max {
        max = numb3
    }
    if numb4 > max {
        max = numb4
    }
    if numb5 > max {
        max = numb5
    }

    fmt.Printf("Наибольшее число: %d\n", max)

    fmt.Println("Задание 2")
    fmt.Println("Даны семь целых ненулевых положительных чисел. Найти сумму четырех наибольших чисел.")

    var arr [7]int
    for i := 0; i < 7; i++ {
        fmt.Printf("Введите элемент %d: ", i+1)
        fmt.Scan(&arr[i])
        
        if arr[i]==0 || arr[i]<0 {
            fmt.Println("Ошибка: числа должны быть положительными и ненулевыми!")
            return
        }
    }
    sort.Sort(sort.Reverse(sort.IntSlice(arr[:])))

    var sum4 int
    for i := 0; i < 4; i++ {
        sum4 += arr[i]
    }

    fmt.Printf("Сумма четырех наибольших чисел равна: %d\n", sum4)

    fmt.Println("Задание 3")
    fmt.Println("Из пяти введенных целых положительных чисел найти два наибольших и вывести произведение этих двух наибольших чисел.")
   
    
    var arr2 [5]int
    for i := 0; i < 5; i++ {
        fmt.Printf("Введите элемент %d: ", i+1)
        fmt.Scan(&arr2[i])
        
        if  arr2[i]<=0 {
            fmt.Println("Ошибка: числа должны быть положительными!")
            return
        }
    }

    // Ints - Сортировка по возрастанию
    sort.Ints(arr2[:])

    //два наибольших числа
    max1 := arr2[4]
    max2 := arr2[3]  

    proiz := max1 * max2
    fmt.Printf("Два наибольших числа: %d и %d\n", max1, max2)
    fmt.Printf("Произведение двух наибольших чисел: %d\n", proiz)

    fmt.Println("Задание 4")
    fmt.Println("Ввести целое положительное число. Проверить истинность высказывания: 'Данное целое число является четным двузначным числом'.")

    var number_input int
    fmt.Println("Введите целое положительное число:")
    fmt.Scan(&number_input)

    if number_input<=0{
        fmt.Println("Ошибка: число должно быть положительными!")
        return
    }

    if number_input%2==0 && number_input>=10 && number_input<=99{
        fmt.Println("Высказывание является истинным.")
    }
    else {
         fmt.Println("Высказывание является ложным.")
    }

    fmt.Println("Задание 5")
    fmt.Println("Дан номер месяца N - целое число положительное в диапазоне от 1 до 12 (1 - январь, 2 - февраль, ..., 12 - декабрь). Вывести название соответствующего времени года («зима», «весна», «лето», «осень»).")


    var N int
    fmt.Println("Введите номер месяца N - целое число положительное в диапазоне от 1 до 12:")
    fmt.Scan(&N)

    switch N {
    case 12,1,2:
        fmt.Println("Время года - зима")
    case 3,4,5:
        fmt.Println("Время года - весна")   
    case 6,7,8:
        fmt.Println("Время года - лето") 
    case 9,10,11:
        fmt.Println("Время года - осень")
    default:
		//Отрабатывает только в том случае, если не один из выше перечисленных кейсов - не сработал
		fmt.Println("Ошибка! Номер месяца N - целое число положительное в диапазоне от 1 до 12")
    }
    
}