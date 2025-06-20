﻿//ОДНОМЕРНЫЕ МАССИВЫ
// 
//_________________________________________________________________________________________________________________________
//Одномерные массивы 1
//Дано натуральное число n ≥ 10, целочисленная последовательность a1, a2, … an.
//Получить число положительных членов последовательности a1, a2, …, an - 5 и общее число нулей всей последовательности.

#include <iostream>
#include <locale.h>

using namespace std;

int main() {

    setlocale(LC_ALL, "Russian");

    int n;
    cout << "Введите n (n >= 10): ";
    cin >> n;

    // Проверка корректности введённого значения
    if (n < 10) {
        cout << "Ошибка: n должно быть >= 10!" << endl;
        return 1;
    }
    int *a = new int[n];
    cout << "Введите " << n << " элементов последовательности:" << endl;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    /* 1. Подсчёт положительных чисел в первых (n-5) элементах
               (от a[0] до a[n-6] включительно) */

    int p_count = 0;  // Счётчик положительных чисел
    for (int i = 0; i < n - 5; ++i) {
        if (a[i] > 0) {  // Проверка на положительность
            p_count++;
        }
    }

    /*2. Подсчёт нулей во всей последовательности
                (от a[0] до a[n-1] включительно) */

    int zero_count = 0;  // Счётчик нулевых элементов
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) {  // Проверка на равенство нулю
            zero_count++;  // Увеличение счётчика
        }
    }

    cout << "Число положительных членов в a₁..aₙ₋₅: " << p_count << endl;
    cout << "Общее число нулей в последовательности: " << zero_count << endl;

    delete[] a;

    return 0;
}

//_________________________________________________________________________________________________________________________
//Одномерные массивы 2
//Даны натуральное число n, действительные числа a1, a2, … an.
//Вычислить: -a1 / 1!+ a2 / 2!+ …, +(-1¬n) an / n!.

#include <iostream>
#include <cmath> // Для pow (возведения в степень)
#include <locale.h>

using namespace std;

// Функция для вычисления факториала числа
long long factorial(int k) {
    long long fact = 1;  // Инициализация результата

    // Цикл умножения чисел от 1 до k
    for (int i = 1; i <= k; ++i) {
        fact *= i;       // Умножение на текущее число
    }
    return fact;         // Возврат вычисленного факториала
}

int main() {

    setlocale(LC_ALL, "Russian");

    int n;
    cout << "Введите натуральное число n: ";
    cin >> n;

    // Проверка, что n - натуральное число
    if (n <= 0) {
        cout << "Ошибка: n должно быть натуральным числом!" << endl;
        return 1;
    }

    double *a = new double[n];

    cout << "Введите " << n << " действительных чисел a1, a2, ..., an:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];  // Чтение i-го элемента
    }
    // Вычисление суммы ряда
    double sum = 0.0;

    for (int k = 1; k <= n; ++k) {
        // Вычисление k-го члена ряда: (-1)^k * ak / k!
        // a[k-1] потому что индексация массива начинается с 0

        double term = pow(-1, k) * a[k - 1] / factorial(k);
        sum += term;  // Добавление члена к сумме
    }

    cout << "Результат: " << sum << endl;

    delete[] a;

    return 0;
}

//_________________________________________________________________________________________________________________________
//Одномерные вопросы 3
//Дано натуральное число n ≥ 2, целочисленная последовательность a1, a2, … an
//Получить сумму членов последовательности с четными номерами и произведение членов последовательности с нечетными номерам.

#include <iostream>
#include <locale.h>

using namespace std;

int main() {

    setlocale(LC_ALL, "Russian");

    int n;
    cout << "Введите натуральное число n (n >= 2): ";
    cin >> n;

    if (n < 2) {
        cout << "Ошибка: n должно быть >= 2!" << endl;
        return 1;
    }

    int *a = new int[n]; // Создаем массив для последовательности

    cout << "Введите " << n << " целых чисел последовательности:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Вычисляем сумму элементов с четными номерами (индексы 1, 3, 5...)
    int sum_even = 0;
    for (int i = 1; i < n; i += 2) {
        sum_even += a[i];
    }

    // Вычисляем произведение элементов с нечетными номерами (индексы 0, 2, 4...)
    long long element_nechet = 1; // Используем long long для избежания переполнения
    for (int i = 0; i < n; i += 2) {
        element_nechet *= a[i];
    }

    cout << "Сумма элементов с четными номерами: " << sum_even << endl;
    cout << "Произведение элементов с нечетными номерами: " << element_nechet << endl;

    delete[] a; // Освобождаем память
    return 0;
}

//_________________________________________________________________________________________________________________________
//Одномерные массивы 7
//Даны натуральное число n, последовательность целых чисел a1, a2, … an.
//Получить из нее новую последовательность удалив из исходной все значения
//max(a1, a2, … an.).

#include <iostream>
#include <locale.h>

using namespace std;

