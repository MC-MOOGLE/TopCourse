// Используются для базового функционала
#include <iostream>
#include <string>
#include <Windows.h>
#include <stdio.h>
#include <vector>
// Используются в заданиях
#include <chrono>
#include <thread>

// Используются для базового функционала
#define RU setlocale(LC_ALL, "ru-RU");
#define EN setlocale(LC_ALL, "en-EN");
#define Color(n) SetConsoleTextAttribute(console, n);

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

using namespace std;

// Используются в заданиях
#define sleep(n) this_thread::sleep_for(chrono::milliseconds(n));
#define deleteLastOutput cout << "\x1b[A" << "\x1b[2K";

template<typename T>
T getNumber(const char* what = "number") {
    T a;
    cout << "Enter " << what << " >> ";
    cin >> a;
    deleteLastOutput;
    return a;
}

void print(string str, int repeats, string end = "") {
    for (; repeats > 0; repeats--)
    {
        cout << str;
    }
    cout << end;
}

string tasksText[] = {
    /*1*/ R"delimeter(Написать игру «GUESS MY NUMBER». Пользователь угадывает число, которое 
«загадал» компьютер. Возможны 2 уровня сложности: на первом уровне число от 
1 до 10, на втором от 10 до 100. В начале игры пользователь выбирает уровень.
В начале каждого уровня игроку даются «жизни» — 50% от длины диапазона 
угадывания на первом уровне и 25% — на втором (пример приведен ниже). За 
каждую ошибку игрок штрафуется — минус одна жизнь. Предусмотреть в игре 
возможность подсказки: «загаданное число больше — меньше твоего». Стоимость 
подсказки — одна жизнь (пользователь может принять подсказку в случае ошибки 
или отказаться от нее). Уровень продолжается, пока игрок жив или не угадает 
(состояние игрока «жив» — «убит» отображается рисунком в консоли).
Очки после уровня — количество оставшихся жизней, умноженные на 5 для 
первого уровня и на 10 для второго. Результат игры, количество очков или 
«Проигрыш», вывести в консоль.

Задание 2 *
Модифицировать игру «GUESS MY NUMBER» следующим образом:
пользователь не выбирает уровень, т. к. переход ко второму уровню 
возможен только после завершения первого без проигрыша (если игрок 
желает продолжать);
первый уровень длится три раунда (на каждом раунде загадывается новое 
число), а второй — два раунда. Новые жизни начисляются игроку перед 
новым раундом;
если пользователь проиграл раунд, то компьютеру начисляются очки за 
раунд в размере начальные жизни пользователя, умноженные на 5 для 
первого уровня и на 10 для второго;
количество очков сохраняется и накапливается в раундах и уровнях;
промежуточные итоги выводятся после каждого раунда и уровня.)delimeter",
};

void printTask(unsigned short int n) {
    const unsigned short int lineLen = -1;
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

class Game {
public:
    Game(unsigned int _difficulty = 0) {

        difficulty = _difficulty;

        updateRange();
    };

    bool startRound() {
        srand(time(nullptr));
        coof = (difficulty == 1) ? 0.5 : 0.25;
        lifes = (range[1] - range[0]) * coof;
        int chosenNumber = rand() % (range[1] - range[0] + 1) + range[0];

        cout << "The number is in range " << range[0] << " - " << range[1] << endl;
        for (; lifes >= 0; lifes--) {
            int playerGuess = getNumber<int>();

            if (playerGuess == chosenNumber) {
                Color(2);
                score += 5 * (difficulty / 10 + 1);
                cout << "You're guessed it!" << endl
                    << "Your score << " << score << endl
                    << "Computer score << " << computerScore << endl;
                Color(7);
                return true;
            }
            deleteLastOutput;
            cout << "Wrong! You have " << lifes << " lifes left" << endl;
            if (lifes > 1) {
                cout << "Do you want a hint? Cost = 1 life; 0 - no, other - yes >> ";
                int tmp;
                cin >> tmp;
                deleteLastOutput;
                if (tmp) {
                    deleteLastOutput;
                    lifes--;
                    cout << "The number is ";
                    cout << ((chosenNumber > playerGuess) ? "bigger" : "smaller") << endl;
                }
            }
        }

        Color(4);
        computerScore += ((range[1] - range[0]) * coof + 1) * (difficulty / 10 + 1);
        cout << "Computer won this round!" << endl
            << "Your score << " << score << endl
            << "Computer score << " << computerScore << endl;
        Color(7);
        return false;
    };

    void setDifficulty(int _difficulty) {
        difficulty = _difficulty;
        updateRange();
    };

    bool winner() {
        return (computerScore < score) ? true : false;
    }

private:

    unsigned int difficulty = 0;
    double coof = 0.5;
    unsigned int range[2] = { difficulty,  difficulty * 10 };
    int lifes = range[1] - range[0] * coof;
    int computerScore = 0;
    int score = 0;

    void updateRange() {
        range[0] = difficulty;
        range[1] = difficulty * 10;
    }
};

void t1() {
    Game game(1);

    for (int round = 0; round < 3; round++) {
        cout << "Round " << round + 1 << endl;
        game.startRound();
        sleep(1500);
    }

    Color(2);
    cout << "Level up!" << endl;
    Color(7);
    sleep(1000);

    game.setDifficulty(10);

    for (int round = 0; round < 2; round++) {
        cout << "Round " << round + 1 << endl;
        game.startRound();
        sleep(1500);
    }

    if (game.winner()) {
        Color(2);
        cout << "You won!" << endl;
        Color(7);
        sleep(4000);
    }
    else {
        Color(4);
        cout << "\aYou lose!" << endl;
        Color(7);
        sleep(4000);
    }

    return;
}

typedef void (*voidFuncton) ();
vector<voidFuncton> tasks = { t1 };

int main() {

    unsigned short int task = 1;
    while (true) {
        if (task > 1) {
            cout << "Enter task from " << 1 << " to " << tasks.size() << " (0 to exit) >> ";
            cin >> task;
        }
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