#include <iostream>
#include <string>
#include <Windows.h>
#include <stdio.h>
#include <iomanip>
#include <regex>
#include <map>

#define RU setlocale(LC_ALL, "ru-RU");
#define EN setlocale(LC_ALL, "en-EN");
#define Color(n) SetConsoleTextAttribute(console, n);
#define tab "\t"

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

using namespace std;

void printTask(int n) {
    RU;
    Color(3);
    string task;
    switch (n)
    {
    case 1:
        task = { R"delimeter(Напишите программу, которая вычисляет сумму целых чисел от а (значение 
вводится пользователем) до 500.)delimeter" };
        break;
    case 2:
        task = { R"delimeter(Напишите программу, которая запрашивает два целых числа x и y, после чего 
вычисляет и выводит значение x в степени y. Учтите ограничения значений, 
связанные с представлением чисел в памяти. Учтите, что числа могут быть как 
равны нулю, так и отличными от него.)delimeter" };
        break;
    case 3:
        task = { R"delimeter(Найти среднее арифметические всех целых чисел от 1 до 1000. Использовать 
циклы – обязательно!)delimeter" };
        break;
    case 4:
        task = { R"delimeter(Найти произведение всех целых чисел от a до 20. Значение переменной a 
вводится с клавиатуры: )delimeter" };
        break;
    case 5:
        task = { R"delimeter(Написать программу, которая выводит на экран таблицу умножения на k,
где k— ваш порядковый номер в списке группы (если не знаете своего порядкового номера – уточните у преподавателя).
Например, для 7-го варианта:)delimeter" };
        break;
    default:
        break;
    }
    cout << task << endl;
    Color(7);
    EN;
};

void t1() {
    int a = 0;
    int sum = 0;
    cout << "Enter a >> ";
    cin >> a;

    if (a > 500 || a < 0) {
        cout << "Number is out of range";
        return;
    }

    for (int i = a; i < 500; i++) {
        sum += i;
    }
    cout << "Sum excluding 500 >> " << sum << endl;
    cout << "Sum including 500 >> " << sum + 500;
}

void t2() {
    long long int x, y;
    cout << "Enter number and its power >> ";
    cin >> x >> y;
    if (double(pow(x, y)) >= pow(2, 63) - 1) {
        cout << "Integer overflow";
        return;
    }
    else {
        cout << "Result << " << long long int(pow(x, y));
    }
}

void t3() {
    // Complex, practically unscalable method
    double avg = 0;

    for (int i = 0; i <= 1000; i++) {
        avg += i;
    }

    cout << "Including 1000 >> "
        << avg / 1000 << endl;
    // easy, but no loops
    // Works for all averages, starting from i = 1 and going i++
    cout << "Excluding 1000 >> "
        << 999 / 2 + 0.5;
}

void t4() {
    int a = 0;
    cout << "Enter a >> ";
    cin >> a;
    if (a > 20 || a < 1) {
        cout << "Number is out of range";
        return;
    }
    for (int i = a + 1; i <= 20; i++) {
        a += i;
    }
    cout << a;
}

void t5() {
    // Assuming im #3
    const int myN = 3;
    for (int i = 0; i <= 10; i++) {
        cout << myN << " * " << i << " = " << myN * i << endl;
    }
}


int main() {
    int task;
    while (true) {
        cout << "Enter task (0 to exit) >> ";
        cin >> task;
        printTask(task);
        switch (task) { // There is must be a better way to do this
        case (1):
            t1();
            break;
        case (2):
            t2();
            break;
        case (3):
            t3();
            break;
        case (4):
            t4();
            break;
        case (5):
            t5();
            break;
        default:
            exit(0);
            break;
        }
        cout << "\n\n";
    }
    return 0;
}