int main() {

    setlocale(LC_ALL, "Russian");

    int n;

    cout << "Введите количество элементов n: ";
    cin >> n;

    if (n <= 0) {
        cout << "Ошибка: n должно быть натуральным числом!" << endl;
        return 1;
    }

    int *a = new int[n];

    cout << "Введите " << n << " целых чисел: ";
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    // Нахождение максимального элемента в массиве
    int max_val = a[0];  // Предполагаем, что первый элемент - максимальный
    for (int i = 1; i < n; ++i) {
        if (a[i] > max_val) {
            max_val = a[i];  // Обновляем максимальное значение, если нашли больше
        }
    }

    // Подсчет количества максимальных элементов в массиве
    int count_max = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == max_val) {
            count_max++;  // Увеличиваем счетчик при нахождении максимального элемента
        }
    }

    // Создание нового массива без максимальных элементов
    int new_size = n - count_max;  // Размер нового массива
    int *new_a = new int[new_size];  // Выделение памяти под новый массив
    int index = 0;  // Индекс для заполнения нового массива

    // Заполнение нового массива элементами, кроме максимальных
    for (int i = 0; i < n; ++i) {
        if (a[i] != max_val) {
            new_a[index++] = a[i];  // Копируем элемент, если он не максимальный
        }
    }

    cout << "Новая последовательность без максимальных элементов (" << max_val << "):" << endl;
    for (int i = 0; i < new_size; ++i) {
        cout << new_a[i] << " ";
    }
    cout << endl;

    delete[] a;
    delete[] new_a;

    return 0;
}

//_________________________________________________________________________________________________________________________
//Одномерные процессы 5
//Дано натуральное число n ≥ 3, целочисленная последовательность a1, a2, … an.
//Получить последовательность :
//| a1 | , | a1 + a2 | , …, | a1 + a2 + … + an |

#include <iostream>
#include <cmath> // Для функции abs()
#include <locale.h>

using namespace std;

int main() {

    setlocale(LC_ALL, "Russian");

    int n;

    cout << "Введите натуральное число n (n >= 3): ";
    cin >> n;


    if (n < 3) {
        cout << "Ошибка: n должно быть >= 3!" << endl;
        return 1;
    }

    int *a = new int[n];

    cout << "Введите " << n << " целых чисел последовательности:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Создание нового массива для преобразованной последовательности
    int* new_seq = new int[n];
    int sum = 0;  // Переменная для накопления суммы элементов

    // Вычисление новой последовательности
    for (int i = 0; i < n; ++i) {
        sum += a[i];              // Добавляем текущий элемент к сумме
        new_seq[i] = abs(sum);    // Записываем модуль суммы в новый массив
    }

    cout << "Новая последовательность:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << new_seq[i] << " ";
    }
    cout << endl;

    delete[] a;
    delete[] new_seq;

    return 0;
}

//_________________________________________________________________________________________________________________________
//Одномерный массив
//Даны натуральное число n и целые числа a1, a2, …, an.Все члены последовательности с четными номерами, предшествующие первому по порядку члену со значением max(a1, a2, …, an.) умножить на max(a1, a2, …, an.)

#include <iostream>
#include <climits> // Для INT_MIN
#include <locale.h>

using namespace std;

int main() {

    setlocale(LC_ALL, "Russian");

    int n;

    cout << "Введите натуральное число n: ";
    cin >> n;

    if (n <= 0) {
        cout << "Ошибка: n должно быть натуральным числом!" << endl;
        return 1;
    }

    int *a = new int[n];

    // Запрос на ввод элементов массива
    cout << "Введите " << n << " целых чисел:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];  // Считывание каждого элемента массива
    }

    // Находим максимальный элемент и его первую позицию
    int max_val = INT_MIN;      // Инициализация минимально возможным значением
    int first_max_pos = -1;     // Позиция первого максимума (пока не найдена)

    for (int i = 0; i < n; ++i) {
        if (a[i] > max_val) {   // Если текущий элемент больше известного максимума
            max_val = a[i];      // Обновляем значение максимума
            first_max_pos = i;   // Запоминаем позицию первого вхождения
        }
    }

    // Умножаем четные элементы (в 1-ной нумерации) перед первым максимумом на max_val
    for (int i = 0; i < first_max_pos; ++i) {
        if ((i + 1) % 2 == 0) {  // Проверка на четность номера (1-based)
            a[i] *= max_val;      // Умножение элемента на максимальное значение
        }
    }

    cout << "Преобразованная последовательность:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
    delete[] a;

    return 0;
}

//_________________________________________________________________________________________________________________________
//Одномерный массив 6
//Дано натуральное число n ≥ 2, целочисленная последовательность a1, a2, …, an.
//Получить последовательность :
//a1, a1 a2, …, a1 a2 … an

#include <iostream>
#include <locale.h>

using namespace std;

int main() {

    setlocale(LC_ALL, "Russian");

    int n;

    // Запрос на ввод натурального числа n (n >= 2)
    cout << "Введите натуральное число n (n >= 2): ";
    cin >> n;

    if (n < 2) {
        cout << "Ошибка: n должно быть >= 2!" << endl;
        return 1;
    }

    int *a = new int[n];

    cout << "Введите " << n << " целых чисел:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }


    int *new_seq = new int[n];
    int proizv_element = 1;  // Инициализация переменной для накопления произведения

    // Вычисление последовательности накопленных произведений
    for (int i = 0; i < n; i++) {
        proizv_element *= a[i];      // Умножение текущего элемента на произведение
        new_seq[i] = proizv_element; // Сохранение текущего произведения в новый массив
    }

    // Вывод преобразованной последовательности
    cout << "Новая последовательность произведений:" << endl;
    for (int i = 0; i < n; i++) {
        cout << new_seq[i] << " ";
    }
    cout << endl;

    delete[] a;
    delete[] new_seq;

    return 0;
}

