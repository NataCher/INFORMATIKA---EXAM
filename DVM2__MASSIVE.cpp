//ДВУМЕРНЫЕ МАССИВЫ
//Двумерные массивы 5
//Дана действительная матрица размера m x n.Определить числа bi, …, bm, равные соответственно суммам элементов строк.

#include <iostream>
#include <cstdlib>  
#include <ctime> 
#include <locale.h>

using namespace std;

int rnd(int range_min, int range_max) {
    return (double)rand() / (RAND_MAX + 1) * (range_max - range_min) + range_min;
}

int main() {

    setlocale(LC_ALL, "Russian");

    int m, n;

    // Инициализация генератора случайных чисел текущим временем
    srand((unsigned int)time(NULL));

    // Ввод размеров матрицы
    cout << "Введите количество строк (m): ";
    cin >> m;
    cout << "Введите количество столбцов (n): ";
    cin >> n;

    // Создание динамической матрицы m x n
    double** matrix = new double* [m];
    for (int i = 0; i < m; i++) {
        matrix[i] = new double[n];
    }

    // Заполнение матрицы случайными числами от -100 до 100
    cout << "Матрица заполняется случайными числами..." << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rnd(-100, 100);
        }
    }

    // Вычисление сумм элементов каждой строки
    double* b = new double[m]; // Массив для хранения сумм
    for (int i = 0; i < m; i++) {
        b[i] = 0; // Инициализация суммы
        for (int j = 0; j < n; j++) {
            b[i] += matrix[i][j]; // Накопление суммы
        }
    }

    cout << "\nСгенерированная матрица:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << "\t"; // Вывод с табуляцией
        }
        cout << endl;
    }

    cout << "\nСуммы элементов строк:" << endl;
    for (int i = 0; i < m; i++) {
        cout << "b" << i + 1 << " = " << b[i] << endl;
    }


    for (int i = 0; i < m; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] b;

    return 0;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Двумерные массивы 2
//Даны две целочисленные квадратные матрицы порядка N.Найти последовательность из нулей и единиц b1, … bn, такую, что bi = 1, когда все элементы i - x строк первой и второй матриц отрицательны.

#include <iostream>
#include <cstdlib>  
#include <ctime>    
#include <locale.h> 

using namespace std;

// Функция генерации случайного числа в заданном диапазоне
int rnd(int range_min, int range_max) {
    return (double)rand() / (RAND_MAX + 1) * (range_max - range_min) + range_min;
}

int main() {
    setlocale(LC_ALL, "Russian");

    int m, n;

    srand((unsigned int)time(NULL));

    cout << "Введите количество строк (m): ";
    cin >> m;
    cout << "Введите количество столбцов (n): ";
    cin >> n;

    // Создание динамической матрицы m x n
    double** matrix = new double* [m];
    for (int i = 0; i < m; i++) {
        matrix[i] = new double[n];
    }

    // Заполнение матрицы случайными числами от -100 до 100
    cout << "Матрица заполняется случайными числами..." << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rnd(-100, 100);
        }
    }

    // Вычисление сумм элементов каждой строки
    double* b = new double[m]; // Массив для хранения сумм
    for (int i = 0; i < m; i++) {
        b[i] = 0; // Инициализация суммы
        for (int j = 0; j < n; j++) {
            b[i] += matrix[i][j]; // Накопление суммы
        }
    }

    cout << "\nСгенерированная матрица:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << "\t"; // Вывод с табуляцией
        }
        cout << endl; // Переход на новую строку
    }

    // Вывод сумм строк
    cout << "\nСуммы элементов строк:" << endl;
    for (int i = 0; i < m; i++) {
        cout << "b" << i + 1 << " = " << b[i] << endl;
    }

    for (int i = 0; i < m; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] b;

    return 0;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Двумерные массивы
//Дана действительная матрица порядка M* N.Написать программу вычисления : суммы наибольших значений ее строк.

#include <iostream> 
#include <cstdlib>   
#include <ctime>    
#include <locale.h> 

using namespace std;

// Функция генерации случайного числа в заданном диапазоне
int rnd(int range_min, int range_max) {
    return (double)rand() / (RAND_MAX + 1) * (range_max - range_min) + range_min;
}

