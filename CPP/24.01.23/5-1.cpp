#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;

class Time
{
public:
    int sec = 0, min = 0, hours = 0, days = 0;

    void convertEverythingToSeconds() {
        sec += days * 86400;
        days = 0;
        sec += hours * 3600;
        hours = 0;
        sec += min * 60;
        min = 0;
    }
};

class displayTime : public Time
{
public:
    int Fsec = 0, Fmin = 0, Fhours = 0, Fdays = 0;

    void timeHMS() {
        int tmpSec = sec;
        toHMS(tmpSec);
    }

    void timeBeforeMidnightHMS() {
        int tmpSec = sec;
        tmpSec %= dayL;
        tmpSec = dayL - tmpSec;
        toHMS(tmpSec);
    }

private:

    const int dayL = 86400, hourL = 3600, minL = 60;
    void toHMS(int tmpSec) {
        if (tmpSec < 0) {
            tmpSec = dayL + (tmpSec % dayL);
        }
        Fdays = tmpSec / dayL;
        Fhours = tmpSec % dayL / hourL;
        Fmin = tmpSec % dayL % hourL / minL;
        Fsec = tmpSec % dayL % hourL % minL;

        cout << Fhours << " : " << setw(2) << setfill('0') << Fmin << " : " << setw(2) << setfill('0') << Fsec;
    }
};

void t1() {
    /*Пользователь вводит с клавиатуры время в секундах, прошедшее с начала дня.
Необходимо выполнить перевод введенных пользователем секунд в часы, минуты
и секунды. Вывести полученное время на экран. Посчитать количество часов,
минут и секунд, оставшееся до полуночи.*/

    displayTime clock;
    cout << "Enter seconds passed today >> ";
    cin >> clock.sec;
    cout << "Time passed -> ";
    clock.timeHMS();
    cout << endl;
    cout << "Time before midnight -> ";
    clock.timeBeforeMidnightHMS();
}

void t2() {
    /*Пользователь вводит с клавиатуры время в секундах, прошедшее с начала
рабочего дня. Необходимо посчитать, сколько целых часов осталось ему
работать, если рабочий день длится 9 часов. */

    Time passed;
    Time dayEnd;
    cout << "Enter seconds passed since job start >> ";
    cin >> passed.sec;
    dayEnd.hours = 9;
    dayEnd.convertEverythingToSeconds();
    if (passed.sec > dayEnd.sec) {
        cout << "You are owerworking! Chill, bro";
    }
    else if (passed.sec == dayEnd.sec) {
        cout << "Working day ended, Yay!";
    }
    else if (passed.sec < 0) {
        cout << "Are you in working depth? Is this even legal?";
    }
    else {
        cout << "Remaining full hours << " << (dayEnd.sec - passed.sec) / 3600;
    }
}

int main() {
    int task;
    while (true) {
        cout << "Enter task (0 to exit) >> ";
        cin >> task;
        switch (task) {
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