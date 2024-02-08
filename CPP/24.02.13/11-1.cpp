#include <iostream>
#include <string>
#include <Windows.h>
#include <stdio.h>
#include <iomanip>
#include <regex>
#include <map>

#define RU setlocale(LC_ALL, "ru-RU");
#define EN setlocale(LC_ALL, "en-EN");
#define Color(n) SetConsoleTextAttribute(console, n);
#define tab "\t"

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

using namespace std;

template<typename T>
T getNumber(const char* what = "number") {
    T a;
    cout << "Enter " << what << " >> ";
    cin >> a;
    return a;
}

void printTask(int n) {
    RU;
    Color(3);
    string task;
    switch (n)
    {
    case 1:
        task = { R"delimeter(Пользователь вводит число. Необходимо организовать общение с пользователем с помощью меню,
в котором будет осуществляться выбор одной из следующих задач:
    1) определить количество цифр в этом числе, посчитать их сумму и среднее арифметическое;
    2) определить количество нулей в этом числе;
    3) закончить работу с программой по нажатию кнопки «0».)delimeter" };
        break;
    case 2:
        task = { R"delimeter(Написать программу, которая выводит на экран шахматную доску с заданным 
размером клетки. Каждая клетка представляет из себя квадрат из звездочек 
(условно белые клетки) или ~дефисов~ я сделал пробелы (условно черные клетки).)delimeter" };
        break;
    default:
        break;
    }
    cout << task << endl;
    Color(7);
    EN;
};

void t1() {
    unsigned int n = getNumber<int>();
    while (true) {
        cout << "Select option" << endl
            << "0. Exit" << endl
            << "1. Output amount of digits, their sum and average" << endl
            << "2. Output amount of zeros in number" << endl;
        int choice = getNumber<int>("your choice");

        string strN = to_string(n);
        long int sum = 0;
        int digits = 0;

        Color(2);
        switch (choice) {
        case 1:
            for (char c : strN) {
                sum += c - 48;
                digits++;
            }
            cout << "Sum of digits << " << sum << endl
                << "Average of digits << " << double(sum) / double(digits);
            break;
        case 2:
            for (char c : strN) {
                if (c == '0') digits++;
            }
            cout << "Amount of zeros in number << " << digits;
            break;
        default:
            Color(7);
            return;
            break;
        }
        Color(7);
        cout << endl;
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

void t2() {
    int side = getNumber<int>("square side");

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < side; j++) {
            for (int l = 0; l < 4; l++) {
                if (i % 2) {
                    print("  ", side);
                    print("* ", side);
                }
                else
                {
                    print("* ", side);
                    print("  ", side);
                }
            }
            cout << "\n";
        }
    }
}

int main() {
    int task;
    while (true) {
        cout << "Enter task (0 to exit) >> ";
        cin >> task;
        printTask(task);
        switch (task) { // There is must be a better way to do this
        case (1):
            t1();
            break;
        case (2):
            t2();
            break;
        default:
            exit(0);
            break;
        }
        cout << "\n\n";
    }
    return 0;
}