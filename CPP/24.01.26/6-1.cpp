#include <iostream>
#include <string>
#include <Windows.h>
#include <stdio.h>
#include <iomanip>
#include <regex>

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
        task = { R"delimeter(Написать программу, реализующую процедуры заказа и расчета его суммы в мини - пиццерии.В меню пиццерии предусмотрено 4 вида пиццы и три вида напитков.
Пользователю выводится меню (вначале пиццы, потом напитки), содержащее код и название. Пользователь вводит код желаемого продукта, после чего вводит количество единиц данного продукта. В пиццерии предусмотрены два вида скидок:
    • если общая сумма заказа более 50$, то размер скидки составляет 20% от суммы заказа;
    • каждая пятая пицца — в подарок;
    • для напитков с ценой более 2$, если количество в заказе более трех, то скидка 15% (только на напитки, а не на весь заказ).
Вывести пользователю «чек» для оплаты в виде:
Название1 — количество1 — цена1
Название2 — количество2 — цена2
...
НазваниеN — количествоN — ценаN
Итого к оплате: $XXX.
Вместо XXX – должна быть стоимость всего заказа.)delimeter" };
        break;
    case 2:
        task = { R"delimeter(Необходимо написать программу, рассчитывающую зарплату трех менеджеров. Базовая ставка менеджера составляет 60.000 руб. + процент от продаж, рассчитываемый следующим образом:
    • продажи до 300.000 руб. — 3%,
    • от 300.000 до 700.000 руб. — 5%,
    • свыше 700.000 – 8%.
По окончании расчета всех зарплат необходимо определить наиболее ценного сотрудника (выполнившего больше всех продаж) и выдать ему премию в размере двух базовых ставок.
Примечание: уровень продаж у всех трех менеджеров разный.)delimeter" };
        break;
    default:
        break;
    }
    cout << task << endl;
    Color(7);
    EN;
};

class Menu
{
public:
    void showMenu() {
        int i = 0;
        Color(2)
        cout << "Name\t\t" << "Price\t" << "Code\t" << endl;
        Color(7)
        cout << "Pizza : " << endl;
        for (string position : pizza) {
            i++;
            cout << position << tab << i * 75 << tab << "P" << i << endl;
        }
        i = 0;
        cout << "\nDrinks : " << endl;
        for (string position : drinks) {
            i++;
            cout << position << tab << tab << i * 75 << tab << "D" << i << endl;
        }
    }

    void getPosition(string code) {
        regex numberRegex("[0-9]+");

        string letter = regex_replace(code, numberRegex, "");
        int number = exctractNumber(code);

        cout << letter << " " << number << endl;

    }
private:
    string pizza[4] = { "Pepperonni", "4 cheese", "Margherita", "Hawaiian" };
    string drinks[3] = { "Cola", "Pepsi", "Water" };

    int exctractNumber(string str) {
        string tmpNumber;
        for (char c : str) {
            int num;
            try {
                num = stoi(string(1, c));
                tmpNumber += to_string(num);
            }
            catch (invalid_argument&) {}
        }
        return stoi(tmpNumber);
    }
};


void t1() {
    Menu menu;
    menu.showMenu();
    menu.getPosition("A2");
}

void t2() {

}

void t3() {

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