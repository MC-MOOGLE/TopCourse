#include <iostream>
#include <windows.h>  
#include <map>

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

// least useless oop implementation
class Tasks {
private:
    void aroundTheWorld(unsigned int repeats) {
        for (int i = 0; i < repeats; i++) {
            cout << "Around the world, around the world" << endl;
        };
        cout << "\n";
    };
public:

    void getColors() {
        for (int i = 0; i < 255; i++) {
            SetConsoleTextAttribute(hConsole, i);
            cout << i << ". COLOR" << endl;
        }
    }

    void task1() {
        /*Вывести на экран часть любимого стихотворения или куплет песни,
        с указанием автора или исполнителя (на английском языке).
        Используйте escape-последовательности для форматирования.*/
        aroundTheWorld(8);
        aroundTheWorld(16);
        aroundTheWorld(28);
        aroundTheWorld(20);
        cout << "\nDaft Punk - Around the World";
    }

    void task2() {
        /*Вывести на экран стих «Every hunter wants…» таким образом,
        чтобы каждый «цвет» начинался с новой строки и соответствующим количеством табуляций.
        Не забывайте использовать escape-последовательности для форматирования.*/
        cout << "I replaced Russian version with english one. Hope you dont mind." << endl;
        // Richard Of York Gave Battle In Vain Red Orange Yellow Green Blue Indigo Violet.17 сент. 2011 г.
        SetConsoleTextAttribute(hConsole, 4);
        cout << "Red\t- Richard" << endl;
        SetConsoleTextAttribute(hConsole, 6);
        cout << "Orange\t- Of" << endl;
        SetConsoleTextAttribute(hConsole, 14);
        cout << "Yellow\t- York" << endl;
        SetConsoleTextAttribute(hConsole, 10);
        cout << "Green\t- Gave" << endl;
        SetConsoleTextAttribute(hConsole, 11);
        cout << "Blue\t- Battle" << endl;
        SetConsoleTextAttribute(hConsole, 1);
        cout << "Indigo\t- In" << endl;
        SetConsoleTextAttribute(hConsole, 5);
        cout << "Violet\t- Vain" << endl;
        SetConsoleTextAttribute(hConsole, 7);
    }

    void task3() {
        /*Напишите объявление о продаже чего-нибудь (на английском языке) и выведите его на экран,
        в том виде как оно должно было бы быть напечатано. Например:*/
        cout << "Selling Nvidia's GPUs" << endl
            << "status: new" << endl;
        map < string, int> gpuMap;
        gpuMap["RTX 3090"] =  1000 ;
        gpuMap["RTX 3080"] =  750 ;
        gpuMap["RTX 3070"] =  650 ;
        gpuMap["RTX 3060"] =  350 ;

        for (auto const& pos : gpuMap) {
            std::cout << "GPU: " << pos.first << "\t| Price: " << pos.second << "\t| Quanity: " << rand() % 100 << '\n';
        }
    }

    void completeTask(int task) {
        switch (task)
        {
        case (1):
            task1();
            break;
        case (2):
            task2();
            break;
        case (3):
            task3();
            break;
        default:
            exit(-1);
            break;
        }
    };
};

int main()
{
    Tasks tmp;
    unsigned short int inp;
    while (true) {
        cout << "Enter task, to exit enter 0 >> ";
        cin >> inp;
        tmp.completeTask(inp);
        cout << "\n\n\n";
    }
}