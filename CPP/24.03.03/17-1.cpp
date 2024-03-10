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
    /*1*/ "Написать функцию, которая принимает две даты (т.е. функция принимает шесть параметров) и вычисляет разность в днях между этими датами. Для решения этой задачи необходимо также написать функцию, которая определяет, является ли год високосным.",
    /*2*/ "Написать функцию, определяющую среднее арифметическое элементов передаваемого ей массива",
    /*3*/ "Написать функцию, определяющую количество положительных, отрицательных и нулевых элементов передаваемого ей массива.",
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

// Используются в заданиях

template <typename T>
vector<T> *createVector(int &size = 0) {

    vector <T> *arr = new vector<T>();
    cout << "Enter -1 to confirm array\n";
    for (int i = 0;; i++) {
        double a;
        cout << "Enter array[" << i << "] >> ";
        cin >> a;
        if (a == -1) break;
        arr->push_back(a);
        size++;
    }
    return arr;
}

// Сами задания

// t1

class date {
public:
    date(int _day, int _month, int _year) {
        set_day(_day);
        set_month(_month);
        set_year(_year);
    }

    void set_day(unsigned int _) { // using snake_case, cuz its more readable for get / set, then camelCase
        if (_ > 31) {
            _ = 31;
            warning("Days");
        }
        day = _;
    }

    void set_month(unsigned int _) {
        if (_ > 12) {
            _ = 12;
            warning("Month");
        }
        month = _;
    }

    void set_year(int _) {
        year = _;
    }

    int get_day() {
        return day;
    }

    int get_month() {
        return month;
    }

    int get_year() {
        return year;
    }
private:
    int day, month, year;

    void warning(string what) {
        cout << what << " value is out of range. Rounded to largest possible value" << endl;
    }
};

bool isLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int calculateDateDifference(date date1, date date2) {
    /*int monthDays[12];
    for (int i = 0; i < 12; i++) {
        monthDays[i] = ((i % 2) ? 30 : 31);
        cout << monthDays[i] << " ";
    }*/

    unsigned const int monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    unsigned int day1 = date1.get_day();
    unsigned int month1 = date1.get_month();
    int year1 = date1.get_year();

    unsigned int day2 = date2.get_day();
    unsigned int month2 = date2.get_month();
    int year2 = date2.get_year();

    long int n1 = year1 * 365 + day1;
    for (int i = 0; i < month1 - 1; i++) {
        n1 += monthDays[i];
    }

    long int n2 = year2 * 365 + day2;
    for (int i = 0; i < month2 - 1; i++) {
        n2 += monthDays[i];
    }
 
    n1 += (year1 - 1) / 4 - (year1 - 1) / 100 + (year1 - 1) / 400;
    n2 += (year2 - 1) / 4 - (year2 - 1) / 100 + (year2 - 1) / 400;


    if (month1 <= 2) {
        year1--;
    }
    if (month2 <= 2) {
        year2--;
    }

    return (n2 - n1);
}

void t1() {
    /*date date1(1, 2, 2003);
    date date2(4, 5, 2006);*/

    unsigned int day1 = getNumber<unsigned int>("starting date day");
    unsigned int month1 = getNumber<unsigned int>("starting date month");
    date date1(day1, month1, getNumber<int>("starting date year"));

    unsigned int day2 = getNumber<unsigned int>("ending date day");
    unsigned int month2 = getNumber<unsigned int>("ending date month");
    date date2(day2, month2, getNumber<int>("ending date year"));

    std::cout << "Difference in days: " << calculateDateDifference(date1, date2) << std::endl;
}

// t2

template<typename T>
double avg(T arr, const int size) { // Not a pointer bcuz vector
    double sum = 0;

    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    if (!size) return 0;
    return sum / size;
}

void t2() {
    int size = 0;
    vector<double> *arr = createVector<double>(size);
    cout << "Average of array is " << avg(*arr, size);
}

// t3

template<typename T>
void countArr(T arr, const int size, int* result) {
    int pos = 0, neg = 0, zero = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) pos++;
        else if (arr[i] < 0) neg++;
        else zero++;
    }

    if (!size) return;
    result[0] = pos;
    result[1] = neg;
    result[2] = zero;
    //neg, zero;
    return;
}

void t3() {
    int size = 0;
    vector<double>* arr = createVector<double>(size);
    int result[3] = { 0, 0, 0 };
    countArr(*arr, size, result);
    cout << "\nPositive numbers << " << result[0] << "\nNegative numbers << " << result[1] << "\nZeros << " << result[2];
}

// Запуск заданий

typedef void (*voidFuncton) ();
vector<voidFuncton> tasks = { t1, t2, t3 };

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