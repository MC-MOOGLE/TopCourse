#include <iostream>
#include <string>
#include <Windows.h>
#include <stdio.h>

#define RU setlocale(LC_ALL, "ru-RU");
#define EN setlocale(LC_ALL, "en-EN");
#define Color(n) SetConsoleTextAttribute(console, n);

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

using namespace std;

void printTask(int n) {
    RU;
    Color(3);
    string task;
    switch (n)
    {
    case 1:
        task = { R"delimeter(Вывести на экран фигуры, заполненные звездочками. Реализовать диалог с 
пользователем при помощи пользовательского меню.)delimeter" };
        break;
    default:
        break;
    }
    cout << task << endl;
    Color(7);
    EN;
};

void print(string str, int repeats, string end = "\n") {
    while (repeats > 0)
    {
        cout << str;
        repeats--;
    }
    cout << end;
}

void t1() {
    char id;
    int size;
    cout << "Enter figure id (0 to exit) >> ";
    cin >> id;
    cout << "Enter figure side >> ";
    cin >> size;

    switch (id)
    {
    case 'a':
        for (int layer = 0; layer < size; layer++) {
            print("  ", layer, ""); // its so cursed to see print() in cpp
            print("* ", (size - layer));
        }
        break;
    case 'b':
        for (int layer = 0; layer < size; layer++) {
            print("* ", layer + 1);
        }
        break;
    case 'c':
        for (int layer = 0; layer < size; layer++) {
            print("  ", layer, "");
            print("* ", size - (layer * 2));
        }
        break;
    case 'd':
        for (int layer = 0; layer < size / 2; layer++) {
            cout << endl;
        }
        for (int layer = size / 2; layer >= 0; layer--) {
            print("  ", layer, "");
            print("* ", size - (layer * 2));
        }
        break;
    case 'e':
        for (int layer = 0; layer < size / 2; layer++) {
            print("  ", layer, "");
            print("* ", size - (layer * 2));
        }
        if (size % 2) {
            print("  ", size / 2, "");
            cout << "*" << endl;
        }
        for (int layer = size / 2 - 1; layer >= 0; layer--) {
            print("  ", layer, "");
            print("* ", size - (layer * 2));
        }
        break;
    case 'f':
        for (int layer = 0; layer <= size / 2; layer++) {
            print("* ", layer, "");
            print("  ", size - (layer * 2), "");
            print("* ", layer);
        }
        if (size % 2) {
            print("* ", size);
        }
        for (int layer = size / 2; layer >= 0; layer--) {
            print("* ", layer, "");
            print("  ", size - (layer * 2), "");
            print("* ", layer);
        }
        break;
    case 'g':
        for (int layer = 0; layer <= size / 2; layer++) {
            print("* ", layer, "");
            print("  ", size - (layer * 2));
        }
        if (size % 2) {
            print("* ", size / 2 + 1);
        }
        for (int layer = size / 2; layer >= 0; layer--) {
            print("* ", layer, "");
            print("  ", size - (layer * 2));
        }
        break;
    case 'h':
        for (int layer = 0; layer <= size / 2; layer++) {
            print("  ", size - layer, "");
            print("* ", layer);
        }
        if (size % 2) {
            print("  ", size / 2, "");
            print("* ", size / 2 + 1);
        }
        for (int layer = size / 2; layer >= 0; layer--) {
            print("  ", size - layer, "");
            print("* ", layer);
        }
        break;
    case 'i':
        for (int layer = 0; layer <= size; layer++) {
            print("* ", size - layer);
        }
        break;
    case 'j':
        for (int layer = 0; layer <= size; layer++) {
            print("  ", size - layer, "");
            print("* ", layer);
        }
        break;
    default:
        exit(0);
        break;
    }
}

int main() {
    printTask(1);
    while (true) {
        t1();
        cout << "\n\n";
    }
    return 0;
}