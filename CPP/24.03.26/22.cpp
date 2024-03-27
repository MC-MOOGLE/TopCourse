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
    /*1*/ R"delimeter(Написать следующие функции для работы с динамическим массивом :

Функция распределения динамической памяти(аллоцирование нового участка памяти определенного размера).

Функция инициализации динамического массива(добавить возможность автоматического и ручного заполнения массива).

Функция печати динамического массива в консоль.

Функция удаления динамического массива(также занулять и указатель, по которому ранее была выделена память).

Функция добавления элемента в конец массива(связать с аллоцированием нового участка памяти).

Функция вставки элемента по указанному индексу(связать с аллоцированием нового участка памяти).

Функция удаления элемента по указанному индексу(связать с аллоцированием нового участка памяти).

В основную функцию добавить возможность вызова всех этих функций для проверки их работы.)delimeter",
/*2*/ "Написать функцию, которая получает указатель на динамический массив и его размер. Функция должна удалить из массива все простые числа и вернуть указатель на новый динамический массив. Не забудьте добавить функцию определения простоты числа. Для распределения памяти можно использовать функции из первого задания.",
/*3*/ "Написать функцию, которая получает указатель на статический массив и его размер. Функция распределяет положительные, отрицательные и нулевые элементы в отдельные динамические массивы. Для распределения памяти можно использовать функции из первого задания.",
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
            cout << "Executed in " << result.count() << " nanoseconds";
        }

    private:

        chrono::steady_clock::time_point t1;
        chrono::steady_clock::time_point t2;
        duration<double, std::nano> result;

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
    int size = 5;
    int* myArray = allocate(size);
    initializeArray(myArray, size);
    cout << "Array: ";
    printArray(myArray, size);

    cout << "Appended 10 in the end: ";
    append(myArray, size, 10);
    printArray(myArray, size);

    cout << "Inserted 20 at index 2: ";
    insert(myArray, size, 2, 20);
    printArray(myArray, size);

    cout << "Deleted index 1: ";
    remove(myArray, size, 1);
    printArray(myArray, size);

    deleteArray(myArray);
}

bool isPrime(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (!(n % i)) return false;
    }
    return true;
}

void t2() {
    int size = 10;
    int* myArray = allocate(size);
    initializeArray(myArray, size);
    cout << "Array:     ";
    printArray(myArray, size);

    for (int i = 0; i < size; i++) {
        if (isPrime(myArray[i])) {
            remove(myArray, size, i);
            i--;
        }
    }

    cout << "Modified:  ";
    printArray(myArray, size);
    deleteArray(myArray);
}

void t3() {
    int size = 10;
    int* myArray = allocate(size);
    initializeArray(myArray, size, true, true);
    cout << "Array:    ";
    printArray(myArray, size);

    int positiveSize = 0;
    int* positive = allocate(positiveSize);

    int negativeSize = 0;
    int* negative = allocate(negativeSize);

    for (int i = 0; i < size; i++) {
        if (myArray[i] > 0) append(positive, positiveSize, myArray[i]);
        if (myArray[i] < 0) append(negative, negativeSize, myArray[i]);
        
        if (myArray[i] != 0) {
            if (remove(myArray, size, i)) i--; // Я запихнул все нули в оригинальный массив, чтобы сэкономить память (Мне очень нужны эти 40 байт)
        }
    }

    cout << "Positive: ";
    printArray(positive, positiveSize);
    deleteArray(positive);

    cout << "Negative: ";
    printArray(negative, negativeSize);
    deleteArray(negative);

    cout << "Zeros:    ";
    printArray(myArray, size);
    deleteArray(myArray);
}