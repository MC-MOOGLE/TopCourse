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
        task = { R"delimeter(�������� ���������, ����������� ��������� ������ � ������� ��� ����� � ���� - ��������.� ���� �������� ������������� 4 ���� ����� � ��� ���� ��������.
������������ ��������� ���� (������� �����, ����� �������), ���������� ��� � ��������. ������������ ������ ��� ��������� ��������, ����� ���� ������ ���������� ������ ������� ��������. � �������� ������������� ��� ���� ������:
    � ���� ����� ����� ������ ����� 50$, �� ������ ������ ���������� 20% �� ����� ������;
    � ������ ����� ����� � � �������;
    � ��� �������� � ����� ����� 2$, ���� ���������� � ������ ����� ����, �� ������ 15% (������ �� �������, � �� �� ���� �����).
������� ������������ ���� ��� ������ � ����:
��������1 � ����������1 � ����1
��������2 � ����������2 � ����2
...
��������N � ����������N � ����N
����� � ������: $XXX.
������ XXX � ������ ���� ��������� ����� ������.)delimeter" };
        break;
    case 2:
        task = { R"delimeter(���������� �������� ���������, �������������� �������� ���� ����������. ������� ������ ��������� ���������� 60.000 ���. + ������� �� ������, �������������� ��������� �������:
    � ������� �� 300.000 ���. � 3%,
    � �� 300.000 �� 700.000 ���. � 5%,
    � ����� 700.000 � 8%.
�� ��������� ������� ���� ������� ���������� ���������� �������� ������� ���������� (������������ ������ ���� ������) � ������ ��� ������ � ������� ���� ������� ������.
����������: ������� ������ � ���� ���� ���������� ������.)delimeter" };
        break;
    default:
        break;
    }
    cout << task << endl;
    Color(7);
    EN;
};

class Food {
public:
    bool Pizza;
    string Name;
    string Code;
    double Price;
    int Amount = 0;
    double total = 0;
    Food(bool v = false, string x = "Not found", string y = "", double z = 0) {
        Pizza = v;
        Name = x;
        Code = y;
        Price = z;
    };
};

void t1() {
    /*
    �� � ���� ���� ���� ��������... ���� �� ��������

    � ���� ������ ��� ���� �����, ���� �� �����
    */

    Food pizza1(true, "Pepperonni", "P1", 2.50);
    Food pizza2(true, "Margherita", "P2", 1.75);
    Food pizza3(true, "4 cheese ", "P3", 2);
    Food pizza4(true, "Hawaiian ", "P4", 3);

    Food drink1(false, "Cola    ", "D1", 2.5);
    Food drink2(false, "Pepsi   ", "D2", 2.25);
    Food drink3(false, "Water   ", "D3", 0.3);

    Food full[] = { pizza1, pizza2, pizza3, pizza4, drink1, drink2, drink3 };

    Color(2);
    cout << "Name\t\tCode\tPrice" << endl;
    Color(7);
    for (Food c : full) {
        cout << c.Name << "\t" << c.Code << "\t" << c.Price << "$" << endl;
    }

    string pizzaCode, drinkCode;
    int pizzaQ, drinkQ;
    Food pizza, drink;
    cout << "Enter pizza code >> ";
    cin >> pizzaCode;
    cout << "Enter pizza amount >> ";
    cin >> pizzaQ;
    for (Food c : full) {
        if (c.Code == pizzaCode) {
            pizza = c;
            pizza.Amount = pizzaQ;
        }
    }

    cout << "Enter drinks code >> ";
    cin >> drinkCode;
    cout << "Enter drink amount >> ";
    cin >> drinkQ;
    for (Food c : full) {  
        if (c.Code == drinkCode) {
            drink = c;
            drink.Amount = drinkQ;
        }
    }

    pizza.total = pizza.Price * pizza.Amount;
    drink.total = drink.Price * drink.Amount;

    if (pizza.Amount >= 5) {
        pizza.total -= pizza.Price * (pizza.Amount / 5);
    }

    if (drink.Price > 2 && drink.Amount > 3) {
        drink.total *= 0.85;
    }

    double total = pizza.total + drink.total;
    if (total > 50) {
        total *= 0.8;
    }

    cout << "\nTotal:" << endl;
    cout << "Name       " << "Amount    " << "Price " << endl
        << pizza.Name << "\t" << pizza.Amount << "\t" << pizza.total << endl
        << drink.Name << "\t" << drink.Amount << "\t" << drink.total << endl;

    cout << "Total: " << total;
}

class Manager {
public:
    const int baseSalary = 60'000;
    int salary = baseSalary;
    int volume = 0;

    void addSells(int sellVolume) {
        if (sellVolume < 300'000) {
            salary += sellVolume * 0.03;
        }
        else if (sellVolume < 700'000) {
            salary += sellVolume * 0.05;
        }
        else {
            salary += sellVolume * 0.08;
        }
        volume = sellVolume;
    }

    void genSells(int number) {
        cout << "Enter manager #" << number << " sells volume >> ";
        cin >> volume;
        addSells(volume);
    }
};

void t2() {
    Manager manager1, manager2, manager3;
    manager1.genSells(1);
    manager2.genSells(2);
    manager3.genSells(3);

    Manager ManagerList[] = { manager1, manager2, manager3 };

    int bestVolume = 0;

    for (int i = 0; i < 3; i ++) {
        Manager c = ManagerList[i];
        if (c.volume > bestVolume) {
            bestVolume = c.volume;
        }
    }

    for (int i = 0; i < 3; i++) {
        Manager c = ManagerList[i];
        if (c.volume == bestVolume) {
            c.salary += c.baseSalary * 2;
        }
        cout << "Manager #" << i + 1 << " salary << " << c.salary << endl;
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