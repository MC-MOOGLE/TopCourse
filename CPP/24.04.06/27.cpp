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
vector<voidFuncton> tasks = { t1, t2 };

string tasksText[] = {
    /*1*/ R"delimeter(Пользователь вводит положительное число N. Необходимо найти наименьшее 
количество чисел, являющихся квадратами, которое в сумме дает N.
Примеры:
Число 17 можно составить из чисел 16 и 1;
Число 15 можно составить из чисел 9, 4, 1 и 1.
Число 16 можно составить только из самого числа 16.
Вывести на экран сформированный массив. Используйте динамические массивы!)delimeter",

/*2*/ R"delimeter(Дана шахматная доска размером 8x8 и шахматный конь. Программа должна 
запросить у пользователя координаты клетки поля и поставить туда коня. Задача 
программы найти и вывести путь коня, при котором он обойдет все клетки доски, 
становясь в каждую клетку только один раз. (Так как процесс отыскания пути для 
разных начальных клеток может затянуться, то рекомендуется сначала 
опробовать задачу на поле размером 6x6). В программе необходимо 
использовать рекурсию.)delimeter",
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
    }

    void Color(string s) {
        string colors[] = { "Blue", "Green", "Cyan", "Red", "Purple", "Yellow", "White", "Grey", "Cyan", "LGreen", "LBlue", "LRed", "DPurple", "Skin", "LWhite" };

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
        const unsigned short int lineLen = 80;
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
        srand(time(nullptr));
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

    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;

    class measureTime {
    public:

        void startTimer() {
            t1 = now();
        }

        void stopTimer() {
            t2 = now();

            result = t2 - t1;
        }

        void printTimer() {
            cout << "Executed in " << result.count() << " milliseconds";
        }

    private:

        chrono::steady_clock::time_point t1;
        chrono::steady_clock::time_point t2;
        duration<double, std::milli> result;

        chrono::steady_clock::time_point now() {
            return high_resolution_clock::now();
        }
    };

    void sleep(unsigned int n) {
        this_thread::sleep_for(chrono::milliseconds(n));
    }

    void deleteLastOutput() {
        cout << "\x1b[A" << "\x1b[2K";
    }
}

namespace Array {

    template <typename T>
    int LinearSearch(T* arr, int size, int key) {
        for (int i = 0; i < size; i++) {
            if (*(arr + i) == key) return i;
        }
        return -1;
    }

    template <typename T>
    int BinarySearch(T* arr, int size, int key) {
        int left = 0, right = --size, mid;
        while (left <= right) {
            mid = (right - left) / 2;

            if (arr[mid] == key) return mid;
            else if (arr[mid] > key) right = mid;
            else left = mid;

        }

        return -1;
    }

    int* allocate(int size) {
        return new int[size];
    }

    short int* allocate(short int size) {
        return new short int[size];
    }

    long long* allocate(long long size) {
        return new long long[size];
    }

    double* allocate(double size) {
        return new double[size];
    }

    float* allocate(float size) {
        return new float[size];
    }

    char* allocate(char size) {
        return new char[size];
    }

    template <typename T>
    void initializeArray(T* array, int size, bool autoFill = true, bool negatives = false) {
        if (autoFill) {
            for (int i = 0; i < size; ++i) {
                array[i] = rand() % 100;
                if (negatives) array[i] -= 50;
            }
        }
        else {
            cout << "Введите " << size << " элементов массива:\n";
            for (int i = 0; i < size; ++i) {
                cout << "[" << i << "] = ";
                cin >> array[i];
                Customs::deleteLastOutput();
            }
        }
    }

    template <typename T>
    void printArray(T* array, int size) {
        for (int i = 0; i < size; ++i) {
            cout << array[i] << ' ';
        }
        cout << endl;
    }

    template <typename T>
    void deleteArray(T*& array) {
        delete[] array;
        array = nullptr;
    }

    template <typename T>
    void append(T*& array, int& size, T element) {
        T* newArray = allocate(size + 1);
        for (int i = 0; i < size; ++i) {
            newArray[i] = array[i];
        }
        newArray[size] = element;
        delete[] array;
        array = newArray;
        ++size;
    }

    template <typename T>
    void insert(T*& array, int& size, int index, T element) {
        if (index > size) {
            cerr << "Index is out of range" << endl;
            return;
        }
        T* newArray = allocate(size + 1);
        for (int i = 0; i < index; ++i) {
            newArray[i] = array[i];
        }
        newArray[index] = element;
        for (int i = index; i < size; ++i) {
            newArray[i + 1] = array[i];
        }
        delete[] array;
        ++size;
        array = newArray;
    }

    template <typename T>
    bool remove(T*& array, int& size, int index) {
        if (size - 1 < 0) {
            cerr << "Array doesnt have any values" << endl;
            return false;
        }
        if (index >= size) {
            cerr << "Index is out of range" << endl;
            return false;
        }
        T* newArray = allocate(size - 1);
        for (int i = 0; i < index; ++i) {
            newArray[i] = array[i];
        }
        for (int i = index + 1; i < size; ++i) {
            newArray[i - 1] = array[i];
        }
        delete[] array;
        --size;
        array = newArray;
        return true;
    }

