#include <iostream>
#include <iomanip>
#include <map>
#include <string>
#include <cmath>

using namespace std;

void t1() {
    /*Пользователь вводит с клавиатуры расстояние до аэропорта Шереметьево (км) и время (мин) до рейса.
    Написать программу, вычисляющую среднюю скорость (в км/ч), с которой пользователю необходимо ехать,
    чтобы успеть в аэропорт вовремя.*/
    float S, t;
    cout << "Enter distance to airport (km) & time until departure (min) >> ";
    cin >> S >> t;
    cout << "Minimal average speed to catch a flight << " << S / (t / 60) << " km/h";
}

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

void t2() {
    /*Пользователь вводит с клавиатуры шесть целых значений,
    соответствующих времени начала и времени завершения использования самоката (часы, минуты и секунды).
    Написать программу, вычисляющую стоимость всей поездки на самокате, если стоимость одной минуты 5 руб. 50 коп.*/
    Time start, ending;
    cout << "== Enter starting ==" << endl
        << "Hour >> ";
    cin >> start.hours;
    cout << "minute >> ";
    cin >> start.minutes;
    cout << "second >> ";
    cin >> start.seconds;
    cout << "== Enter ending ==" << endl
        << "Hour >> ";
    cin >> ending.hours;
    cout << "minute >> ";
    cin >> ending.minutes;
    cout << "second >> ";
    cin >> ending.seconds;
    start.convertEverythingToSeconds();
    ending.convertEverythingToSeconds();
    if (start.seconds > ending.seconds) {
        cout << "Something is sketchy over there :sus:";
        return;
    }
    int Total = (float)(ending.seconds - start.seconds) * 550 / 60;
    cout << "Session cost << " << Total / 100 << " rub. " << Total % 100 << " dimes.";
}

class Table {
public:
    int l = 16;
    int elements = 2;
    float shifting = 0.5;
    void openLayer() {
        cout << char(201);
        createLine(203);
        cout << char(187) << endl;
    }

    void middleLayer() {
        cout << char(204);
        createLine(206);
        cout << char(185) << endl;
    }

    void closeLayer() {
        cout << char(200);
        createLine(202);
        cout << char(188) << endl;
    }

    void layer(string array[]) {
        cout << char(186) << setw(l / elements) << array[0] + "  " << char(186);
        for (int i = 1; i < elements - 1; i++) {
            cout << setw(l / elements) << array[i] + "  " << char(186);
        }
        cout << setw(l / elements) << array[elements - 1] + "  " << char(186) << endl;
        middleLayer();
    }

private:
    void basicallyLine(int shiftedL) {
        for (int i = 0; i < shiftedL; i++) {
            cout << char(205);
        }
    }
    void createLine(char mid) {
        for (int i = 0; i < elements - 1; i++) {
            basicallyLine(l / elements);
            cout << char(mid);
        }
        basicallyLine(l / elements);
    };
};

void getChars() {
    for (int i = 0; i < 256; i++) {
        cout << i << ". " << char(i) << endl;
    }
}

void t3() {
    /*Пользователь вводит с клавиатуры расстояние по маршруту навигатора, расход бензина автомобилем (на 100 км)
    и стоимость трех видов бензина ближайшей АЗС. Написать программу, которая выводит в
    консоль сравнительную таблицу со стоимостью поездки на разных видах бензина.*/
    float distance, gasUsage;

    map<string, float> gasMap; // Could just use array or whatever it called bruh

    cout << "Enter total distance (in km) >> ";
    cin >> distance;
    cout << "Enter gas usage (per 100km) >> ";
    cin >> gasUsage;
    for (int i = 1; i <= 3; i++) {
        float price;
        cout << "Enter " << "Gas #" << i << " price >> ";
        cin >> price;
        gasMap["Gas #" + to_string(i)] = price * distance * (gasUsage / 100);
    }

    Table border;
    border.shifting = 0.4;
    border.l = 28;
    border.openLayer();
    string header[] = { "Gas type", "Price" };
    border.layer(header);
    map<string, float>::iterator it = gasMap.begin();
    while (it != gasMap.end()) {
        string content[] = { it->first, to_string(it->second) };
        border.layer(content);
        ++it;
    }
    border.closeLayer();
}

void t4() {
    /*Выпишите в консоль таблицу со всеми основными типами данных,
    изученными на занятиях. Таблица должна содержать следующие поля:
    имя типа, описание типа, размер типа в байтах и диапазон возможных значений.
    Дополните таблицу с помощью беззнаковых типов данных.*/
    Table border;
    border.elements = 6;
    border.l = 20 * border.elements;

    cout << "The information may vary depending on the operating system and processor bitness." << endl;

    string typeArr[][6] = {
        { "Name",           "Description",          "Size (bytes)", "Signed range min", "Signed range max", "Unsigned range"},
        { "char",           "One character",        "1",            "-128",             "127",              "0 -> 255" },
        { "short int",      "Integer number",       "2",            "-32'768",          "32'767",           "0 -> 65535" },
        { "int",            "Integer number",       "4",            "-2'147'483'648",   "2'147'483'647",    "0 -> 4'294'967'295" },
        { "long int",       "Integer number",       "8",            "-2^63",            "2^63 - 1",         "0 -> 2^64 - 1" },
        { "Name",           "Description",          "Size (bytes)", "Range",            "---------------",  "---------------"},
        { "float",          "Floating point num",   "4",            "+/- 3.4E +/- 38",  "---------------",  "---------------"},
        { "double",         "Floating point num",   "8",            "+/- 1.7E +/- 308", "---------------",  "---------------"},
        { "bool",           "Boolean logic",        "1",            "true, false",      "---------------",  "---------------"},
    };

    border.openLayer();
    for (int i = 0; i < 9; i++) {
        border.layer(typeArr[i]);
    }
    border.closeLayer();
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
        default:
            exit(0);
            break;
        }
        cout << "\n\n";
    }
    return 0;
}