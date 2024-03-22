// Используются для базового функционала
#include <iostream>
#include <sstream>
#include <string>
#include <Windows.h>
#include <stdio.h>
#include <vector>

// Часто юзаемые
#include <chrono>
#include <thread>

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
using namespace std;

void t1();
void t2();
void t3();
void t4();
void t5();

typedef void (*voidFuncton) ();
vector<voidFuncton> tasks = { t1, t2, t3 };

string tasksText[] = {
    /*1*/ "Написать функцию, реализующую алгоритм линейного поиска заданного ключа в одномерном массиве.",
    /*2*/ "Написать функцию, реализующую алгоритм бинарного поиска заданного ключа в одномерном массиве.",
    /*3*/ "Написать функцию для перевода числа, записанного в двоичном виде, в десятичное представление.",
};

namespace Base {

    void RU() {
        setlocale(LC_ALL, "ru-RU");
    }

    void EN() {
        setlocale(LC_ALL, "en-EN");
    }

    void Color(int n) {
        SetConsoleTextAttribute(console, n);
        cout << n << endl;
    }

    void Color(string s) {
        string colors[] = {"Blue", "Green", "Cyan", "Red", "Purple", "Yellow", "White", "Grey", "Cyan", "LGreen", "LBlue", "LRed", "DPurple", "Skin", "LWhite"};

        int i = 0;
        for (string str : colors) {
            if (s == str) {
                Color(i);
                return;
            }
            i++;
        }
    }

    template<typename T>
    void getNumber(T* var, const char* what = "number", bool rewrite = false) {
        string input;
        if (rewrite) cout << what;
        else cout << "Enter " << what << " >> ";
        cin >> input;
        stringstream stream(input);
        if (stream >> *var) {
            if (!(stream.eof())) cout << "Incorrect input" << endl;
        }
        else {
            cout << "Not a number" << endl;
        }
    }

    void print(string str, int repeats, string end = "") {
        while (repeats > 0)
        {
            cout << str;
            repeats--;
        }
        cout << end;
    }

    void printTask(const unsigned short int n) {
        const unsigned short int lineLen = 60;
        RU();
        Color(3);
        if (tasksText->size() > n) {
            int i = 0;
            int lineChar = 0;
            string task = tasksText[n - 1];
            for (char c : task) {
                i++;
                if (c == '\n') lineChar = 0;
                if (lineChar > lineLen && c == ' ') {
                    task.insert(i, "\n");
                    lineChar = 0;
                }
                lineChar++;
            }
            cout << task << endl;
        }
        Color(7);
        EN();
        return;
    };

    void LaunchTask() {
        unsigned short int task;
        while (true) {
            if (tasks.size() > 1) {
                cout << "Enter task from " << 1 << " to " << tasks.size() << " (0 to exit) >> ";
                getNumber(&task, "", true);
            }
            else if (tasks.size() == 1) {
                task = 1;
                cout << "Enter 1 to continue, 0 to exit >> ";
                getNumber(&task, "", true);
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
    }
}

namespace Customs {

    void sleep(unsigned int n) {
        this_thread::sleep_for(chrono::milliseconds(n));
    };

    void deleteLastOutput() {
        cout << "\x1b[A" << "\x1b[2K";
    }

    template <typename T>
    int partition(T* arr, int low, int high);

    template <typename T>
    void quickSort(T* arr, int low, int high);

    template <typename T>
    void sort(T* arr, int low, int high) {
        quickSort(arr, low, high - 1);
    }

    template <typename T>
    void quickSort(T* arr, int low, int high) {
        if (low < high) {
            int pivot = partition(arr, low, high);
            quickSort(arr, low, pivot - 1);
            quickSort(arr, pivot + 1, high);
        }
    }

    template <typename T>
    int partition(T* arr, int low, int high) {
        T pivot = arr[high];
        int i = (low - 1);

        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return (i + 1);
    }
}

using namespace Base;

int main() {
    LaunchTask();
    return 0;
}

// Сами задания

void t1() {
    srand(time(nullptr));
    const unsigned int size = 10;
    int* a = new int[size];
    for (int i = 0; i < size; i++) {
        *(a + i) = rand() % 100;
        cout << *(a + i) << " ";
    }
    cout << endl;

    Customs::sort(a, 0, size);

    for (int i = 0; i < size; i++) {
        cout << *(a + i) << " ";
    }

    delete[] a;
} 

void t2() {
    srand(time(nullptr));
    const unsigned int size = 10;
    int* a = new int[size];
    for (int i = 0; i < size; i++) {
        *(a + i) = rand() % 100;
        cout << *(a + i) << " ";
    }
    cout << endl;

    Customs::sort(a, 0, size);

    for (int i = 0; i < size; i++) {
        cout << *(a + i) << " ";
    }

    delete[] a;
}

void t3() {
    
}