int main() {
    setlocale(LC_ALL, "Russian");

    int M, N;

    cout << "Введите количество строк M: ";
    cin >> M;
    cout << "Введите количество столбцов N: ";
    cin >> N;

    srand((unsigned int)time(NULL));

    double** matrix = new double* [M];
    for (int i = 0; i < M; i++) {
        matrix[i] = new double[N];
    }

    // Заполнение матрицы случайными числами и вывод
    cout << "Матрица " << M << "x" << N << ":" << endl;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = rnd(-100, 100); // Заполнение случайными числами
            cout << matrix[i][j] << "\t";  // Вывод с табуляцией
        }
        cout << endl;
    }

    // Вычисление суммы максимумов строк
    double sum_of_max = 0;
    for (int i = 0; i < M; i++) {
        double row_max = matrix[i][0]; // Предполагаем, что первый элемент строки - максимальный
        for (int j = 1; j < N; j++) {
            if (matrix[i][j] > row_max) {
                row_max = matrix[i][j]; // Обновляем максимум, если нашли больше
            }
        }
        sum_of_max += row_max; // Добавляем максимум строки к общей сумме
    }

    cout << "Сумма наибольших значений строк: " << sum_of_max << endl;

    for (int i = 0; i < M; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Двумерные массивы
//Дана целочисленная матрица порядка M* N.Написать программу нахождения суммы наибольших значений ее столбцов.
#include <iostream>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <locale.h>


using namespace std;

int rnd(int range_min, int range_max) {
    return (double)rand() / (RAND_MAX + 1) * (range_max - range_min) + range_min;
}

int main() {

    setlocale(LC_ALL, "Russian");

    int M, N;

    cout << "Введите количество строк M: ";
    cin >> M;
    cout << "Введите количество столбцов N: ";
    cin >> N;

    srand((unsigned int)time(NULL));

    // Создание динамической матрицы M x N
    int** matrix = new int* [M];
    for (int i = 0; i < M; i++) {
        matrix[i] = new int[N];
    }

    // Заполнение матрицы случайными числами от 0 до 100 и вывод
    cout << "Матрица " << M << "x" << N << ":" << endl;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = rnd(0, 100);
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    // Вычисление суммы максимумов столбцов
    int sum_of_max = 0;
    for (int j = 0; j < N; j++) {      // Перебор по столбцам
        int col_max = matrix[0][j];     // Первый элемент столбца как начальный максимум
        for (int i = 1; i < M; i++) {   // Перебор по строкам
            if (matrix[i][j] > col_max) {
                col_max = matrix[i][j]; // Обновление максимума столбца
            }
        }
        sum_of_max += col_max; // Добавление максимума столбца к общей сумме
    }


    cout << "Сумма наибольших значений столбцов: " << sum_of_max << endl;

    for (int i = 0; i < M; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Двумерные массивы
//Дана целочисленная матрица порядка M* M(N).Написать программу нахождения суммы наименьших значений ее строк.
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <locale.h>

using namespace std;

// Функция генерации случайного числа
int rnd(int range_min, int range_max) {
    return (double)rand() / (RAND_MAX + 1) * (range_max - range_min) + range_min;
}

int main() {

    setlocale(LC_ALL, "Russian");

    int M;

    srand((unsigned int)time(NULL));

    // Ввод порядка матрицы с проверкой корректности
    cout << "Введите порядок матрицы M: ";
    while (!(cin >> M) || M <= 0) {
        cout << "Ошибка! Введите натуральное число: ";
        cin.clear();           // Сброс флагов ошибок
        cin.ignore(10000, '\n'); // Очистка буфера ввода
    }

    // Создание динамической квадратной матрицы M x M
    int** matrix = new int* [M];
    for (int i = 0; i < M; i++) {
        matrix[i] = new int[M];
    }

    // Заполнение матрицы случайными числами от 0 до 100 и вывод
    cout << "\nСгенерированная матрица " << M << "x" << M << ":" << endl;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            matrix[i][j] = rnd(0, 100);
            cout << matrix[i][j] << "\t"; // Вывод с табуляцией
        }
        cout << endl;
    }

    // Вычисление суммы минимумов строк
    int sum_of_min = 0;
    for (int i = 0; i < M; i++) {
        int row_min = matrix[i][0]; // Первый элемент строки как начальный минимум
        for (int j = 1; j < M; j++) {
            if (matrix[i][j] < row_min) {
                row_min = matrix[i][j]; // Обновление минимума строки
            }
        }
        sum_of_min += row_min; // Добавление минимума строки к общей сумме
    }

    cout << "\nСумма наименьших значений строк: " << sum_of_min << endl;

    for (int i = 0; i < M; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Двумерные массивы 10 – СОРТИРОВКА *
//Дана действительная матрица порядка M * N.Написать программу формирования новой матрицы, у которой столбец с наибольшим и столбец с наименьшим значением переставлены местами.Предполагается, что такие элементы единственны.
#include <iostream>
#include <locale.h>
#include <cstdlib>
#include <ctime>

using namespace std;

// Функция генерации случайного числа
double rnd(double range_min, double range_max) {
    return (double)rand() / RAND_MAX * (range_max - range_min) + range_min;
}

int main() {

    setlocale(LC_ALL, "Russian");

    const int MAX_SIZE = 100; // Максимальный размер матрицы
    int M, N;

    // Инициализация генератора случайных чисел
    srand((unsigned int)time(NULL));

    // Ввод размеров матрицы с проверкой
    cout << "Введите количество строк M (не более " << MAX_SIZE << "): ";
    while (!(cin >> M) || M <= 0 || M > MAX_SIZE) {
        cout << "Ошибка! Введите число от 1 до " << MAX_SIZE << ": ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    cout << "Введите количество столбцов N (не более " << MAX_SIZE << "): ";
    while (!(cin >> N) || N <= 0 || N > MAX_SIZE) {
        cout << "Ошибка! Введите число от 1 до " << MAX_SIZE << ": ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    // Создание исходной и новой матриц
    double** matrix = new double* [M];
    double** new_matrix = new double* [M];
    for (int i = 0; i < M; i++) {
        matrix[i] = new double[N];
        new_matrix[i] = new double[N];
    }

    // Заполнение исходной матрицы случайными числами
    cout << "\nСгенерированная матрица " << M << "x" << N << ":" << endl;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = rnd(-100.0, 100.0);
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    // Поиск столбцов с максимальной и минимальной суммами
    int max_col = 0, min_col = 0;
    double max_sum = -DBL_MAX; // Минимально возможное значение double
    double min_sum = DBL_MAX;  // Максимально возможное значение double

    for (int j = 0; j < N; j++) {
        double col_sum = 0;
        for (int i = 0; i < M; i++) {
            col_sum += matrix[i][j];
        }

        if (col_sum > max_sum) {
            max_sum = col_sum;
            max_col = j;
        }
        if (col_sum < min_sum) {
            min_sum = col_sum;
            min_col = j;
        }
    }

    // Создание новой матрицы с переставленными столбцами
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (j == max_col) {
                new_matrix[i][j] = matrix[i][min_col];
            }
            else if (j == min_col) {
                new_matrix[i][j] = matrix[i][max_col];
            }
            else {
                new_matrix[i][j] = matrix[i][j];
            }
        }
    }

    cout << "\nСтолбец с наибольшей суммой (" << max_sum << "): " << max_col + 1 << endl;
    cout << "Столбец с наименьшей суммой (" << min_sum << "): " << min_col + 1 << endl;

    cout << "\nНовая матрица после перестановки столбцов:" << endl;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << new_matrix[i][j] << "\t";
        }
        cout << endl;
    }

    for (int i = 0; i < M; i++) {
        delete[] matrix[i];
        delete[] new_matrix[i];
    }
    delete[] matrix;
    delete[] new_matrix;

    return 0;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Двумерные массивы 11
//Дана действительная матрица порядка(M)N * N.
//Написать программу нахождения наибольшего элемента матрицы и определения суммы элементов столбцов…

#include <iostream>
#include <locale.h>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <iomanip>  // Для форматированного вывода

using namespace std;

// Функция генерации случайного числа в заданном диапазоне
double randomDouble(double range_min, double range_max) {
    return (double)rand() / RAND_MAX * (range_max - range_min) + range_min;
}

int main() {


    setlocale(LC_ALL, "Russian");

    int N;

    // Инициализация генератора случайных чисел
    srand((unsigned int)time(NULL));

    // Ввод размера матрицы
    cout << "Введите размер квадратной матрицы N: ";
    while (!(cin >> N) || N <= 0) {
        cout << "Ошибка! Введите положительное целое число: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    // Динамическое создание матрицы
    double** matrix = new double* [N];
    for (int i = 0; i < N; i++) {
        matrix[i] = new double[N];
    }

    // Заполнение матрицы случайными числами от -100.0 до 100.0
    cout << "\nСгенерированная матрица " << N << "x" << N << ":\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = randomDouble(-100.0, 100.0);
            cout << fixed << setprecision(2) << setw(8) << matrix[i][j];
        }
        cout << endl;
    }

    // Поиск наибольшего элемента
    double maxElement = matrix[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (matrix[i][j] > maxElement) {
                maxElement = matrix[i][j];
            }
        }
    }

    // Вычисление суммы элементов каждого столбца
    double* columnSums = new double[N]();  // Инициализация нулями

    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N; i++) {
            columnSums[j] += matrix[i][j];
        }
    }

    cout << "\nНаибольший элемент матрицы: " << fixed << setprecision(2) << maxElement << endl;
    cout << "Суммы элементов столбцов:\n";
    for (int j = 0; j < N; j++) {
        cout << "Столбец " << j + 1 << ": " << fixed << setprecision(2) << columnSums[j] << endl;
    }

    for (int i = 0; i < N; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] columnSums;

    return 0;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Двумерные массивы 4
