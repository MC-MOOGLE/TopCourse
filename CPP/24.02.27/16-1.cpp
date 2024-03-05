// Используются для базового функционала
#include <iostream>
#include <string>
#include <Windows.h>
#include <stdio.h>
#include <vector>

// Часто юзаемые
#include <chrono>
#include <thread>

// Используются в заданиях
// ...


// Используются для базового функционала
#define RU setlocale(LC_ALL, "ru-RU");
#define EN setlocale(LC_ALL, "en-EN");
#define Color(n) SetConsoleTextAttribute(console, n);

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

using namespace std;

// Часто юзаемые
#define sleep(n) this_thread::sleep_for(chrono::milliseconds(n));
#define deleteLastOutput cout << "\x1b[A" << "\x1b[2K";

// Используются в заданиях
// ...


// Используются для базового функционала
template<typename T>
T getNumber(const char* what = "number") {
    T a;
    cout << "Enter " << what << " >> ";
    cin >> a;
    return a;
}

void print(string str, int repeats, string end = "") {
    while (repeats > 0)
    {
        cout << str;
        repeats--;
    }
    cout << end;
}

string tasksText[] = {
    /*1*/ "Написать функцию, которая принимает два параметра: основание степени и показатель степени, и вычисляет степень числа на основе полученных данных.",
    /*2*/ "Написать функцию, которая получает в качестве параметров 2 целых числа и возвращает сумму чисел из диапазона между ними.",
    /*3*/ "Число называется совершенным, если сумма всех его делителей равна ему самому.Напишите функцию поиска таких чисел во введенном интервале.",
};

void printTask(const unsigned short int n) {
    const unsigned short int lineLen = 60;
    RU;
    Color(3);
    if (tasksText->size() > n) {
        int i = 0;
        int lineChar = 0;
        string task = tasksText[n - 1];
        for (char c : task) {
            i++;
            if (lineChar > lineLen && c == ' ') {
                task.insert(i, "\n");
                lineChar = 0;
            }
            lineChar++;
        }
        cout << task << endl;
    }
    Color(7);
    EN;
    return;
};

// Сами задания
template<typename T>
T poww(T x = 1, T y = 1) {
    return pow(x, y);
}

void t1() {
    int x = getNumber<int>("base");
    int y = getNumber<int>("exponent");

    cout << poww(x, y);
}

template<typename T>
void reassembleMinMax(T &a, T &b) {
    T max = (a > b ? a : b);
    T min = (a > b ? b : a);

    a = min;
    b = max;
}

template<typename T>
T rangeSum(T x = 1, T y = 1) {
    T sum = 0;

    for (T i = x; i <= y; i++) {
        sum += i;
    }

    return sum;
}

void t2() {
    int x = getNumber<int>("start of range");
    int y = getNumber<int>("end of range");

    reassembleMinMax(x, y);

    cout << rangeSum(x, y);
}

template<typename T>
void printAllPerfectInRange(T x = 1, T y = 1) {
    for (int i = x; i < y; i++) {
        int sum = 0;
        for (int j = 1; j < (i / 2) + 1; j++) {
            if (!(i % j)) sum += j;
        }
        if (i == sum) cout << i << endl;
    }
}

void t3() {
    int x = getNumber<int>("start of range");
    int y = getNumber<int>("end of range");

    reassembleMinMax(x, y);

    printAllPerfectInRange(x, y);
}

// Запуск заданий

typedef void (*voidFuncton) ();
vector<voidFuncton> tasks = { t1, t2, t3 };

int main() {

    unsigned short int task;
    while (true) {
        if (tasks.size() > 1) {
            cout << "Enter task from " << 1 << " to " << tasks.size() << " (0 to exit) >> ";
            cin >> task;
        }
        else if (tasks.size() == 1) {
            task = 1;
            cout << "Enter 1 to continue, 0 to exit >> ";
            cin >> task;
        }
        if (tasks.size() >= task && task != 0) {
            printTask(task);
            tasks[task - 1]();
        }
        else {
            exit(0);
        }
        cout << "\n\n";
    }
    return 0;
}