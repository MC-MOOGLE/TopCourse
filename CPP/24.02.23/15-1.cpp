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
    /*1*/ "Напишите программу, которая создает двухмерный массив и заполняет его по следующему принципу: пользователь вводит число (например, 3) первый элемент массива принимает значение этого числа, последующий элемент массива принимает значение этого числа умноженного на 2 (т.е. 6 для нашего примера), третий элемент массива предыдущий элемент умноженный на 2 (т.е. 6*2=12 для нашего примера). Созданный массив вывести на экран.",
    /*2*/ "Напишите программу, которая создает двухмерный массив и заполняет его по следующему принципу: пользователь вводит число (например, 3) первый элемент массива принимает значение этого числа, последующий элемент массива принимает значение этого числа + 1 (т.е. 4 для нашего примера), третий элемент массива = предыдущий элемент + 1 (т.е. 5 для нашего примера). Созданный массив вывести на экран.",
};

void printTask(unsigned short int n) {
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
    unsigned short int len;
    int input;

    cout << "=== Setup ===" << endl;
    len = getNumber<unsigned int>("n where array = {input * 1, input * 2 ... input * n}");
    deleteLastOutput;
    deleteLastOutput;

    vector<vector<int>> vect;

    int i = 0;
    while (true) {
        input = getNumber<int>("number (0 to exit)");
        if (!input) break;

        vect.push_back(vector<int>(len));
        for (int j = 0; j < len; j++) {
            vect[i][j] = input * (j + 1);
        }

        i++;
    }

    for (int i = 0; i < vect.size(); i++) {
        cout << "[" << i << "] = { ";
        for (int j = 0; j < len; j++) {
            cout << vect[i][j] << ", ";
        }
        cout << "\b\b }\n";
    }
}

void t2() {
    unsigned short int len;
    int input;

    cout << "=== Setup ===" << endl;
    len = getNumber<unsigned int>("n where array = {input, input + 1 ... input + n}");
    len++;
    deleteLastOutput;
    deleteLastOutput;

    vector<vector<int>> vect;

    int i = 0;
    while (true) {
        input = getNumber<int>("number (0 to exit)");
        if (!input) break;

        vect.push_back(vector<int>(len));
        for (int j = 0; j < len; j++) {
            vect[i][j] = input + j;
        }

        i++;
    }

    for (int i = 0; i < vect.size(); i++) {
        cout << "[" << i << "] = { ";
        for (int j = 0; j < len; j++) {
            cout << vect[i][j] << ", ";
        }
        cout << "\b\b }\n";
    }
}

// Запуск заданий

typedef void (*voidFuncton) ();
vector<voidFuncton> tasks = { t1, t2 };

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