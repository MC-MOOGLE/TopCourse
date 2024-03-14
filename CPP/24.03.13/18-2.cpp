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
    /*1*/ "Написать игру «Быки и коровы». Программа «загадывает» четырёхзначное число и играющий должен угадать его.После ввода пользователем числа программа сообщает, сколько цифр числа угадано(быки) и сколько цифр угадано и стоит на нужном месте(коровы).После отгадывания числа на экран необходимо вывести количество сделанных пользователем попыток.В программе необходимо использовать рекурсию.",
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

// Запуск заданий

void t1();
void t2();
void t3();
void t4();
void t5();

typedef void (*voidFuncton) ();
vector<voidFuncton> tasks = { t1 };

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

// t1

int game(int a, const string answer) {
    string guess;
    getNumber(&guess, "your guess");
    deleteLastOutput;

    if (guess.length() != 4) {
        cout << "Number is not 4-digit" << endl;
        return game(a, answer);
    }

    int cows = 0, bulls = 0;

    for (int i = 0; i < 4; i++) {
        if (answer[i] == guess[i]) cows++;
        else {
            for (int j = 0; j < 4; j++) {
                if (answer[i] == guess[j]) {
                    bulls++;
                }
            }
        }
    }

    if (a > 0) {
        deleteLastOutput;
        deleteLastOutput;
    }
    cout << "Bulls: " << bulls << endl
        << "Cows: " << cows << endl;
    a++;
    if (answer != guess) return game(a, answer);
    return a;
}

void t1() {
    srand(time(nullptr));
    const string answer = to_string(rand() % 9000 + 1000);
    //cout << answer << endl;
    int tries = game(0, answer);
    if (tries == -1) return;
    cout << "You won in " << tries << " turns!";
}