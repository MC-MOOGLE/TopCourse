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

// Используются в заданиях
#include <algorithm>


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

string tasksText[] = {
    /*1*/ "Используя два указателя на массив целых чисел, скопировать один массив в другой. Использовать в программе арифметику указателей для продвижения по массиву, а также оператор разыменования – обязательно!",
    /*2*/ "Используя указатель на массив целых чисел, изменить порядок следования элементов массива на противоположный. Использовать в программе арифметику указателей для продвижения по массиву, а также оператор разыменования – обязательно!",
    /*3*/ "Используя два указателя на массивы целых чисел, скопировать один массив в другой так, чтобы во втором массиве элементы находились в обратном порядке. Использовать в программе арифметику указателей для продвижения по массиву, а также оператор разыменования – обязательно!",
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
    EN;
    return;
};

// Часто юзаемые

template <typename T>
void arrFillRand(T* arr, int size, int min = 0, int max = 100) {
    for (int i = 0; i < size; i++) {
        *(arr + i) = rand() % max + min;
    }
}

template <typename T>
void printArr(T* arr, unsigned int size) {
    for (int i = 0; i < size; i++) {
        cout << *(arr + i) << " ";
    }
    if (size > 0) cout << endl;
}

// Используются в заданиях
// ...

void t1();
void t2();
void t3();

// Запуск заданий

typedef void (*voidFuncton) ();
vector<voidFuncton> tasks = { t1, t2, t3 };

int main() {

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
    return 0;
}

// Сами задания

int* mergeArrs(int* A, int* B, unsigned short int A_n, unsigned short int B_n) {

    int* newArr = new int[A_n + B_n];

    for (int i = 0; i < A_n; i++) {
        *(newArr + i) = A[i];
    }

    for (int i = 0; i < B_n; i++) {
        *(newArr + i + A_n) = B[i];
    }

    return newArr;
}

void t1() {
    srand(time(nullptr));

    int* A;
    int* B;
    unsigned short int A_n, B_n;

    getNumber(&A_n, "first arr len");
    getNumber(&B_n, "second arr len");

    A = new int[A_n];
    B = new int[B_n];

    arrFillRand(A, A_n);
    arrFillRand(B, B_n);

    printArr(A, A_n);
    printArr(B, B_n);

    int* C = mergeArrs(A, B, A_n, B_n);

    printArr(C, A_n + B_n);

    delete[] A;
    delete[] B;
    delete[] C;
}

void arr_reverse(int* A, unsigned short int A_n) {
    int* copy = new int[A_n];
    for (int i = 0; i < A_n; i++) {
        *(copy + i) = *(A + i);
    }

    for (int i = 0; i < A_n; i++) {
        *(A + i) = *(copy + A_n - i - 1);
    }
}

void t2() {
    srand(time(nullptr));

    int* A;
    unsigned short int A_n;

    getNumber(&A_n, "arr len");

    A = new int[A_n];

    arrFillRand(A, A_n);

    printArr(A, A_n);

    arr_reverse(A, A_n);

    printArr(A, A_n);

    delete[] A;
}

void t3() {
    srand(time(nullptr));

    int* A;
    int* B;
    unsigned short int A_n, B_n;

    getNumber(&A_n, "first arr len");
    getNumber(&B_n, "second arr len");

    A = new int[A_n];
    B = new int[B_n];

    arrFillRand(A, A_n);
    arrFillRand(B, B_n);

    printArr(A, A_n);
    printArr(B, B_n);

    arr_reverse(B, B_n);

    int* C = mergeArrs(A, B, A_n, B_n);

    printArr(C, A_n + B_n);

    delete[] A;
    delete[] B;
    delete[] C;
}