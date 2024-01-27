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
        task = { R"delimeter(Ќаписать программу, реализующую процедуры заказа и расчета его суммы в мини - пиццерии.¬ меню пиццерии предусмотрено 4 вида пиццы и три вида напитков.
ѕользователю выводитс€ меню (вначале пиццы, потом напитки), содержащее код и название. ѕользователь вводит код желаемого продукта, после чего вводит количество единиц данного продукта. ¬ пиццерии предусмотрены два вида скидок:
    Х если обща€ сумма заказа более 50$, то размер скидки составл€ет 20% от суммы заказа;
    Х кажда€ п€та€ пицца Ч в подарок;
    Х дл€ напитков с ценой более 2$, если количество в заказе более трех, то скидка 15% (только на напитки, а не на весь заказ).
¬ывести пользователю Ђчекї дл€ оплаты в виде:
Ќазвание1 Ч количество1 Ч цена1
Ќазвание2 Ч количество2 Ч цена2
...
ЌазваниеN Ч количествоN Ч ценаN
»того к оплате: $XXX.
¬место XXX Ц должна быть стоимость всего заказа.)delimeter" };
        break;
    case 2:
        task = { R"delimeter(Ќеобходимо написать программу, рассчитывающую зарплату трех менеджеров. Ѕазова€ ставка менеджера составл€ет 60.000 руб. + процент от продаж, рассчитываемый следующим образом:
    Х продажи до 300.000 руб. Ч 3%,
    Х от 300.000 до 700.000 руб. Ч 5%,
    Х свыше 700.000 Ц 8%.
ѕо окончании расчета всех зарплат необходимо определить наиболее ценного сотрудника (выполнившего больше всех продаж) и выдать ему премию в размере двух базовых ставок.
ѕримечание: уровень продаж у всех трех менеджеров разный.)delimeter" };
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
    ¬сЄ в этом мире либо картошка... либо не картошка

    ¬ моем случае все либо пицца, либо не пицца
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