    // Technical

    template <typename T>
    int partition(T* arr, int low, int high);

    template <typename T>
    void quickSort(T* arr, int low, int high);

    template <typename T>
    void sort(T* arr, int high, int low = 0) {
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

using namespace Array;

void t1() {
    int N;
    getNumber(&N);
    if (N <= 0) {
        cout << "Input must be greater than 0";
        return;
    }

    int size = 0;

    int* squares = allocate(size);

    for (int i = 1; i * i <= N; i++) {
        append(squares, size, i * i);
    }

    int sizeRes = 0;
    int* result = allocate(sizeRes);
    int sum = 0;
    for (int i = size - 1; i >= 0; i--) {
        while (sum + squares[i] <= N) {
            sum += squares[i];
            append(result, sizeRes, squares[i]);
        }
    }

    cout << "[";
    for (int i = 0; i < sizeRes; i++) {
        cout << result[i];
        if (i != sizeRes - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

/////////////

#define BOARD_SIZE 8

int solveKnightTourUtil(int currentX, int currentY, int moveIndex, int solution[BOARD_SIZE][BOARD_SIZE], int xMoves[], int yMoves[]);

int isMoveSafe(int x, int y, int solution[BOARD_SIZE][BOARD_SIZE]) {
    return (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE && solution[x][y] == -1);
}

void printSolution(int solution[BOARD_SIZE][BOARD_SIZE]) {
    for (int x = 0; x < BOARD_SIZE; x++) {
        for (int y = 0; y < BOARD_SIZE; y++) {
            if (solution[x][y] < 10) {
                cout << "  " << solution[x][y] << " ";
            }
            else {
                cout << " " << solution[x][y] << " ";
            }
        }
        cout << endl;
    }
}

int solveKnightTour(int startX, int startY) {
    if (startX > BOARD_SIZE - 1 || startY > BOARD_SIZE - 1 || startX < 0 || startY < 0) {
        cerr << "Incorrect input. Enter value between 0-" << BOARD_SIZE - 1 << endl;
        return -1;
    }
    int solution[BOARD_SIZE][BOARD_SIZE];

    for (int x = 0; x < BOARD_SIZE; x++)
        for (int y = 0; y < BOARD_SIZE; y++)
            solution[x][y] = -1;

    int xMoves[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int yMoves[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

    solution[startX][startY] = 0;

    if (solveKnightTourUtil(startX, startY, 1, solution, xMoves, yMoves) == 0) {
        cout << "Solution does not exist" << endl;
        return 0;
    }
    else printSolution(solution);

    return 1;
}

int solveKnightTourUtil(int currentX, int currentY, int moveIndex, int solution[BOARD_SIZE][BOARD_SIZE], int xMoves[8], int yMoves[8]) {
    int k, nextX, nextY;
    if (moveIndex == BOARD_SIZE * BOARD_SIZE) return 1;

    for (k = 0; k < 8; k++) {
        nextX = currentX + xMoves[k];
        nextY = currentY + yMoves[k];
        if (isMoveSafe(nextX, nextY, solution)) {
            solution[nextX][nextY] = moveIndex;
            if (solveKnightTourUtil(nextX, nextY, moveIndex + 1, solution, xMoves, yMoves) == 1) return 1;
            else solution[nextX][nextY] = -1;
        }
    }
    return 0;
}

void t2()
{
    int startX, startY;
    getNumber(&startX, "startX");
    getNumber(&startY, "startY");
    Customs::measureTime timer;
    timer.startTimer();
    solveKnightTour(startX, startY);
    timer.stopTimer();
    timer.printTimer();
}


/// Первая версия (Полностью написанная вручную)

/*
int boardSize = 8;

void printBoard(int** board) {
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int moves[8][2] = {
    {2, 1},
    {2, -1},
    {-2, 1},
    {-2, -1},
    {1, 2},
    {1, -2},
    {-1, 2},
    {-1, -2}
};

int scanMoves(int** board, int x, int y, int workingID = -1) {

    if (workingID == -1) {
        for (int i = 0; i < 8; i++) {
            if (x + moves[i][0] < 8 && x + moves[i][0] >= 0) {
                if (y + moves[i][1] < 8 && y + moves[i][1] >= 0) {
                    if (board[x + moves[i][0]][y + moves[i][1]] >= 0) {
                        board[x + moves[i][0]][y + moves[i][1]] += 1;
                        printBoard(board);
                        scanMoves(board, x + moves[i][0], y + moves[i][1]);
                    }
                }
            }
        }
    }
    else {
        board[x + moves[workingID][0]][y + moves[workingID][1]] = 1;
    }

    printBoard(board);
    cout << '\n';
    return workingID;
}

void t2() {
    int** board = new int*[boardSize];

    for (int i = 0; i < boardSize; i++) {
        board[i] = new int[boardSize];
        for (int j = 0; j < boardSize; j++) {
            board[i][j] = 0;
        }
    }

    int x = 3, y = 3;
    int workingID = scanMoves(board, x, y);
    while (true) {
        x += moves[workingID][0];
        y += moves[workingID][1];
        workingID = scanMoves(board, x, y);
        if (workingID == -1) {
            break;
        }
    }
}*/