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

void printTask(int n) {
    RU;
    Color(3);
    string task;
    switch (n)
    {
    case 1:
        task = { R"delimeter(Пользователь вводит с клавиатуры символ. Определить, какой это символ: Буква,
цифра, знак препинания или другое.)delimeter" };
        break;
    case 2:
        task = { R"delimeter(Написать программу подсчета стоимости разговора для разных мобильных операторов.
Пользователь вводит длительность разговора и выбирает с какого на какой оператор он звонит.
Вывести стоимость на экран.)delimeter" };
        break;
    case 3:
        task = { R"delimeter(Вася работает программистом и получает 5000 руб.
за каждые 100 строк кода. За каждое третье опоздание на работу Васю штрафуют на 2000 руб.
Написать программу, в которой по выбору пользователя будет выводится следующая информация:

сколько строк кода Васе надо написать, если пользователь вводит желаемый доход Васи и количество опозданий;

сколько раз Вася может опоздать, если пользователь вводит количество строк кода, написанное Васей и желаемый объем зарплаты;

сколько денег заплатят Васе и заплатят ли вообще, если пользователь вводит количество строк кода и количество опозданий.)delimeter" };
        break;
    default:
        break;
    }
    cout << task << endl;
    Color(7);
    EN;
};

void t1() {
    char c;
    string msg = "";
    cout << "Enter character >> ";
    cin >> c;
    cout << "Char #" << (int)(c) << endl;
    int punctuations[] = { ',', '!', '.', '?', ':', ';' };
    int* tmpPointer = find(begin(punctuations), end(punctuations), c);
    if (tmpPointer != end(punctuations)) {
        cout << "Punctuation mark";
        return;
    }
    if (c < 48) {
        msg = "Special/other";
    }
    else if (c < 58) {
        msg = "Number";
    }
    else if (c < 65) {
        msg = "Number";
    }
    else if (c < 91) {
        msg = "Letter";
    }
    else if (c < 97) {
        msg = "Special/other";
    }
    else if (c < 123) {
        msg = "Letter";
    }
    else {
        msg = "Special/other";
    }
    cout << msg;
}

void t2() {
    string a;
    cout << "In the perfect future, perfect goverment issued a law\nstating that all calls should be free." << endl
        << "Prices: " << endl
        << "Beeline > 0$/m" << endl
        << "Tele2 > 0$/m" << endl
        << "Tinkoff > 0$/m" << endl
        << "Megafon > 0$/m" << endl
        << "Please read the prices carefully!" << endl
        << "Enter call time >> ";
    cin >> a;
    cout << "Fees:" << endl
        << "1. Beeline > Megafon:  50%" << endl
        << "2. Tele2   > Megafon:  100%" << endl
        << "3. Tinkoff > Megafon:  1000%" << endl
        << "4. Beeline > Tele2:    100000%" << endl
        << "5. Beeline > Tinkoff:  42069%" << endl
        << "6. Tinkoff > Tele2:    -50%" << endl;
    cout << "Select your option >> ";
    cin >> a;
    // Complicated math
    int price = 0 * 0;
    cout << "Call cost << " << price << "$";
}

int input(string name) {
    int variable;
    cout << "Enter " << name << " >> ";
    cin >> variable;
    return variable;
};

void t3() {
    const int salaryAmount = 5000, salaryRate = 100, penalty = 2000;
    double salaryPerLine = salaryAmount / salaryRate;

    cout << "Select displayed info: " << endl
        << "1. in: salary, lates for work; out: code lines" << endl
        << "2. in: code lines, salary; out: lates for work" << endl
        << "3. in: code lines, lates for work; our: salary" << endl;

    int choice = input("your choice");

    int salary, lateForWorks, codeLines;

    switch (choice)
    {
    case 1:
        salary = input("salary");
        lateForWorks = input("lates for work");

        if (salary + lateForWorks * penalty < 0) {
            cout << "Loop is, in fact, insanity";
            return;
        }

        codeLines = double(salary + lateForWorks * penalty) / salaryPerLine;

        if (codeLines < 0) {
            cout << "Something is wrong, i can feel it";
            return;
        }
        cout << "Code lines << " << codeLines;
        break;
    case 2:
        codeLines = input("code lines");
        salary = input("salary");

        if (double(codeLines * salaryPerLine) - salary < 0) {
            cout << "Dream more, deptor";
            return;
        }
        lateForWorks = (double(codeLines * salaryPerLine) - salary) / penalty;
        cout << "Lates for work << " << lateForWorks;
        break;
    case 3:
        lateForWorks = input("lates for work");
        codeLines = input("code lines");

        salary = codeLines * salaryPerLine - lateForWorks * penalty;
        if (salary < 0) {
            cout << "You are " << salary << "$ in dept, Vasil";
            return;
        }
        cout << "Salary << " << salary;
        break;
    default:
        break;
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
        case (3):
            t3();
            break;
        default:
            exit(0);
            break;
        }
        cout << "\n\n";
    }
    return 0;
}