//Написать программу определения в массиве случайных целых чисел количества максимальных и минимальных элементов.

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <locale.h>

using namespace std;

int rnd(int range_min, int range_max) {
    return (double)rand() / (RAND_MAX + 1) * (range_max - range_min) + range_min;
}

int main() {

    srand((unsigned int)time(NULL));
    setlocale(LC_ALL, "Russian");

    int size;
    cout << "Введите размер массива: ";
    cin >> size;

    if (size <= 0) {
        cout << "Некорректный размер массива!" << endl;
        return 1;
    }

    int* arr = new int[size];

    // Заполнение массива
    for (int i = 0; i < size; i++) {
        arr[i] = rnd(0, 99);
    }

    // Вывод массива
    cout << "Сгенерированный массив: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Поиск min и max
    int min_val = INT_MAX, max_val = INT_MIN;
    for (int i = 0; i < size; i++) {
        if (arr[i] < min_val) min_val = arr[i];
        if (arr[i] > max_val) max_val = arr[i];
    }

    // Подсчет количества
    int min_count = 0, max_count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == min_val) min_count++;
        if (arr[i] == max_val) max_count++;
    }

    cout << "Минимальный элемент: " << min_val << endl;
    cout << "Количество минимальных элементов: " << min_count << endl;
    cout << "Максимальный элемент: " << max_val << endl;
    cout << "Количество максимальных элементов: " << max_count << endl;

    delete[] arr;

    return 0;
}


