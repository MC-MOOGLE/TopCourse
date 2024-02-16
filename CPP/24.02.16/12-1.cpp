// Используются для базового функционала
#include <iostream>
#include <string>
#include <Windows.h>
#include <stdio.h>
#include <vector>
// Используются в заданиях
#include <chrono>
#include <thread>
#include <cmath>

// Используются для базового функционала
#define RU setlocale(LC_ALL, "ru-RU");
#define EN setlocale(LC_ALL, "en-EN");
#define Color(n) SetConsoleTextAttribute(console, n);

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

using namespace std;

// Используются в заданиях
#define sleep(n) this_thread::sleep_for(chrono::milliseconds(n));
#define deleteLastOutput cout << "\x1b[A" << "\x1b[2K";
#define M_PI 3.14159265358979323846

template<typename T>
T getNumber(const char* what = "number") {
    T a;
    cout << "Enter " << what << " >> ";
    cin >> a;
    return a;
}

void print(string str, int repeats, string end = "") {
    for (;repeats > 0;repeats--)
    {
        cout << str;
    }
    cout << end;
}

string tasksText[] = {
    /*1*/ "Написать программу, которая выводит на экран линию заданным символом, вертикальную или горизонтальную, причем линия может выводиться быстро, нормально и медленно. Общение с пользователем организовать через меню.",
    /*2*/ "Написать игру «Кубики». Пользователь и компьютер по очереди бросают 2 кубика. Победитель — тот, у кого по результатам трех бросков сумма больше. Предусмотреть красивый интерфейс игры.",
};

void printTask(unsigned short int n) {
    const unsigned short int lineLen = 60;
    RU;
    Color(3);
    if (tasksText->size() > n) {
        int i = 0;
        int lineChar = 0;
        string task = tasksText[n - 1];
        for (char c : task) {
            i++;
            if (lineChar > lineLen && c == ' ') {
                task.insert(i, "\n");
                lineChar = 0;
            }
            lineChar++;
        }
        cout << task << endl;
    }
    Color(7);
    EN;
    return;
};

// Может вынесу всю эту каракатицу в отдельный файл

void t1() {
    RU;
    Color(2);
    cout << "Меня это задание натолкнуло на идею, и для нее я убил пол дня на рисование фигурок в десмосе :skull: :thumb_up:" << endl;
    Color(7);
    EN;
    const int resolution = 25;
    const double ratio = 29 / 14; // Я сделал скриншот и посчитал пиксели по обеим осям
    char sym = getNumber<char>("character");
    double angle = getNumber<int>("orientation");
    double speed = getNumber<double>("character displaying speed (in ms)");
    char figure = getNumber<char>("figure (a. Circle, b. Diagonal split screen, c. Diagonal chessboard, d. wave (cos), e. line, f. paraballa)");

    angle = angle * M_PI / 180;

    for (int y = -resolution; y < resolution; y++) {
        for (int x = -resolution; x < resolution; x++) {

            double _x;
            double _y;

            _x = x * cos(angle) - y * sin(angle);
            _y = x * sin(angle) + y * cos(angle);

            bool isOn = false;

            switch (figure)
            {
            case 'a': // Круг
                isOn = _x * _x + _y * _y <= resolution * resolution;
                break;
            case 'b': // Диагональная линия
                isOn = _x > _y;
                break;
            case 'c': // Волна (Косинусоида)
                isOn = cos(_x) * resolution >= cos(_y) * resolution;
                break;
            case 'd': // idk lol
                isOn = cos(_x) - 1 <= _y / 2 && cos(_x) + 1 >= _y / 2;
                break;
            case 'e': // line
                isOn = int(_x) == 0;
                break;
            case 'f': // paraballa
                isOn = int(_x * _x * 0.1) >= _y;
                break;
            default:
                break;
            }

            if (isOn) { 
                cout << sym << " ";
                sleep(int(speed));
            }
            else {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

template<typename T>
constexpr auto rCube(T cubes) { return rand() % (6 * cubes);; }

void t2() {
    const short int moves = 3;
    const short int cubes = 2;
    int player[moves], computer[moves];

    for (int i = 0; i < moves; i++) {
        cout << "Round #" << i + 1 << " (" << i << "/" << moves << ")" << endl;

        cout << "Your turn >> \n";
        system("pause");
        deleteLastOutput;
        player[i] = rCube(cubes);
        cout << "You rolled " << player[i] << endl;
        cout << "Computer's turn!" << endl;
        sleep(1000);
        computer[i] = rCube(cubes);
        cout << "Computer rolled " << computer[i] << endl;
    }

    auto sum = [moves](int arr[]) {
        int sum = 0;
        for (int i = 0; i < moves; i++) {
            int a = arr[i];
            sum += a;
        }
        return sum;
        };

    int playerSum = sum(player);
    int computerSum = sum(computer);



    cout << "And the winner is/are...\n";
    string msg;
    sleep(2000);
    if (playerSum == computerSum) {
        msg = "Its a tie";
    }
    else if (playerSum > computerSum) {
        msg = "You";
    }
    else
    {
        msg = "Computer";
    }
    cout << msg << "!\n\nScore: " << playerSum << " (Player) / " << computerSum << " (Computer)";
}

typedef void (*voidFuncton) ();
vector<voidFuncton> tasks = {t1, t2};

int main() {
    unsigned short int task;
    while (true) {
        cout << "Enter task from " << 1 << " to " << tasks.size() << " (0 to exit) >> ";
        cin >> task;
        if (tasks.size() >= task) {
            printTask(task);
            tasks[task - 1]();
        }
        else {
            exit(0);
        }
        cout << "\n\n";
    }
    return 0;
}