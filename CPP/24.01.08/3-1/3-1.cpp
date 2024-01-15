#include <iostream>
#include <vector>

using namespace std;

class Resistance
{
public:
    Resistance();
    float value;
};

Resistance::Resistance() {
    float num;
    cin >> num;
    value = 1 / num;
}

void t1() {
    // Пользователь вводит три сопротивления: R1, R2, R3. Вычислить значение сопротивления
    cout << "Enter R1, R2 & R3 >> ";
    Resistance R1, R2, R3;
    cout << "1 / R0 = " << R1.value + R2.value + R3.value << endl
        << "R0 = " << 1 / (R1.value + R2.value + R3.value);
}

class Circle
{
public:
    float lenght, radius,area;
    const float pi = 3.14;
    float getRadiusFromLenght() {
        radius = lenght / pi / 2;
        return radius;
    }
    float getAreaFromRadius() {
        area = pi * pow(radius, 2);
        return area;
    }
};

void t2() {
    /*Пользователь задает длину окружности. Найти площадь круга,
    вычислив радиус из формулы длины окружности.*/
    Circle myCircle;
    cout << "Enter circle lenght >> ";
    cin >> myCircle.lenght;
    myCircle.getRadiusFromLenght();
    cout << "Circle area << " << myCircle.getAreaFromRadius();
}

class Movement
{
public:
    // I just relized, that using only one letter is much more intuitive
    float S, v0, v1, t, a;
    float get_t() {
        t = (v1 - v0) / a;
        return t;
    }

    float getS() {
        S = (a * pow(t, 2)) / 2 + v0 * t;
        return S;
    }
};

void t3() {
    /*Пользователь вводит значения ускорения и скорости.
    Вычислить пройденное расстояние при прямолинейном равноускоренном движении*/
    Movement usersPath;
    cout << "Enter acceleration (a) >> ";
    cin >> usersPath.a;
    cout << "Enter starting (v0) and ending (v1) velocity >> ";
    cin >> usersPath.v0 >> usersPath.v1;
    usersPath.get_t();
    cout << "Space (S) = " << usersPath.getS();
}

int main()
{
    int task;
    while (true) {
        cout << "Enter task (0 to exit) >> ";
        cin >> task;
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