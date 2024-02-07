#include <iomanip>
#include <iostream>
#include <map>
#include <regex>
#include <stdio.h>
#include <string>
#include <Windows.h>
#include <set>

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
        task = { R"delimeter(Подсчитать количество целых чисел в диапазоне от 100 до 999, у которых есть две одинаковые цифры.)delimeter" };
        break;
    case 2:
        task = { R"delimeter(Подсчитать количество целых чисел в диапазоне от 100 до 999, у которых все цифры разные.)delimeter" };
        break;
    case 3:
        task = { R"delimeter(Пользователь вводит любое целое число.
Необходимо из этого целого числа удалить все цифры 3 и 6 и вывести обратно на экран.)delimeter" };
        break;
    case 4:
        task = { R"delimeter(Пользователь вводит любое целое число А.
Необходимо вывести все целые числа В, для которых А делится без остатка на В*В
и не делится без остатка на В*В*В.)delimeter" };
        break;
    case 5:
        task = { R"delimeter(Пользователь вводит целое число А. Программа должна определить, что куб 
суммы цифр этого числа равен А*А.)delimeter" };
        break;
    case 6:
        task = { R"delimeter(Пользователь вводит целое число. Необходимо вывести все целые числа, на 
которое заданное число делиться без остатка.)delimeter" };
        break;
    case 7:
        task = { R"delimeter(Пользователь вводит два целых числа. Необходимо вывести все целые числа, на 
которые оба введенных числа делятся без остатка.)delimeter" };
        break;
    default:
        break;
    }
    cout << task << endl;
    Color(7);
    EN;
};

void t1() {
    // Теоретически, можно посчитать по формуле, но это слишком просто
    int counter = 0;
    for (int i = 100; i < 1000; i++) {
        set<int> uniqueDigits = {i / 100 % 10, i / 10 % 10, i % 10 }; // Сначала хотел сделать поддержку чисел любой длины, но стало лень

        if (uniqueDigits.size() < 3) {
            counter++;
        }
    }
    cout << "Numbers with duplicate digits << " << counter;
};

void t2() {
    int counter = 0;
    for (int i = 100; i < 1000; i++) {
        set<int> uniqueDigits = { i / 100 % 10, i / 10 % 10, i % 10 };

        if (uniqueDigits.size() == 3) {
            counter++;
        }
    }
    cout << "Numbers with duplicate digits << " << counter;
}

void t3() {
    long long n; // Чтобы пользователь лишние символы не вводил
    cout << "Enter number >> ";
    cin >> n;

    string number = to_string(n);
    string newN;

    for (char c : number) {
        if (c == '3' || c == '6') {}
        else
        {
            newN += c;
        }
    }
    cout << newN;
}

void t4() {
    int A;
    cout << "Enter number >> ";
    cin >> A;

    for (int B = 1; B < int(sqrt(A)) + 1; B++) {
        if ( !(A % (B * B)) && (A % (B * B * B)) ) {
            cout << B << endl;
        }
    }
}

void t5() {
    unsigned int A;
    cout << "Enter number >> ";
    cin >> A;

    string strA = to_string(A);
    int sum = 0;

    for (char c : strA) {
        int a = c - 48;
        sum += a;
    }

    if (pow(sum, 3) == pow(A, 2)) {
        cout << "Sum of digits cubed == A squared";
    }
    else {
        cout << "Sum of digits cubed != A squared";
    }
}

void t6() {
    unsigned int A;
    cout << "Enter number >> ";
    cin >> A;

    cout << "All              " << char(24) << " dividers" << endl;
    for (int i = 1; i <= A / 2; i++) {
        if (!(A % i)) {
            cout << i << endl;
        }
    }
};

void t7() {
    unsigned int A, B;
    cout << "Enter 2 numbers >> ";
    cin >> A >> B;

    cout << "All both numbers dividers" << endl;
    for (int i = 1; i <= max(A / 2, B / 2); i++) {
        if (!(A % i) && !(B % i)) {
            cout << i << endl;
        }
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
        case (6):
            t6();
            break;
        case (7):
            t7();
            break;
        default:
            exit(0);
            break;
        }
        cout << "\n\n";
    }
    return 0;
}