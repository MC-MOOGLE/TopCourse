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
        task = { R"delimeter(Создать одномерный массив из N вещественных чисел (N задается константой в 
программе). Предоставить пользователю выбор: автоматически сгенерировать 
данные в массиве или ввести вручную. Вещественные числа генерируются с 
помощью деления целых случайных чисел на 100.0.
Далее по выбору пользователя необходимо вычислить:
- Сумму отрицательных элементов;
- Произведение элементов, находящихся между min и max элементами;
- Произведение элементов с четными номерами;
- Сумму элементов, находящихся между первым и последним 
отрицательными элементами.
Обратите внимание, что массив после выбора должен остаться исходным: 
перезадавать его по новой для каждого выбора пользователем вычисления 
ненужно!)delimeter" };
        break;
    default:
        break;
    }
    cout << task << endl;
    Color(7);
    EN;
};

void t1() {
    srand(time(nullptr));
    const int N = 5;
    double arr[N];
    int choice;

    cout << "Automatic fill?" << endl
        << "1 - yes, 0 - no" << endl;
    cin >> choice;
    deleteLastOutput;

    if (!choice) {
        for (int i = 0; i < N; i++) {
            cout << "Enter number #" << i + 1 << " >> ";
            cin >> arr[i];
        }
    }
    else
    {
        for (int i = 0; i < N; i++) {
            arr[i] = rand() % 10000 / 100.0 * ((rand() % 2) ? 1 : -1);
        }
    }

    RU;
    cout << R"delimeter(Menu

a. Сумма отрицательных элементов;
b. Произведение элементов, находящихся между min и max элементами;
c. Произведение элементов с четными номерами;
d. Сумма элементов, находящихся между первым и последним 
отрицательными элементами.)delimeter";
    EN;

    while (true) {
        cout << endl;
        char choice2 = getNumber<char>("your choice");

        switch (choice2)
        {
        case 'a': {
            double sum = 0;
            for (int i : arr) {
                if (i < 0) sum += i;
            }
            cout << sum;
            break; }
        case 'b': {
            int minI = 0, maxI = 0;
            double min = arr[0], max = arr[0];

            double mul = 1;
            for (int i = 0; i < N; i++) {
                if (arr[i] < min) {
                    min = arr[i];
                    minI = i;
                }
                if (arr[i] > max) {
                    max = arr[i];
                    maxI = i;
                }
            }

            for (int i = min(minI, maxI); i <= max(minI, maxI); i++) {
                mul *= arr[i];
            }
            cout << mul;
            break; }
        case 'c': {
            double mul = 1;

            for (int i = 0; i < N; i+=2) {
                mul *= arr[i];
            }

            cout << mul;
            break; }
        case 'd': {

            double sum = 0;
            int negativeFirstI = 0, negativeLastI = 0;
            
            for (int i = 0; i < N; i++) {
                if (arr[i] < 0) { negativeFirstI = i; break; };
            }

            for (int i = N - 1; i >= 0; i--) {
                if (arr[i] < 0) { negativeLastI = i; break; };
            }

            for (int i = negativeFirstI; i <= negativeLastI; i++) {
                sum += arr[i];
            }
           
            cout << sum;
            break; }
        default:
            return;
            break;
        }

        cout << endl;
        sleep(1000);
    }
}

typedef void (*voidFuncton) ();
vector<voidFuncton> tasks = { t1 };

int main() {

    unsigned short int task = 1;
    while (true) {
        if (task > 1) {
            cout << "Enter task from " << 1 << " to " << tasks.size() << " (0 to exit) >> ";
            cin >> task;
        }
        if (tasks.size() >= task) {
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