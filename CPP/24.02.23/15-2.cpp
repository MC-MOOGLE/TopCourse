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
    /*1*/ "Создайте двухмерный массив. Заполните его случайными числами и покажите на экран. Пользователь выбирает количество сдвигов и положение(влево, вправо, вверх, вниз).Выполнить сдвиг массива и показать на экран полученный результат. Сдвиг циклический. ",
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

void t1() {
    srand(time(nullptr));
    const int x = 7, y = 9;
    int arr[x][y];
    int newArr[x][y];

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            arr[i][j] = rand() % 100;
        }
    }

    cout << "Old" << endl;
    for (int i = 0; i < x; i++) {
        cout << "[" << i << "] = { ";
        for (int j = 0; j < y; j++) {
            cout << arr[i][j] << ", ";
        }
        cout << "\b\b }\n";
    }

    unsigned int offset = getNumber<int>("offset");
    int direction = getNumber<int>("direction (0 - left, 1 - right, 2 - up, 3 - down)");
    cout << endl;

    if (direction == 0 || direction == 1) offset %= x;
    else if (direction == 2 || direction == 3) offset %= y;
    else {
        cout << "Number is not in range";
        return;
    }

    switch (direction)
    {
    case 0:
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                newArr[i][j] = arr[i][j + offset];
            }
        }

        for (int i = 0; i < x; i++) {
            for (int j = offset - 1; j >= 0; j--) {
                newArr[i][y - offset + j] = arr[i][j];
            }
        }
        break;
    case 1:
        for (int i = 0; i < x; i++) {
            for (int j = offset; j < y; j++) {
                newArr[i][j] = arr[i][j - offset];
            }
        }

        for (int i = 0; i < x; i++) {
            for (int j = y - offset; j < y; j++) {
                newArr[i][j - (y - offset)] = arr[i][j];
            }
        }
        break;
    case 2:
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                newArr[i][j] = arr[i + offset][j];
            }
        }

        for (int i = 0; i < offset; i++) {
            for (int j = 0; j < y; j++) {
                newArr[x - offset + i][j] = arr[i][j];
            }
        }
        break;
    case 3:
        for (int i = offset; i < x; i++) {
            for (int j = 0; j < y; j++) {
                newArr[i][j] = arr[i - offset][j];
            }
        }

        for (int i = x - offset; i < x; i++) {
            for (int j = 0; j < y; j++) {
                newArr[i - (x - offset)][j] = arr[i][j];
            }
        }
        break;
    default:
        break;
    }

    cout << "New" << endl;
    for (int i = 0; i < x; i++) {
        cout << "[" << i << "] = { ";
        for (int j = 0; j < y; j++) {
            cout << newArr[i][j] << ", ";
        }
        cout << "\b\b }\n";
    }
}

// Запуск заданий

typedef void (*voidFuncton) ();
vector<voidFuncton> tasks = { t1 };

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