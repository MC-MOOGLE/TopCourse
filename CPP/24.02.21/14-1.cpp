// Используются для базового функционала
#include <iostream>
#include <string>
#include <Windows.h>
#include <stdio.h>
#include <vector>
// Используются в заданиях
#include <chrono>
#include <thread>

// Используются для базового функционала
#define RU setlocale(LC_ALL, "ru-RU");
#define EN setlocale(LC_ALL, "en-EN");
#define Color(n) SetConsoleTextAttribute(console, n);

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

using namespace std;

// Используются в заданиях
#define sleep(n) this_thread::sleep_for(chrono::milliseconds(n));
#define deleteLastOutput cout << "\x1b[A" << "\x1b[2K";

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
    /*1*/ "Написать программу, имитирующую часы с кукушкой. Пользователь вводит час, а программа должна вывести на экран нужное количество раз слово «Ку-ку». Использовать 12-часовое представление времени.",
    /*2*/ "Написать программу, вычисляющую N-ое число факториала.",
    /*3*/ "Написать программу, вычисляющую N-ое значение Фибоначчи.",
    /*4*/ "Есть кофемашина, которая умеет готовить два вида напитков: американо и латте. Для американо требуется 300 мл воды, а для латте 30 мл воды и 270 мл молока. Необходимо написать программу - прошивку для аппарата, которая запрашивает у пользователя остаток воды и молока на текущий момент и далее в цикле запрашивает виды напитков и готовит их.Цикл продолжается до тех пор, пока пользователь не выберет кнопку выхода или пока не закончатся жидкости для приготовления кофе. Если на приготовление выбранного пользователем напитка не хватает какой - либо жидкости, необходимо вывести на экран сообщение о невозможности приготовления напитка и не готовить его.",
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

void t1() {
    unsigned int time = getNumber<unsigned int>("time");

    if (!time) return;

    time %= 12;

    if (!time) time = 12;

    for (int i = 0; i < time; i++) {
        cout << "KY-KY" << endl;
    }
}

void t2() {
    unsigned int n = getNumber<int>();
    long long result = 1;

    for (int i = 2; i <= n; i++) {
        result *= i;
    }

    string num = "th";

    if (n == 1) num = "st";
    else if (n == 2) num = "nd";
    else if (n == 3) num = "rd";
    else if (!n) num = "'s";

    cout << n << num << " number is " << result;
}

void t3() {
    unsigned int n = getNumber<int>();
    long long result = 0, prev = 1, prevprev = 0;

    for (int i = 2; i < n; i++) {
        result = prev + prevprev;
        if (result < 0) {
            cout << "Number is too big";
            return;
        }
        prevprev = prev;
        prev = result;
    }

    if (n == 2) result = 1;

    cout << result;
}

void t4() {
    int water = getNumber<int>("water amount"), milk = getNumber<int>("milk amoount");
    unsigned int americano[] = {300, 0}, latte[] = {30, 270}; // 
    short int choice;

    while (true) {
        if (water <= 0 || milk <= 0) {
            cout << "Please refill your coffemachine";
            return;
        }
        cout << "0. Exit, 1. Americano, 2. Latte" << endl;
        choice = getNumber<int>("your choice");
        
        switch (choice)
        {
        case 0:
            return;
            break;
        case 1: case 2: {
            unsigned int(&chosenDrink)[2] = ((choice == 1) ? americano : latte);
            water -= chosenDrink[0];
            milk -= chosenDrink[1];

            if (water < 0 || milk < 0) {
                cout << "Not enough materials.";
                water += chosenDrink[0];
                milk += chosenDrink[1];
                break;
            }

            break; }
        default:
            cout << "Not a choice";
            break;
        }

        cout << "\nRemaining water: " << water << "; milk: " << milk << endl;
    }
}

typedef void (*voidFuncton) ();
vector<voidFuncton> tasks = { t1, t2, t3, t4 };

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