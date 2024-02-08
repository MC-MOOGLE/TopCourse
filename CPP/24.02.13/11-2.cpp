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
#define nl cout << endl;
#define tab cout << "\t";
#define GET_VARIABLE_NAME(Variable) (#Variable)
#define deleteLastOutput cout << "\x1b[A" << "\x1b[2K";

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

using namespace std;

template<typename T>
T getNumber(const char* what = "number") {
    T a;
    cout << "Enter " << what << " >> ";
    cin >> a;
    return a;
}

void printTask(int n) {
    RU;
    Color(3);
    string task;
    switch (n)
    {
    case 1:
        task = { R"delimeter(Реализовать программу расчета заказа в кафетерии при условии,
что заказ может быть сформирован на несколько человек
и каждый клиент формирует свою часть заказа.)delimeter" };
        break;
    case 2:
        task = { R"delimeter(Есть пустое поле игры «Морской бой»,
необходимо вывести в консоль номера полей игры в виде аналогичного квадрата.)delimeter" };
        break;
    default:
        break;
    }
    cout << task << endl;
    Color(7);
    EN;
};

void print(string str, int repeats, string end = "") {
    for (int r = repeats; r > 0; r--) {
        cout << str;
    }
    cout << end;
}

class Menu {
public:
    double price = 0;
    string Name = "";

    map<int, unsigned int> orders;

    void addPosition(int Guest, int Amount) {
        orders[Guest] = Amount;
    }

    Menu(string N = "", double tmpPrice = 0) {
        price = tmpPrice;
        Name = N;
    };
};

bool isExist(Menu b[], int i) {
    try
    {
        Menu a = b[i];
    }
    catch (const std::exception&)
    {
        return false;
    }
    return true;
}

void t1() {

    const int positionsN = 4;

    Menu a("Hamburger", 250);
    Menu b("Pizza", 370);
    Menu c("Soda", 75);
    Menu d("Water", 30);

    Menu AllPositions[] = {a, b, c, d};

    unsigned int Guests = getNumber<int>("amount of guests");

    cout << endl << "== Menu ==" << endl;
    for (int j = 0; j < positionsN; j++) {
        Menu pos = AllPositions[j];
        cout << j << ". " << pos.Name << " -> " << pos.price << endl;
    }
    Color(4);
    cout << "To go to next guest, enter any number not in menu!" << endl;
    Color(7);

    nl;
    for (int i = 1; i <= Guests; i++) {
        bool swtch = true;
        while (swtch) {
            unsigned int amount, tmp;
            cout << "Guest " << i << " select position >> ";
            cin >> tmp;
            if (tmp >= 0 && tmp < positionsN) {
                cout << "Guest " << i << " select amount >> ";
                cin >> amount;
                AllPositions[tmp].addPosition(i, amount);
                deleteLastOutput;
                deleteLastOutput;
            }
            else
            {
                deleteLastOutput;
                break;
            }
        }
    }

    double total = 0;
    cout << "Total!" << endl;
    for (int i = 1; i <= Guests; i++) {
        double guestTotal = 0;
        cout << "==============" << endl
            <<  "Guest " << i << ":" << endl;
        for (int j = 0; j < positionsN; j++) {
            Menu pos = AllPositions[j];
            float subtotal = pos.orders[i] * pos.price;
            cout << "Name    |   " << pos.Name << endl
                <<  "Price   |   " << pos.price << endl
                <<  "Amount  |   " << pos.orders[i] << endl
                <<  "Subtotal|   " << subtotal << "\n\n";
            total += subtotal;
            guestTotal += subtotal;
        }

        cout << "Guest total << " << guestTotal << endl;
    }

    cout << "Total << " << total;
}

void t2() {
    tab;
    cout << "   ";
    for (int i = 0; i < 10; i++) {
        cout << char(i + 97) << "     ";
    }
    print("\n", 2);
    for (int i = 0; i < 10; i++) {
        tab;
        print("######", 10);
        cout << "#";
        nl;
        for (int j = 0; j < 3; j++) {
            if (j == 1) cout << "  " << i;
            tab;
            print("#     ", 10);
            cout << "#";
            nl;
        }
    }
    tab;
    print("######", 10);
    cout << "#";
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