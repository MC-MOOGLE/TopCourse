// Используются для базового функционала
#include <iostream>
#include <string>
#include <Windows.h>
#include <stdio.h>
#include <vector>
// Используются в заданиях
#include <chrono>
#include <thread>

// Используются для базового функционала
#define RU setlocale(LC_ALL, "ru-RU");
#define EN setlocale(LC_ALL, "en-EN");
#define Color(n) SetConsoleTextAttribute(console, n);

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

using namespace std;

// Используются в заданиях
#define sleep(n) this_thread::sleep_for(chrono::milliseconds(n));
#define deleteLastOutput cout << "\x1b[A" << "\x1b[2K";

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

void printTask(int n) {
    RU;
    Color(3);
    string task;
    switch (n)
    {
    case 1:
        task = { R"delimeter(В одномерном массиве, заполненном случайными числами, определить 
минимальный и максимальный элементы. Размер массива: 11 элементов.)delimeter" };
        break;
    case 2:
        task = { R"delimeter(Создать одномерный массив из 9 элементов и заполнить его случайными 
значениями. Границы диапазона случайных значений задает пользователь. 
Пользователем вводится еще одно число. Необходимо найти все пары 
элементов, сумма которых меньше задаваемого пользователем числа.)delimeter" };
        break;
    case 3:
        task = { R"delimeter(Пользователь вводит прибыль фирмы за год (12 месяцев). Затем пользователь 
вводит диапазон (например, 3 и 6 — поиск между 3-м и 6-м месяцем). Необходимо 
определить месяц, в котором прибыль была максимальна и месяц, в котором 
прибыль была минимальна с учетом выбранного диапазона. Левая и правая 
граница диапазона включаются в диапазон.)delimeter" };
        break;
    default:
        break;
    }
    cout << task << endl;
    Color(7);
    EN;
};

template<typename T>
T arrMin(T *arr, int size) {
    T min = arr[0];
    for (T i = 0; i < size; i++) {
        if (arr[i] <= min) {
            min = arr[i];
        }
    }

    return min;
}

template<typename T>
T arrMax(T* arr, int size) {
    T max = arr[0];
    for (T i = 0; i < size; i++) {
        if (arr[i] >= max) {
            max = arr[i];
        }
    }

    return max;
}

void t1() {
    srand(time(nullptr));
    const int size = 11;
    int arr[size];

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }

    cout << "Min << " << arrMin(arr, size) << endl
        << "Max << " << arrMax(arr, size) << endl;
}

void t2() {
    srand(time(nullptr));

    const int size = 9;
    int arr[size];

    unsigned int start = getNumber<unsigned int>("start of range");
    unsigned int end = getNumber<unsigned int>("end of range");

    end++;

    if (start > end) {
        return;
    }

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % (end - start ) + start;
    }

    int minNum = getNumber<int>("Min par num");

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (minNum > arr[i] + arr[j]) {
                cout << "[" << i << "] " << arr[i] << " + [" << j << "] " << arr[j] << " < " << minNum << endl;
            }
        }
    }
}

void t3() {
    srand(time(nullptr));

    const int size = 12;
    int arr[size];

    const string months[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };

    for (int i = 0; i < size; i++) {
        cout << "Enter " << months[i] << "'s [" << i + 1 << "] profits >> ";
        cin >> arr[i];
    }

    unsigned int start = getNumber<unsigned int>("start of range");
    unsigned int end = getNumber<unsigned int>("end of range");

    start--;
    end--;

    int min = INT32_MAX, max = INT32_MIN;

    if (start > end || start > size || end > size) {
        return;
    }

    for (int i = start; i < end; i++) {
        if (arr[i] > max) {
            max = i;
        }
        if (arr[i] < min) {
            min = i;
        }
    }

    cout << "Min profits << " << months[min] << "(" << arr[min] << ")" << endl
        << "Max profits << " << months[max] << "(" << arr[max] << ")" << endl;
}

typedef void (*voidFuncton) ();
vector<voidFuncton> tasks = { t1, t2, t3 };

int main() {
    unsigned short int task;
    while (true) {
        cout << "Enter task from " << 1 << " to " << tasks.size() << " (0 to exit) >> ";
        cin >> task;
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