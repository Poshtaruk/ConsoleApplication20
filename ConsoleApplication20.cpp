// Створити лінійний односпрямований список із дійсних чисел. Додати до списку число 1.5 після кожного елемента з від’ємним значенням.Видалити зі списку усі числа від 2 до 5
#include <iostream>
#include <forward_list>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    forward_list<double> numberList = { -3.2, 1.4, 4.5, -2.1, 6.8, 2.5, -1.0, 4.0 };

    cout << "Початковий список: ";
    for (double number : numberList) {
        cout << number << " ";
    }
    cout << endl;

    // Додавання числа 1.5 після кожного від'ємного елемента
    auto current = numberList.before_begin();
    for (auto it = numberList.begin(); it != numberList.end(); ++it) {
        if (*it < 0) {
            current = numberList.insert_after(it, 1.5);  // Вставка 1.5 після від'ємного числа
        }
        current = it;
    }

    cout << "Список після додавання 1.5 після від'ємних чисел: ";
    for (double number : numberList) {
        cout << number << " ";
    }
    cout << endl;

    // Видалення чисел у діапазоні [2, 5]
    auto prev = numberList.before_begin();
    for (auto it = numberList.begin(); it != numberList.end(); ) {
        if (*it >= 2 && *it <= 5) {
            it = numberList.erase_after(prev);  // Видалення поточного елемента
        }
        else {
            prev = it;
            ++it;
        }
    }

    cout << "Список після видалення чисел у діапазоні [2, 5]: ";
    for (double number : numberList) {
        cout << number << " ";
    }
    cout << endl;

    return 0;
}