//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Задача 26
//Даны натуральное число n и целые числа ci, …, сn.
//Имеются ли в последовательности ci, …, сn;
//a)	два идущих подряд четных элемента;
//b)	три идущих подряд нулевых элемента.

#include <iostream>
#include <locale.h>

using namespace std;

int main() {

    setlocale(LC_ALL, "Russian");

    int n;


    cout << "Введите количество элементов n: ";
    while (!(cin >> n) || n <= 0) {
        cout << "Ошибка! Введите натуральное число: ";
        cin.clear(); // Сброс флагов ошибок
        cin.ignore(10000, '\n'); // Очистка буфера ввода
    }


    int* sequence = new int[n];


    cout << "Введите " << n << " целых чисел: ";
    for (int i = 0; i < n; i++) {
        while (!(cin >> sequence[i])) {
            cout << "Ошибка! Введите целое число: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }

    // Проверка условия a) два подряд четных элемента
    bool hasTwoEven = false;
    for (int i = 0; i < n - 1 && !hasTwoEven; i++) {
        if (sequence[i] % 2 == 0 && sequence[i + 1] % 2 == 0) {
            hasTwoEven = true;
        }
    }

    // Проверка условия b) три подряд нулевых элемента
    bool hasThreeZeros = false;
    for (int i = 0; i < n - 2 && !hasThreeZeros; i++) {
        if (sequence[i] == 0 && sequence[i + 1] == 0 && sequence[i + 2] == 0) {
            hasThreeZeros = true;
        }
    }

    cout << "\nРезультаты проверки:\n";
    cout << "a) В последовательности "
        << (hasTwoEven ? "есть" : "нет")
        << " два подряд четных элемента\n";
    cout << "b) В последовательности "
        << (hasThreeZeros ? "есть" : "нет")
        << " три подряд нулевых элемента\n";


    delete[] sequence;

    return 0;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Задача 27
//Даны целые числа a1, a2 … Известно, что a1 > 0 и что среди a1, a2 … есть хотя бы одно отрицательное число.
//Пусть a1…, an – члены данной последовательности, предшествующие первому отрицательному элементу(n заранее неизвестно).
//Получить количество четных среди a1…, an.

#include <iostream>
#include <locale.h>

using namespace std;

int main() {

    setlocale(LC_ALL, "Russian");

    int num;
    int count = 0;  // Счетчик четных чисел

    cout << "Введите последовательность целых чисел (первое > 0, должно быть хотя бы одно отрицательное):\n";

    // Читаем числа до первого отрицательного
    while (true) {
        cin >> num;

        // Проверяем, не отрицательное ли число
        if (num < 0) {
            break;  // Выходим из цикла при первом отрицательном числе
        }

        // Проверяем четность и увеличиваем счетчик
        if (num % 2 == 0) {
            count++;
        }
    }

    cout << "Количество четных чисел до первого отрицательного: " << count << endl;

    return 0;
}


//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Задача 28
//Даны натуральное число n и символы si, …, sn, среди которых есть двоеточие.
//Получить все символы, расположенные до первого двоеточия включительно.


#include <iostream>
#include <locale.h>

using namespace std;

int main() {

    setlocale(LC_ALL, "Russian");

    const int MAX_SIZE = 1000; // Максимальный размер последовательности
    char symbols[MAX_SIZE];
    int n;

    // Ввод количества символов
    cout << "Введите количество символов n: ";
    cin >> n;

    // Проверка корректности ввода
    if (n <= 0 || n > MAX_SIZE) {
        cout << "Некорректный ввод! n должно быть натуральным числом не больше " << MAX_SIZE << endl;
        return 1;
    }

    // Ввод последовательности символов
    cout << "Введите " << n << " символов через пробел или по одному: ";
    for (int i = 0; i < n; i++) {
        cin >> symbols[i];
    }

    // Поиск первого двоеточия
    int colon_pos = -1;
    for (int i = 0; i < n; i++) {
        if (symbols[i] == ':') {
            colon_pos = i;
            break;
        }
    }

    // Проверка наличия двоеточия
    if (colon_pos == -1) {
        cout << "В последовательности нет двоеточия!" << endl;
        return 1;
    }

    // Вывод результата
    cout << "Символы до первого двоеточия включительно: ";
    for (int i = 0; i <= colon_pos; i++) {
        cout << symbols[i];
        if (i < colon_pos) {
            cout << " "; // Добавляем пробелы между символами, кроме последнего
        }
    }
    cout << endl;

    return 0;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Задача 29
//Дана целочисленная квадратная матрица порядка n.Найти номера строк :
//a)	элементы в каждой из которых одинаковы;
//b)	все элементы которых – нули.


#include <iostream>
#include <locale.h>
#include <cstdlib>  // Для функций rand() и srand()
#include <ctime>    // Для функции time()

using namespace std;

// Функция генерации случайного числа в заданном диапазоне
int rnd(int range_min, int range_max) {
    return (double)rand() / (RAND_MAX + 1) * (range_max - range_min) + range_min;
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(0));  // Инициализация генератора случайных чисел

    int n;

    cout << "Введите порядок матрицы n: ";
    cin >> n;

    if (n <= 0) {
        cout << "Некорректный размер матрицы!" << endl;
        return 1;
    }

    // Динамическое выделение памяти для матрицы
    int** matrix = new int* [n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
    }

    // Заполнение матрицы случайными числами (от 0 до 10 для увеличения вероятности одинаковых элементов)
    cout << "Сгенерированная матрица:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rnd(0, 2);  // Диапазон можно изменить по вашему усмотрению
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    // Поиск строк с одинаковыми элементами (пункт a)
    cout << "a) Строки с одинаковыми элементами: ";
    for (int i = 0; i < n; i++) {
        bool all_equal = true;
        int first_element = matrix[i][0];

        for (int j = 1; j < n; j++) {
            if (matrix[i][j] != first_element) {
                all_equal = false;
                break;
            }
        }

        if (all_equal) {
            cout << i + 1 << " ";
        }
    }
    cout << endl;

    // Поиск строк со всеми нулями (пункт b)
    cout << "b) Строки со всеми нулями: ";
    for (int i = 0; i < n; i++) {
        bool all_zeros = true;

        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != 0) {
                all_zeros = false;
                break;
            }
        }

        if (all_zeros) {
            cout << i + 1 << " ";
        }
    }
    cout << endl;

    // Освобождение памяти
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}



/*#include <iostream>
using namespace std;

int main() {
    const int MAX_SIZE = 100;
    int matrix[MAX_SIZE][MAX_SIZE];
    int n;

    // Ввод размера матрицы
    cout << "Введите порядок матрицы n: ";
    cin >> n;

    // Проверка корректности ввода
    if (n <= 0 || n > MAX_SIZE) {
        cout << "Некорректный размер матрицы!" << endl;
        return 1;
    }

    // Ввод элементов матрицы
    cout << "Введите элементы матрицы:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    // Поиск строк с одинаковыми элементами (пункт a)
    cout << "a) Строки с одинаковыми элементами: ";
    for (int i = 0; i < n; i++) {
        bool all_equal = true;
        int first_element = matrix[i][0];

        for (int j = 1; j < n; j++) {
            if (matrix[i][j] != first_element) {
                all_equal = false;
                break;
            }
        }

        if (all_equal) {
            cout << i + 1 << " ";
        }
    }
    cout << endl;

    // Поиск строк со всеми нулями (пункт b)
    cout << "b) Строки со всеми нулями: ";
    for (int i = 0; i < n; i++) {
        bool all_zeros = true;

        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != 0) {
                all_zeros = false;
                break;
            }
        }

        if (all_zeros) {
            cout << i + 1 << " ";
        }
    }
    cout << endl;

    return 0;
}
*/

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Задача 30
//Дана целочисленная квадратная матрица порядка n.Найти номера строк, элементы каждой из которых образуют монотонную последовательность(монотонно убывающую и возрастающую).

#include <iostream>
#include <locale.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    int n;
    cout << "Введите порядок матрицы n: ";
    cin >> n;

    if (n <= 0) {
        cout << "Некорректный размер матрицы!" << endl;
        return 1;
    }

    // Динамическое выделение памяти
    int** matrix = new int* [n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
    }

    // Ввод элементов матрицы
    cout << "Введите элементы матрицы:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    // Поиск монотонных строк
    cout << "Строки с монотонными последовательностями: ";
    for (int i = 0; i < n; i++) {
        if (n == 1) {
            cout << i + 1 << " ";
            continue;
        }

        bool increasing = true;
        bool decreasing = true;

        for (int j = 1; j < n; j++) {
            if (matrix[i][j] < matrix[i][j - 1]) increasing = false;
            if (matrix[i][j] > matrix[i][j - 1]) decreasing = false;
            if (!increasing && !decreasing) break;
        }

        if (increasing || decreasing) {
            cout << i + 1 << " ";
        }
    }
    cout << endl;


    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}


