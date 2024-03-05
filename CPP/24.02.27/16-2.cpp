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
    /*1*/ "Написать функцию, выводящую на экран переданную ей игральную карту.",
    /*2*/ "Написать функцию, которая определяет, является ли «счастливым» шестизначное число.",
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

void PrintCard(int num) {
    switch (num)
    {
    case 1:
        cout << "   Ace   ";
        break;
    case 2:case 3:case 4:case 5:
        cerr << "Cards beetween 2-5 dont work lol";
        break;
    case 6:
        print("#     #\n\n", 3);
        break;
    case 7:
        print("#     #\n", 1);
        cout << "   #   \n";
        print("#     #\n\n", 2);
        break;
    case 8:
        print("#     #\n   #   \n", 2);
        print("#     #\n\n", 1);
        break;
    case 9:
        print("\n#     #\n", 2);
        cout << "   #   \n";
        print("#     #\n\n", 2);
        break;
    case 10:
        for (int i = 0; i < 2; i++) {
            print("#     #\n   #   \n", 1);
            print("#     #\n\n", 1);
        }
        break;
    case 11:
        cout << "   Jack";
        break;
    case 12:
        cout << "   Queen";
        break;
    case 13:
        cout << "   King";
        break;
    default:
        cerr << "Invalid card value";
        break;
    }
}

void t1() {
    // ♥ ♦ ♠ ♣
    // Масти не добавил, так как не знаю, как выводить юникод

    PrintCard(getNumber<int>("card value (11 for J, 12 for Q, 13 for K, 1 for A)"));
}

bool isHappy(long long num) {
    long long numCopy = num;
    while (numCopy > 9) {
        string strNum = to_string(numCopy);
        numCopy = 0;
        for (char c : strNum) {
            numCopy += pow(int(c - 48), 2);
        }
    }

    if (numCopy == 1) return true;
    return false;
}

void t2() {
    // Есть много представлений, о том, какие числа считаются счастливыми, я использовал, что если в цикле проверять, что сумма квадратов цифр числа == 1, число - счастливое
    /*
    Пример:
    192 -> 1^2 + 9^2 + 2^2 = 1 + 81 + 4 = 86
    86 -> 8^2 + 6^2 = 64 + 36 = 100
    100 -> 1^2 + 0^2 + 0^2 = 1 (Число счастливое, потому что в конце остался 0)
    */
    unsigned int num = getNumber<unsigned int>();
    cout << "Number is ";
    if (isHappy(num)) {
        cout << "happy" << endl;
    }
    else {
        cout << "not happy" << endl;
    }
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