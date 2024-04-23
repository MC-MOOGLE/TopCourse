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
vector<voidFuncton> tasks = { t1 };

string tasksText[] = {
    /*1*/ R"delimeter(Задание 1. Написать функцию, которая удаляет из строки
символ с заданным номером.
Задание 2. Написать функцию, которая удаляет из строки
все вхождения в нее заданного символа.
Задание 3. Написать функцию, которая вставляет в строку
в указанную позицию заданный символ.
Задание 4. Написать программу, которая заменяет все
символы точки «.» в строке, введенной пользователем,
на символы восклицательного знака «!».
Задание 5. Пользователь вводит строку символов и ис-
комый символ, посчитать сколько раз он встречается
в строке.
Задание 6. Пользователь вводит строку. Определить ко-
личество букв, количество цифр и количество остальных
символов, присутствующих в строке.)delimeter",
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

namespace Task {

    int task = 1;

    void printStr(string& str) {
        cout << "Task " << task << ": " << str << endl;
        task++;
    }

    void remove(string& str, int index) {
        if (index >= 0 && index < str.size()) {
            str.erase(index, 1);
        }
    }

    void erase(string& str, char ch, char rplc = ' ') {
        str.erase(remove(str.begin(), str.end(), ch), str.end());
    }

    void insert(string& str, int index, char ch) {
        if (index >= 0 && index <= str.size()) {
            str.insert(index, 1, ch);
        }
    }

    void replace(string& str, char ch, char rplc = ' ') {
        for (int i = 0; i < str.length(); i++) {
            if (ch == str[i]) str[i] = rplc;
        }
    }

    void replaceDots(string& str) {
        replace(str, '.', '!');
    }

    int count(const string& str, char ch) {
        return count(str.begin(), str.end(), ch); // New "revolutionary" AI startups be like
    }

    void getTypes(const string& str, int& letters, int& digits, int& others) {
        letters = digits = others = 0;
        for (char ch : str) {
            if (isalpha(ch)) {
                ++letters;
            }
            else if (isdigit(ch)) {
                ++digits;
            }
            else {
                ++others;
            }
        }
    }
}

void t1() {
    string str;
    cout << "Enter string (0 for example string) >> ";
    cin >> str;

    if (str == "0") {
        str = "AB.1CD,1E.123..";
        cout << "String << " << str << endl;
    }

    Task::remove(str, 3);
    Task::printStr(str);

    Task::erase(str, 'D');
    Task::printStr(str);

    Task::insert(str, 5, 'X');
    Task::printStr(str);

    Task::replaceDots(str);
    Task::printStr(str);

    cout << "Task 5: " << Task::count(str, '1') << " appearances of '1'" << endl;

    int letters, digits, others;
    Task::getTypes(str, letters, digits, others);
    cout << "Task 6: Letters: " << letters << ", digits: " << digits << ", other characters: " << others << endl;
}