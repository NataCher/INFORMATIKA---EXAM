# INFORMATIKA-EXAM
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Введите n (n >= 2): ";
    cin >> n;

    if (n < 2) {
        cout << "Ошибка! n должно быть >= 2";
        return 1;
    }

    int sum_even = 0;       // Сумма чётных
    long long product_odd = 1; // Произведение нечётных
    bool has_odd = false;    // Есть ли нечётные

    cout << "Введите " << n << " чисел: ";
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        if (num % 2 == 0) {
            sum_even += num;  // Чётное - добавляем к сумме
        } else {
            product_odd *= num; // Нечётное - умножаем
            has_odd = true;
        }
    }

    cout << "Сумма чётных: " << sum_even << endl;
    if (has_odd) {
        cout << "Произведение нечётных: " << product_odd;
    } else {
        cout << "Нечётных чисел нет";
    }

    return 0;
}
