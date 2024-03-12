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
void getNumber(T *var, const char* what = "number") {
    string input;
    cout << "Enter " << what << " >> ";
    cin >> input;
    stringstream stream(input);
    if (stream >> *var) {
        if (!(stream.eof())) cout << "Incorrect input" << endl;
    }
    else {
        cout << "Not a num" << endl;
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
    /*1*/ "Написать перегруженные функции (int, double, char) для выполнения следующих задач:\n- Инициализация квадратной матрицы;\n- Вывод матрицы на экран;\n- Определение максимального и минимального элемента на главной диагонали матрицы;\n- Сортировка элементов по возрастанию отдельно для каждой строки матрицы.",
    /*2*/ "Написать рекурсивную функцию нахождения наибольшего общего делителя двух целых чисел.",
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

// Используются в заданиях
// ...

// Сами задания

// t1

void initializeMatrix(vector<vector<double>> &matrix, double min, double max) {
    srand(time(nullptr));
    for (auto& row : matrix) {
        for (auto& elem : row) {
            elem = double(rand() % int((max - min) * 100)) / 100 + min;
        }
    }
}

template <typename T>
void initializeMatrix(vector<vector<T>> &matrix, int min, int max) {
    srand(time(nullptr));
    for (auto &row : matrix) {
        for (auto &elem : row) {
            elem = (rand() % (max - min)) + min;
        }
    }
}

template <typename T>
void printMatrix(const vector<vector<T>> &matrix) {
    for (const auto &row : matrix) {
        for (const T &elem : row) {
            cout << elem << ' ';
        }
        cout << endl;
    }
}

template <typename T>
void findMinMaxOnDiagonal(const vector<vector<T>> &matrix, T &min, T &max) {
    min = max = matrix[0][0];
    for (int i = 0; i < matrix.size(); ++i) {
        if (matrix[i][i] < min) min = matrix[i][i];
        if (matrix[i][i] > max) max = matrix[i][i];
    }
}

template <typename T>
void sortRows(vector<vector<T>> &matrix) {
    for (auto &row : matrix) {
        sort(row.begin(), row.end());
    }
}

template <typename T>
void t1Extra(int size = 1, T min = 0, T max = 0) {
    
    vector<vector<T>> matrix(size, vector<T>(size));

    initializeMatrix(matrix, min, max);

    // Вывод матрицы на экран
    cout << "1. Generated matrix:\n";
    printMatrix(matrix);

    // Определение макс и мин на главной диагонали
    T minElem, maxElem;
    findMinMaxOnDiagonal(matrix, minElem, maxElem);
    cout << "\n2. Values on main diagonal:\n"
        << "Min value on the main diagonal: " << minElem << '\n'
        << "Max value on the main diagonal: " << maxElem << '\n';

    // Сортировка элементов отдельно для каждой строки
    sortRows(matrix);
    cout << "\n3. Sorted: \n";
    printMatrix(matrix);
}


void t1() {
    int size;
    getNumber(&size, "matrix side");
    auto min = 'a',
         max = 'z';
    t1Extra(size, min, max);
}

// t2

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void t2() {
    int a, b;
    
    getNumber(&a);
    getNumber(&b);

    cout << gcd(a, b);
}

// Запуск заданий

typedef void (*voidFuncton) ();
vector<voidFuncton> tasks = { t1, t2 };

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