//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Задача 31
//Дана целочисленная квадратная матрица порядка n.Найти номера строк, элементы которых образуют симметричные последовательности(палиндромы).

#include <iostream>
#include <locale.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    int n;
    cout << "Введите порядок матрицы n: ";
    cin >> n;

    if (n <= 0) {
        cout << "Некорректный размер матрицы!" << endl;
        return 1;
    }

    int** matrix = new int* [n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
    }

    cout << "Введите элементы матрицы:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    // Поиск палиндромов
    cout << "Строки-палиндромы: ";
    bool found = false;
    for (int i = 0; i < n; i++) {
        bool is_palindrome = true;
        for (int j = 0; j < n / 2; j++) {
            if (matrix[i][j] != matrix[i][n - 1 - j]) {
                is_palindrome = false;
                break;
            }
        }
        if (is_palindrome) {
            cout << i + 1 << " ";
            found = true;
        }
    }
    if (!found) cout << "нет";
    cout << endl;

    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Задача 32
//Дана действительная квадратная матрица порядка n.
//В строках с отрицательным элементом на главной диагонали найти :
//a)	сумму всех элементов;
//b)	наибольший из всех элементов.


#include <iostream>
#include <iomanip>  // Для форматированного вывода
#include <locale.h> 

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian"); // Установка русской локали

    int n; // Порядок квадратной матрицы


    cout << "Введите порядок матрицы n: ";
    while (!(cin >> n) || n <= 0) {
        cout << "Ошибка! Введите натуральное число: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    // Создание динамической матрицы n x n
    double** matrix = new double* [n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new double[n];
    }

    // Ввод элементов матрицы
    cout << "Введите элементы матрицы " << n << "x" << n << ":\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            while (!(cin >> matrix[i][j])) {
                cout << "Ошибка! Введите число: ";
                cin.clear();
                cin.ignore(10000, '\n');
            }
        }
    }

    // Вывод матрицы для наглядности
    cout << "\nВведенная матрица:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << setw(8) << fixed << setprecision(2) << matrix[i][j];
        }
        cout << endl;
    }

    // Обработка строк с отрицательными элементами на главной диагонали
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (matrix[i][i] < 0) {
            found = true;
            double sum = 0;
            double max_val = matrix[i][0];

            // Вычисление суммы и максимума в строке
            for (int j = 0; j < n; j++) {
                sum += matrix[i][j];
                if (matrix[i][j] > max_val) {
                    max_val = matrix[i][j];
                }
            }

            cout << "\nСтрока " << i + 1 << " (имеет отрицательный элемент на диагонали):\n";
            cout << "  Сумма элементов: " << sum << "\n";
            cout << "  Максимальный элемент: " << max_val << "\n";
        }
    }

    if (!found) {
        cout << "\nВ матрице нет строк с отрицательным элементом на главной диагонали.\n";
    }

    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Задача 33
