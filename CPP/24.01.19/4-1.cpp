#include <iostream>
#include <iomanip>

using namespace std;

class Time
{
public:
    unsigned long long int seconds = 0;
    unsigned int minutes = 0, hours = 0, days = 0, weeks = 0;

    int convertEverythingToSeconds() {
        seconds += minutes * 60;
        minutes = 0;
        seconds += hours * 3600;
        hours = 0;
        seconds += days * 86'400;
        days = 0;
        seconds += weeks * 604'800;
        weeks = 0;
        return seconds;
    }
};

class formalTime : public Time
{
public:
    void convertSecondsToTime() {
        convertEverythingToSeconds();
        Fweeks = seconds / 604'800;
        Fdays = seconds % 604'800 / 86'400;
        Fhours = seconds % 86'400 / 3600;
        Fminutes = seconds % 3600 / 60;
        Fseconds = seconds % 3600 % 60;
    }

    void displayFormalTimeHMS() {
        cout << Fhours << " : "
            << setw(2) << setfill('0') << Fminutes << " : "
            << setw(2) << setfill('0') << Fseconds << endl;
    }

    void displayFormalTimeWD() {
        cout << Fweeks << " weeks, " << Fdays << " days." << endl;
    }
private:
    unsigned int Fseconds = 0, Fminutes = 0, Fhours = 0, Fdays = 0, Fweeks = 0;
};

void t1() {
    /*Пользователь вводит с клавиатуры время в секундах.
    Необходимо написать программу, которая переведет введенные
    пользователем секунды в часы, минуты, секунды и выводит их в консоль.*/
    formalTime clock;
    cout << "Seconds >> ";
    cin >> clock.seconds;
    clock.convertSecondsToTime();
    clock.displayFormalTimeHMS();
}

class Money
{
public:
    double totalMoney;
    int rubles, dimes;

    void convertMoney() {
        rubles = int(totalMoney);
        dimes = (int)(totalMoney * 100) % 100;
    }
};

void t2() {
    /*Написать программу, которая преобразует введенное с клавиатуры вещественное число в денежный формат.*/
    Money userMoney;
    cout << "User's money: ";
    cin >> userMoney.totalMoney;
    userMoney.convertMoney();
    cout << "Converted: " << userMoney.rubles << " rub. " << userMoney.dimes << " dimes";
}

void t3() {
    /*Написать программу, которая преобразует введенное пользователем
    количество дней в количество полных недель и оставшихся дней.*/
    formalTime clock;
    cout << "Days >> ";
    cin >> clock.days;
    clock.convertSecondsToTime();
    clock.displayFormalTimeWD();
}

void t4() {
    /*Написать программу, вычисляющую, с какой средней скоростью бегун пробежал дистанцию.
    Пользователем вводится дистанция в метрах, и время, за которое он ее преодолел.*/
    // no oop :sob:
    float meters, seconds, angVel;
    cout << "Meters & seconds >> ";
    cin >> meters >> seconds;
    cout << "Average velocity << " << meters / seconds << " m/s";
}

void t5() {
    /*Пользователь сумму денежного вклада в рублях, а также процент годовых,
    которые выплачивает банк. Программа должна определять сумму денег,
    выплачиваемую банком вкладчику каждый месяц.*/
    unsigned int rub;
    float percent;
    cout << "Investment amount & percent/year >> ";
    cin >> rub >> percent;
    cout << "Monthly income << " << rub * (percent / 100 / 12) << endl
        << "(" << rub * (percent / 100) << " yearly income)";
}

int main()
{
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
        case (3):
            t3();
            break;
        case (4):
            t4();
            break;
        case (5):
            t5();
            break;
        default:
            exit(0);
            break;
        }
        cout << "\n\n";
    }
    return 0;
}