//Дана действительная квадратная матрица порядка n.
//Получить x1xn + x2xn - 1 … + xnx1,
//где xk наибольшее значение элементов k - й строки данной матрицы.

#include <iostream>
#include <iomanip>
#include <climits>
#include <locale.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    int n;
    cout << "Введите порядок матрицы n: ";
    cin >> n;

    // Проверка корректности ввода
    if (n <= 0) {
        cout << "Некорректный размер матрицы!" << endl;
        return 1;
    }

    // Динамическое выделение памяти для матрицы
    double** matrix = new double* [n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new double[n];
    }

    // Динамическое выделение памяти для массива x
    double* x = new double[n];

    // Ввод элементов матрицы
    cout << "Введите элементы матрицы:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    // Находим максимальные элементы каждой строки
    for (int i = 0; i < n; i++) {
        x[i] = matrix[i][0];
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] > x[i]) {
                x[i] = matrix[i][j];
            }
        }
    }

    // Вычисляем требуемое выражение
    double result = 0;
    for (int k = 0; k < n; k++) {
        result += x[k] * x[n - 1 - k];
    }

    // Вывод результата
    cout << fixed << setprecision(4);
    cout << "Результат вычисления выражения: " << result << endl;

    // Освобождение памяти
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] x;

    return 0;
}

