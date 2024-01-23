﻿#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;

int getNDigitNumber(int digits) {
    cout << "Enter " << digits << "-digit number >> ";
    int n;
    cin >> n;
    n = abs(n);
    string strN = to_string(n);
    if (strN.length() != digits) {
        cout << "This is not a " << digits << "-digit number";
        return 0;
    };
    return n;
};

void t1() {
	/*Пользователь вводит с клавиатуры целое шестизначное число.
    Написать программу, которая определяет,
    является ли введенное число — счастливым Счастливым считается шестизначное число,
    у которого сумма первых 3 цифр равна сумме вторых трех цифр.
    Если пользователь ввел не шестизначное число необходимо вывести на экран сообщение об ошибке.*/
    int n = getNDigitNumber(6);
    if (!n) {
        return;
    }
    string strN = to_string(n);
    int s1 = 0, s2 = 0;
    for (int i = 0; i < 6; i++) {
        (i < 3) ? s1 += strN[i] - '0' : s2 += strN[i] - '0'; // Genius kludge
    }
    cout << "The number is ";
    (s1 == s2) ? cout << "" : cout << "not ";
    cout << "lucky";
}

void t2() {
    /*Пользователь вводит четырехзначное число.
    Необходимо поменять в этом числе 1 и 2 цифры, а также 3 и 4 цифры
    Если пользователь вводит не четырехзначное число — вывести сообщение об ошибке.*/
    int n = getNDigitNumber(4);
    if (!n) {
        return;
    }
    string strN = to_string(n);
    string finalN = strN;
    finalN[0] = strN[1];
    finalN[1] = strN[0];
    finalN[2] = strN[3];
    finalN[3] = strN[2];
    cout << "Final number << " << finalN;
}

void notAloop(int * nums, int i) {

    /*ChatGPT:
    
    No, recursion is not a loop in programming.
    
    Recursion is a programming technique where a function calls itself repeatedly.
    This allows you to break down a problem into smaller subproblems,
    until you reach a base case where the problem can be solved directly.

    Loops, on the other hand, are used to execute a block of code repeatedly
    until a condition is met. While recursion and loops can both be used to solve
    some of the same problems, they are fundamentally different techniques.*/

    int n;
    cout << "Enter number #" << i << " >> ";
    cin >> n;
    nums[i-1] = n;
    if (i < 7) {
        notAloop(nums, i + 1);
    } else {
        return;
    }
}

void t3() {
    /*Пользователь вводит с клавиатуры 7 целых чисел.
    Необходимо написать программу, которая определяет максимальное значение из введенных.
    Использовать 7 переменных для каждого значения запрещено! Использовать циклы запрещено!*/

    int nums[7];

    notAloop(nums, 1);

    cout << "The largest number is << " << *max_element(nums, nums + 7);

    /*⠀⠂⢄⠣⠘⣈⠒⡁⠌⡐⢠⠀⡀⢀⠀⡀⠀⡀⠀⢀⠀⠀⡀⠀⢀⠀⠀⡀⠀⢀⠀⠀⡀⠀⢀⠀⠀⡀⠀⢀⠀⠀⡀⢀⠀⢀⠀⢀⠀⢀⠀⢀⠀⡀⠀⡀⠀⡀⠀⡀⠀⡀⢀⠀⢀⠀⢀⠀⢀⠀⠀⡀⠀⢀⠀⠀⡀⠀⢀⠀⠀⡀⠀⢀⠀⠀⡀⠀⢀⠀⠀⡀⠀⢀⠀⠀⡀⠀⢀⠀⠀⡀⠀⢀⠀⠀⡀⠀⢀⠀⠀⡀⠀⢀⠀⠀⡀⠀⢀⠀
⠀⢀⠰⢀⠐⠠⠀⠄⠡⢐⠈⡐⢀⠂⠔⠠⢀⡁⢂⠈⡐⠠⠁⠌⡐⠠⢁⡐⢀⠂⠌⡐⢠⢈⠐⠀⡀⢄⢂⡀⢄⡀⣦⣤⣬⣤⣤⣤⣤⣦⣤⣤⣤⣬⣤⣤⣬⣤⣴⣤⣴⣤⣤⣴⣤⣥⣤⣦⣤⣴⣤⣤⣦⣤⣦⡀⡀⢄⡈⡐⣀⢂⡐⠈⠐⠈⡀⠄⠡⠈⠄⢡⢈⠐⡠⠁⡜⢀⠡⢈⠐⠠⢈⠐⡈⠠⢁⠂⠡⢈⠠⢁⠐⡀⠂⢄⠠⢀⠐⠀
⢀⠂⠐⡠⠈⠄⣁⠂⡐⠠⢈⠐⡠⠈⠤⢁⠂⡐⠠⢁⠄⠡⠘⠠⠠⢁⠂⡀⠂⠄⢂⠐⡀⢀⣦⣴⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣶⣷⣶⣤⣤⣦⣤⣀⣀⠂⠀⡁⠄⠀⢂⠂⠌⡐⢀⠂⠄⡁⢂⠈⠄⢂⠐⡀⠂⠌⡐⠠⢀⠂⠀⠂
⠀⠌⠐⠠⢁⠂⠄⠠⢀⠡⢂⠂⠄⡁⢂⠂⠌⠠⢁⠂⠌⡀⠃⠄⡁⢂⠐⠠⢁⢂⠁⢂⣴⣿⣿⣿⠿⠛⠉⡉⠉⠉⠉⠉⠉⠀⠄⠠⠀⠄⡀⢀⣀⣄⣰⣾⣿⣿⣿⢿⡿⢿⢶⠶⣶⡴⣦⣶⣼⣶⣿⣭⣌⣉⣉⣉⣉⠋⡛⠛⠛⠛⠿⢻⠿⢿⠿⠿⣿⣿⣿⣿⣿⣿⣿⣿⣴⣦⣆⣀⠠⠀⠂⠉⠄⠰⠀⠂⠌⡀⢂⠀⡁⠂⠄⡁⠂⢀⠁⡀
⠈⠄⡈⢁⠂⠌⠠⢁⠀⠒⠠⢈⠐⠠⠁⡌⠐⡁⢂⠘⠠⢀⢉⠐⡀⠂⠌⠐⠂⢄⣴⣿⣿⡿⠟⠁⠠⢈⢰⠠⠑⡂⠱⠈⡀⢁⠂⣦⣥⣶⣾⣿⠿⠟⠛⠋⠉⢀⠠⢀⢠⡀⣄⢂⡀⢄⠠⢀⠉⠉⠉⠙⠛⠛⠛⠻⠟⠿⠿⠿⠿⡿⢿⢿⡶⢷⣾⠶⠿⠿⡟⠛⠛⠻⠿⢿⡿⣿⣿⣿⣿⣶⣤⡌⠐⠀⠡⢈⠂⡐⢈⡐⠠⠁⠂⠌⠐⠠⠀⠀
⠐⠠⠠⠁⠌⠠⢁⠂⡈⠔⡁⠂⠌⡐⠡⠠⠑⡈⠄⡘⢀⠂⠄⠂⠄⠡⠊⠁⣤⣿⣿⣿⠏⠡⡐⠈⡄⠃⠤⠘⠠⠁⠄⢂⣤⣴⣾⣿⠟⢋⠁⣀⣄⣦⣤⣷⣾⣶⣿⣿⡿⠿⠿⠿⠿⡿⣿⣷⣾⣶⣾⣤⣦⣤⣁⣄⣠⣀⣄⣂⣐⣀⣄⣀⣠⣀⣀⣄⣲⣤⣴⣤⣦⣴⣶⣶⣧⣤⡈⠛⠿⣿⣿⣿⣶⣬⣀⠀⠂⠐⠠⠐⠠⠁⠌⡐⠁⡐⠈⠀
⠠⢁⢀⠃⠌⡐⢀⠂⡐⠤⢀⡁⠆⠠⢁⠂⢡⠐⠠⠐⠂⠌⡐⠈⠄⠡⢀⣡⣿⣿⡿⠃⢀⠐⣀⠃⠰⠁⡀⠂⢁⣐⣼⣿⠟⠋⠩⣄⣢⣮⣿⠿⠟⠛⠋⠉⠉⡀⢀⠀⡀⡐⣀⣂⣐⡀⡀⠠⠀⠉⠉⠉⡙⠛⠛⠿⠻⠿⠿⠿⢿⠿⠿⠿⠿⠟⠟⠛⠛⠛⠋⡉⢉⠉⠉⠉⠉⠻⣿⡦⠀⡀⢉⠻⣿⣿⣿⣧⣐⠈⠀⢁⠂⠅⠠⠐⠠⠐⡀⠁
⢀⠂⠠⠌⡐⠀⠆⡐⠰⢀⠂⠄⡈⠔⢠⠉⢠⠈⠄⣁⠊⡐⠠⠁⠌⠀⣶⣿⣿⠟⠁⡀⠢⠞⡀⠈⠄⠂⢠⣵⣾⡿⠋⢡⣰⣼⣿⠿⠟⣋⣭⣴⣾⣶⣿⡿⠿⠿⠿⠿⠿⠿⠿⢿⣿⣿⣿⣷⡇⠨⠄⢁⠠⢀⠡⢀⠂⠄⠂⠐⡀⢀⠂⡐⣀⢂⣌⣠⣥⣦⣵⣴⣶⣬⡄⠁⠂⢁⠠⠐⠠⠐⢀⠠⠀⠙⠿⣿⣿⣷⡄⠀⡈⠄⡡⢈⠀⠡⠀⠄
⢀⠈⡐⠠⠄⡁⢂⠰⠠⠁⠌⡐⠠⠈⢄⠘⡀⠌⡐⠠⠐⠠⠁⠌⠐⣼⣿⣿⡏⢀⠂⡘⢡⠀⠄⣁⣰⣾⣿⠟⠁⣀⣶⣿⡿⠋⣡⣶⣾⡿⠟⢋⣉⣀⣄⣀⣂⣐⣀⣂⣄⠀⢂⠈⠻⣿⣶⡄⠀⠌⡐⢂⡑⠢⠘⢠⠂⠔⠈⡀⣴⣶⣾⣷⠿⠿⠿⠟⠛⠋⠛⠉⠋⠻⢿⣷⣬⣄⡀⠂⠡⢃⠄⡆⠈⠄⠠⠈⢿⣿⣷⣤⠀⠒⡀⠂⠄⢁⠂⡀
⠀⠂⢀⠁⣂⠐⡈⠤⢁⠃⡐⢀⠡⠈⠄⠒⢀⠒⡀⠡⢈⠠⠁⠠⢸⣿⣿⠟⠀⠺⢠⠑⡀⠄⢲⣾⡿⠋⠁⢐⣼⣿⠟⢁⣴⣿⣿⣫⣷⣾⣿⠿⠿⠿⠿⠿⠻⠿⠿⠿⢿⡿⣿⣷⣶⣬⣻⣿⡆⠐⠠⠁⠄⠡⣁⠂⠌⠄⡁⢀⠉⠉⣁⣾⡟⢀⠠⠀⠌⢀⠡⠈⠐⢀⠂⠉⡙⢿⣿⣦⡁⢀⠈⠤⠁⢂⠄⠁⠠⣿⣿⣯⡀⢀⠡⠈⠄⠈⠄⠀
⠀⠂⢈⠐⡀⢂⠐⡄⢂⠒⠀⠂⠄⠃⡘⠈⠄⠂⠡⢁⠀⠆⠀⣥⣿⣿⡿⠀⠌⡰⠁⠐⠠⢀⡿⠏⠀⡐⣬⣿⡟⢋⣴⣿⣿⣿⡿⠛⠋⢁⠀⢂⠐⢀⠀⢻⣦⡀⠄⢀⠂⠀⠄⠉⢻⣿⣿⣿⣷⣆⡁⢈⠈⡐⠠⠌⢈⢂⡐⢀⠈⢄⣿⡟⠀⠂⡀⢂⢈⡠⣤⣦⣵⣶⣶⣶⣶⣶⣿⣿⣧⣤⢂⡀⠂⢁⠠⠈⡀⣽⣿⣿⡇⠀⠢⢉⡐⠈⢀⠂
⠀⠐⡀⠒⠠⢁⠐⡈⠄⠌⠠⠁⠌⡐⠠⠁⠌⡀⠃⠄⡈⠀⢤⣿⣿⣿⠃⢀⠂⡔⠁⢌⠠⠀⠠⠐⠠⣿⠿⠃⣰⣾⣿⠟⠋⢀⠀⠳⣌⢦⡖⠀⠄⠂⠠⠀⠹⢃⠀⠂⡄⠁⢂⢁⣿⡟⠀⢈⠛⢿⣿⣆⠰⠈⠁⠌⢠⠂⡐⠢⠈⢾⣿⡇⢀⣡⣴⣶⣿⡿⢿⣿⡏⠉⡉⠉⢹⣏⠙⣿⣿⠻⢿⣿⣶⣤⣀⠂⠀⢾⣿⣿⣇⠀⠁⢆⠀⡐⠀⡀
⠀⠠⢀⠱⠈⠄⢂⠡⠌⠠⠁⠄⠒⡀⠡⠌⡐⠠⠁⠂⢀⢰⣿⣿⣿⠃⢀⠂⡘⢠⠁⢂⠂⠡⠐⡀⢁⠀⠠⣰⣿⡟⣇⠠⠈⢠⠘⡀⠌⠳⠄⢈⣰⣬⣷⣿⣿⣷⣮⣄⠀⠌⢀⠚⠛⠁⡀⠂⠠⢀⣽⣿⣿⡄⠁⠌⡀⠆⡁⢣⠐⣸⣿⣧⣾⡿⠛⢉⠁⢀⠠⣿⣧⡐⠀⡁⠈⣿⡆⠉⠡⢀⠀⣈⣙⠻⣿⣷⣌⠘⣿⣿⣿⡄⠠⠈⠠⠀⠐⠀
⠀⢀⠂⠄⡡⠈⠄⠒⡈⠄⠡⠀⠂⠄⢡⠐⡀⠃⠀⣡⣶⣿⣿⡿⠁⡀⠂⠠⢀⠡⠀⠡⠈⡀⠡⠐⢠⠈⢤⣿⡿⠀⠻⠶⠃⠆⡑⠠⠈⡐⣸⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⠀⠐⠈⡀⢐⣬⣶⣿⠟⠋⣿⣿⠀⠐⡀⠃⠠⢀⠰⣽⣿⡿⠋⢀⠐⢠⠈⡄⠠⠈⠻⠟⡀⢤⣡⣽⣇⣌⠳⠀⠸⠿⠟⠀⢀⠻⢿⣷⡘⢿⣿⣿⣶⣀⠐⠀⠁⡀
⠀⢀⢈⠐⠠⢁⠂⡔⠠⠈⠄⡀⢉⡐⠀⠆⠀⣠⣵⣿⣿⣿⣿⣶⣶⣶⣾⣶⣶⣦⣈⣄⠂⠐⢀⣦⣾⣾⣾⣿⡇⠐⠈⠹⡂⠔⡠⠁⡐⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⢈⠐⣈⣿⡟⠋⠄⡀⠂⣿⣿⠀⢂⠠⢌⣔⣠⣿⣿⡟⠀⠺⣤⢢⡄⢂⠠⠁⢂⣱⣶⣿⣿⣿⣿⣿⣿⣿⣦⡁⠐⠠⠈⡀⠄⠘⣿⣷⡈⠹⢿⣿⣿⣦⣈⠀⠀
⠀⢀⠈⠠⢁⠂⠄⠠⠁⠌⠠⠀⢆⠀⠐⢀⣾⣿⣿⣿⣿⣿⠿⠛⠋⠛⢹⣿⣿⢿⣿⣿⣦⡥⠌⠛⠿⠿⣿⣿⣷⠀⢁⠂⠄⠘⠠⠁⠠⠀⡙⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠏⠀⠄⣂⣼⣟⣡⣶⣦⣥⣼⣿⣿⠈⡀⢸⣿⣿⣿⣿⣿⡧⠀⡁⠐⢣⡟⠀⠄⠂⢲⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡆⠈⠄⠐⠠⡐⠀⣿⣿⣿⣄⡀⠙⣿⣿⣿⣦⠁
⠀⡀⠌⢁⠂⠄⠂⢡⠈⠄⡁⠐⠂⢈⣰⣿⣿⣿⣿⣿⠟⠁⡀⢂⢰⣴⣾⣿⣿⣿⣿⣿⣿⣿⣷⣄⢰⡀⠨⢿⣿⣷⡀⢀⠂⢌⣠⣦⣥⡔⠀⠈⠛⠿⢿⣿⣿⡿⠟⠋⢀⠠⠈⢀⠻⢿⡿⠛⠋⡙⣻⣿⡿⠃⠠⢀⠉⢿⣿⣿⣿⣿⣿⡄⠠⠁⠠⠁⠌⢀⠂⢈⠻⣿⣿⣿⣿⣿⣿⣿⣿⡿⠀⠌⠀⣾⣿⣿⣿⣿⣿⢻⣿⣿⣶⡈⠿⣿⣿⡄
⠀⠀⠌⡀⠂⠌⠐⠠⠐⠠⠐⠀⢂⣼⣿⣿⣿⣾⣿⠋⢀⠐⣠⣾⣿⣿⣿⡿⠿⢿⣿⣿⢿⣿⣿⣿⣿⣷⣶⣄⣨⣿⣿⣦⣼⣾⠿⠛⢉⠡⠈⠐⠠⢀⠀⡀⢀⢠⣐⡈⠀⠄⡈⠄⣦⡍⣽⣀⣶⣾⣿⠟⠁⠠⢁⠆⠠⠀⡛⢼⡿⣿⣿⣇⡡⠀⡁⢰⣬⣤⣀⠂⡀⢉⠛⠻⠿⢿⡟⣛⣻⡁⠄⠂⢁⠀⠴⣯⣽⣿⠟⢾⣿⡆⠻⣿⣄⢻⣿⣷
⠀⠈⠰⢀⠁⠂⡁⠌⠠⢁⠂⢈⣾⣿⣿⠟⣽⣿⠁⡀⢂⣰⣿⣿⣿⠿⠁⢀⠂⢌⣿⣿⡄⢈⠻⢿⣿⣿⣿⣿⣿⠟⠛⠻⢿⣿⣶⣄⣂⠄⡈⢄⣷⡷⠦⠐⡀⠘⠛⠛⠓⠂⠙⣦⣿⣿⣽⣿⠟⠋⢀⠠⢀⡑⠊⠜⠠⠁⠄⠸⣗⣿⣿⣿⣿⣷⣾⣿⡿⠛⠛⠃⣴⣷⣄⠂⡀⠄⣿⣿⣿⡅⠀⠌⣀⣶⣾⣿⣿⣿⣦⠀⣿⣧⠀⢻⣿⣼⣿⣿
⠀⠈⢄⠂⠌⡐⠀⠌⡐⠀⡀⣶⣿⣿⠏⠠⣿⡿⠀⡐⣰⣿⣿⣿⠋⢀⠐⡀⠈⢤⣿⣿⣿⡄⠠⠀⠄⡈⠙⠻⠟⠀⠄⡁⢀⠈⡙⠻⠿⢿⣿⣿⣿⣷⣶⣷⣶⣷⣶⣶⣷⣿⣿⡿⡿⡟⠋⢀⡐⠈⢠⠐⡌⠐⢈⠐⠠⠑⡀⠂⢜⣿⣿⣧⡙⠻⢿⣿⣷⣾⣧⣴⡙⣻⣿⣇⣀⢂⡌⣨⣿⣿⣶⣮⡙⠟⠋⠛⢿⣿⣿⠇⣹⣿⡂⠄⣿⣿⣿⣿
⠀⠂⢠⠈⡐⠠⠈⡐⠀⠄⢰⣿⣿⡟⡀⢂⣿⡷⠀⢰⣿⣿⣿⠃⢀⠂⠠⣅⣈⣽⣿⣿⣿⣿⣧⣔⣈⠐⢊⠀⡐⢈⠲⠙⣄⠒⠤⠀⠄⡀⠀⠄⠉⢈⠉⠉⡉⠉⠉⣽⣇⢠⡙⢻⣛⣿⣷⡾⠇⠉⢂⠠⠐⡠⢈⡐⢀⠃⡄⢈⠈⢿⣿⣿⣿⣶⣄⠂⡉⠛⠛⠿⠿⠿⡿⢿⠿⡿⠿⠿⠿⠛⢻⣿⣿⡶⠀⠄⠠⢀⠠⠐⢸⣿⡧⢀⣿⡷⣿⣿
⠀⠐⢀⠂⠄⡁⠐⠠⢉⠀⢸⣿⣿⡿⢀⠂⣿⣿⠀⢸⣿⣿⣿⠀⢠⣀⣱⣿⣿⣿⣿⣿⠻⣿⣿⣿⣿⣿⣤⣀⠄⠠⢀⠣⢀⠘⠤⠃⠒⡀⠡⠐⠈⡀⠄⡁⠠⠈⢄⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠄⠂⢀⠡⠐⠠⠐⡈⠄⡀⠂⠠⠀⠹⠿⣿⣿⣿⣿⣤⡂⠁⠄⠠⠐⠀⠠⢀⠐⠀⢂⠠⠈⢸⣿⣿⣟⠀⠠⠁⠠⠀⠢⣼⣿⠇⢨⣿⣱⣿⣿
⠀⠈⢀⠈⠰⠀⠁⠆⡈⠀⠸⣿⣿⣿⠁⠀⣿⣿⠀⢸⣿⣿⣿⠀⣾⣿⣿⣿⣿⣿⣿⣿⠀⠈⠹⢿⣿⣿⣿⣿⣿⣶⣀⠀⡀⠈⠀⠆⠁⠀⣶⣿⣿⣿⣿⣿⣿⣿⣿⡿⢏⣿⣿⣿⡿⡿⠿⠿⠉⢀⡈⠀⡀⠁⠆⠁⠰⠈⡀⠇⡀⠁⡀⠰⠈⢿⣿⣿⣿⣿⣇⡀⠁⢀⠁⠆⡆⠸⡸⠀⠀⠆⢸⣿⣿⣿⣆⠀⢁⠀⢁⣾⣿⡏⢰⣾⣿⣿⣿⣿
⠀⠐⢠⠈⠄⠡⠈⡐⠠⢂⠀⢿⣿⣿⡇⠠⢸⣿⠄⠂⣿⣿⣿⡏⠿⠿⠿⠿⠿⣿⣿⣿⡄⠂⠄⡀⠈⠙⠿⣿⣿⣿⣿⣿⣦⣬⣐⡠⠈⠠⠙⠉⠉⡀⠄⠠⠀⠄⢀⠀⢸⣿⣿⡷⢀⢀⣬⣷⣵⣦⣽⣤⣤⣅⡂⠈⠄⠡⠐⠢⢀⠁⠠⠐⠈⣴⣿⣿⣿⣿⣿⣷⣬⣀⠀⢂⠠⠀⡑⠈⠠⢈⢸⣿⣿⣿⣿⡆⠠⠸⣿⠟⠋⢀⣹⣿⣿⣿⣿⡏
⠀⠐⢠⠈⡄⠁⠂⠄⢡⠀⠂⢠⣿⣿⣷⡀⢸⣿⣧⠀⢻⣿⣿⣿⡄⢀⠂⠐⠠⢙⣿⣿⣿⣄⠐⠀⡁⠂⠠⠀⠙⠻⣿⣿⣿⣿⣿⣿⣿⣶⣦⣌⡠⢀⠐⠀⡁⠂⠠⠈⠐⣿⣿⣿⣦⢈⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⢂⠐⠀⢂⠠⠈⢀⢂⣿⣿⣿⡿⢿⣿⠏⠉⠛⠿⣿⣶⣤⡂⠀⠌⠐⣤⣾⣿⣿⣿⣿⣷⠀⠄⣤⣼⣾⡿⢟⣻⣿⣿⡿⠁
⠀⠐⡀⢂⠄⢁⠂⠌⠠⢈⠐⠀⠸⣿⣿⣷⡀⢿⣿⣦⡀⠹⣿⣿⡟⠀⠠⠁⠄⢲⣿⣿⣿⣿⣷⣤⣐⠈⡀⠌⠐⠠⣿⣿⡟⠛⠻⠿⣿⣿⣿⣿⣿⣿⣶⣷⣤⣬⣄⣈⠄⠻⢿⣿⣿⡷⠿⣿⡋⢁⠈⠉⠙⠛⠃⢀⠲⣾⣦⣤⣆⣈⣴⣿⣿⣿⡟⠁⡀⠄⠂⠈⠄⠂⠈⠙⢻⣿⣆⣤⣿⣿⣿⣿⡉⣿⣿⣿⠄⠿⠟⠋⠁⠄⣸⣿⣿⡿⠃⠀
⠀⠄⢈⠠⠈⠄⠠⠌⡐⠠⠈⠄⠀⢹⣿⣿⣷⡀⠙⢻⣿⣷⣤⣁⡠⢀⠁⡐⠀⠂⠙⣿⣿⣿⣿⣿⣿⣷⣦⣄⡈⠄⣻⣿⣿⣄⠠⢀⠀⠈⠉⠙⠻⠿⣿⣿⣿⣿⣿⣿⣿⣶⣤⣙⣭⡀⢄⠠⠁⡄⡈⠐⡀⠂⢁⠠⠀⢿⣿⣿⣿⣿⣿⣿⠟⠉⠀⠄⠠⠐⠈⡀⠂⠌⢀⢡⣠⣿⣿⣿⣿⣿⢻⣿⣷⣿⣿⣿⣇⠠⠀⠌⠐⣸⣿⣿⡟⠀⡐⠀
⠀⢀⠂⠌⡐⢈⠀⠒⡀⠡⠈⠄⡈⠀⠈⢿⣿⣿⣷⣤⠈⠙⠛⠿⠿⠀⠠⠐⡈⢀⠁⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣽⣿⣿⣿⣦⠀⡈⠄⠁⠂⠄⡀⠀⠌⡉⠛⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣶⣵⣶⣤⡈⠀⠄⢂⠈⣙⢿⣿⠿⠛⠁⡠⢈⠐⡈⠠⢀⢡⣄⣶⣾⣿⣿⣿⣿⣿⣿⣿⣷⠈⣿⣿⣿⣿⣿⣯⠀⠐⠈⡔⣿⣿⣿⠁⠀⡀⠄
⠀⠀⠌⡐⢀⠂⠌⡐⠠⠁⠌⢀⠐⠡⢈⠘⢿⣿⣿⣿⣯⡀⠂⠐⡀⠄⣁⠂⡑⠠⠀⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣤⣴⣈⡀⢂⠀⠡⠐⠀⡐⣿⣿⣿⠟⠙⠛⠻⠿⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣾⣶⣾⣶⣶⣷⣾⣿⣿⣿⣿⣿⣿⣿⣿⡿⠟⠋⠀⣼⣿⣿⠆⢹⣿⣿⣿⣿⣿⠀⡈⠄⢸⣿⣿⡇⠀⠐⠀⡀
⠀⠈⡐⠠⠌⡐⠠⠘⡀⢃⠈⡀⠌⠰⢀⠢⠀⠌⢻⣿⣿⣷⣌⠀⠄⠐⢠⠃⠤⠁⠠⢹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣮⣄⡠⠁⢺⣿⣿⡿⠀⠂⡐⠠⡄⢠⢀⠀⠄⠉⠉⣿⣿⣿⠟⠿⠿⠿⠿⠿⣿⣿⣿⣿⠿⠿⠿⠿⠻⠛⠛⢉⣿⣿⣧⠀⠂⠁⣼⣿⣿⠃⢨⣿⣿⣿⣿⣿⡇⠀⡐⢸⣿⡿⠁⠀⠂⡀⠄
⠀⠐⠠⢁⠢⢀⠁⠒⣀⠂⡐⠀⡈⠔⣀⠂⣁⠂⠄⠙⠻⣿⣿⣦⠈⠐⡀⠊⡐⠄⡁⠘⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣃⠠⢁⠀⠡⠈⠄⠊⠄⢈⠐⠀⢾⣿⣿⠀⠂⠄⠐⡀⠂⠀⣿⣿⣿⡆⠐⠀⠄⠂⢁⠈⡀⢿⣿⣿⣧⠈⣀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣇⠠⠀⢺⣿⣟⠀⢀⠁⢀⠀
⠀⠠⢁⠂⡰⠀⠌⠰⢀⡐⠠⠐⢀⠂⠄⡐⠀⠬⠀⠄⠈⢻⣿⣿⣷⠀⡀⢁⠀⠆⡀⠌⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣾⣶⣥⣔⣈⣀⣂⣈⣄⣻⣿⣿⣈⣒⣨⣀⣐⣠⣁⣻⣿⣿⣗⣎⣐⣈⣄⣧⣶⣼⣾⣿⣿⣶⣶⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠠⢹⣿⣟⠀⢀⠀⠂⠀
⠀⠂⢀⠊⠄⡐⠈⡐⢂⠐⠠⠁⢂⠌⡐⠠⢁⠂⠡⢈⠀⠄⣿⣿⣿⣇⠀⠄⡈⢡⠀⠄⢹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠂⢼⣿⣟⠀⠀⠄⠂⠁
⠀⠌⠠⠘⢠⠀⠐⠠⡁⠊⠄⠂⠄⠂⠄⡁⠂⠌⡐⠠⢁⠀⠘⣿⣿⣿⡄⠂⠠⠁⡀⢂⠌⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡀⠡⢸⣿⡿⠀⢀⠂⠀⠂
⠐⠠⢁⠘⠠⠈⠄⡁⠌⠡⠐⠈⠌⡁⠒⠠⢁⠂⡐⢀⠢⠐⡀⠙⢿⣿⣿⣄⠁⡐⠀⠂⡀⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡀⠐⣸⣿⡿⠀⢀⠠⠈⠀
⠠⢁⢀⠊⠄⠡⢀⠘⠠⢡⠈⡐⢂⠐⠨⠐⡀⢂⠐⡀⢂⠐⡀⠂⠈⣿⣿⣿⣆⠠⠈⠄⠠⠸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⡐⢸⣿⣟⠀⢀⠠⠀⠁
⡀⠂⠠⠌⡐⠁⢂⠈⡐⢀⠂⠄⠂⠌⢠⠁⡐⠠⢁⠐⡀⢂⠡⢀⠁⠀⠿⣿⣿⣿⣄⠂⢁⠀⠻⣿⣿⣿⡟⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠄⢺⣿⣯⠀⢀⠠⠀⠁
⢀⠁⠂⠔⠠⢁⠂⡐⠈⠄⡈⠄⠨⢐⡀⠢⠀⠅⢂⠐⡀⢂⠐⡀⢊⠄⠀⠙⢿⣿⣿⣿⣄⠠⠁⠙⢿⣿⣿⣦⠈⠉⠛⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠂⢼⣿⣷⡄⠀⠠⠀⠁
⠀⠂⠉⠄⣁⠂⡐⠠⢈⠐⠠⠘⡀⢂⠘⠠⠁⠌⢂⠐⡐⢀⠂⠌⠠⢈⠐⡂⠀⠈⢿⣿⣿⣷⣬⠀⠌⢿⣿⣿⣧⡀⠡⢀⢹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡀⠡⢸⣿⣿⡇⠀⠐⠀⠁
⠈⠄⠡⠈⠄⠂⠄⡁⠠⠘⠠⠁⡐⠠⠉⡄⠡⠈⠄⠒⡀⠂⠌⠠⢁⠂⠘⡀⠡⢂⠀⠉⠉⢿⣿⣿⣄⠈⢻⣿⣿⣷⣄⠂⢨⣿⣿⣇⠉⠻⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡆⢀⢸⣿⣿⣇⠀⢈⠀⠂
⠐⡈⠄⡑⠈⠄⠡⢀⠡⠘⠠⠁⠄⠡⢁⠰⠀⡑⢈⠐⡠⠡⠘⡀⠂⠌⡐⠠⢁⠂⠂⡔⠀⡀⠻⢿⣿⣧⡄⠻⣿⣿⣿⣷⣼⣿⣿⡇⠐⠠⠀⢈⠉⠛⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠰⣿⣿⣿⠀⠀⠄⠂
⠄⡀⠰⢀⠡⠊⡐⠠⢀⠡⢂⠡⢈⠐⡂⠄⠡⢐⡀⠢⠐⠠⢁⠄⡁⢂⠠⠁⠄⡈⠡⠐⢠⠀⠄⠀⢹⣿⣿⣄⠘⣻⣿⣿⣿⣿⡛⠋⢀⠂⢁⠀⢂⠈⡀⢀⠉⠉⢹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⠈⠠⠹⣿⣿⠀⠈⠀⠄
⠠⠀⡁⠂⡄⠡⠐⡀⠂⡐⢀⠂⠄⢂⡐⢈⠐⡠⢀⠡⢈⠐⠠⠂⠌⡀⢂⠁⠂⠄⠡⠈⠄⡐⠤⠈⠀⠹⣿⣿⣧⠀⡘⠿⣿⣿⣿⣶⣄⠀⠂⠌⠀⠣⠀⢂⠠⠁⣼⣿⣿⡇⠉⠙⠛⠿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠡⡘⣿⣿⠀⠠⠁⠀
⢀⠡⠀⠅⠠⢁⠂⡐⠠⢁⠂⠌⡐⠠⠐⢂⠐⡀⠆⠠⢁⠈⡄⢁⠂⠔⠠⠘⠠⠈⠄⡁⢂⠐⡠⠁⠄⡀⠈⢻⣿⣧⡄⠀⠙⢿⣿⣿⣿⣷⣦⡀⠡⠀⡁⠊⢀⢰⣿⣿⣿⠇⠀⢂⠐⡀⠠⠀⠉⠛⠻⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⣿⣿⣿⠃⢈⠐⢈⣿⣿⠀⠄⠀⡁
⠀⠂⠌⢠⠁⢂⡐⠠⠐⡈⠐⠤⢀⠁⠊⠄⢂⡐⢈⠐⢂⠡⠐⠠⢈⠂⠡⠘⡀⠡⢂⠐⠠⠈⠄⢂⡐⠀⠄⠀⠹⣿⣿⣄⠂⠀⠌⠛⣿⣿⣿⣿⣧⣄⠐⢀⢢⣿⣿⣿⠏⠀⠌⢢⠐⡘⠄⡌⡐⠠⠀⠄⢺⣿⣿⠀⠉⡙⠛⠛⠟⠿⠿⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠿⣿⣿⣿⡟⣹⣿⣿⡿⣹⣿⣿⡟⠠⠀⠂⠌⣿⣿⠀⠐⠀⡀
⠈⡐⠈⠄⡈⠄⠠⢁⠐⠠⢁⠂⢄⠈⡡⠌⠠⠐⠂⠌⣀⠂⡑⠠⠂⠌⠠⡁⠐⡁⠂⠌⠠⠁⠌⠠⢀⠃⠌⡀⠄⠛⢿⣿⣦⡁⠐⠠⠀⠙⠿⣿⣿⣿⣿⣦⣿⣿⣿⠏⠀⡈⠄⠃⠌⠄⢃⠐⠡⠀⠡⠀⣿⣿⣿⠄⠁⠠⠐⡈⠄⠠⢀⣾⣿⣿⡇⢀⠀⡀⠀⢼⣿⣿⡿⠀⡐⣼⣿⣿⡿⢱⣿⣿⣿⣷⣿⣿⡿⠁⢀⠂⢉⢮⣿⣿⠀⠈⡀⠀
⠐⡀⠌⡐⠠⢈⠡⢀⠈⠔⠠⡈⠄⠒⠠⠈⠄⡑⢈⡐⠠⠐⠠⢁⡘⠠⠁⠤⠁⠄⠃⠌⡠⠁⠌⡐⠠⠈⠄⠡⠀⠄⠀⢻⣿⣿⣦⡀⠁⢂⠀⠌⠛⢿⣿⣿⣿⣿⣿⣶⣤⣄⡠⠁⢈⠀⠂⠈⠄⠈⠄⢂⣿⣿⣿⡀⠌⠠⠁⡘⠀⡁⢢⣿⣿⣿⠀⠄⠂⢀⢡⣾⣿⣿⠃⡐⣸⣿⣿⣿⠃⢼⣿⣿⣷⣿⣿⡿⠁⢀⠂⠀⢾⣿⣿⡿⠀⠀⠄⠀
⠄⡀⠂⠤⢁⠂⡐⠠⠈⠤⢁⠐⡈⠄⠡⢁⠂⠔⠂⠄⢡⠈⣁⠂⠄⠡⢈⠔⡈⠄⢃⠐⠠⢁⠂⠄⠡⠈⠄⠡⢈⡐⢈⠀⠀⢿⣿⣿⣦⣀⠂⠄⠂⡀⠈⠙⠻⠿⣿⣿⣿⣿⣿⣿⣶⣤⣧⣬⣐⣈⣠⣐⣿⣿⣿⠀⠐⡀⢁⠀⠂⠄⣰⣿⣿⡿⠀⢂⠈⢤⣿⣿⣿⣏⣠⣤⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠋⢀⠐⠠⢚⢠⣿⣿⣿⠃⠀⠈⡀⠄
⠠⠀⣁⠢⢀⠂⠄⡁⠂⡐⡀⢊⠐⡈⠐⠂⠌⡠⠁⢌⡀⠂⠄⠂⠌⠡⢀⠂⠄⢌⠠⢈⠡⠀⡌⠠⠁⠌⠠⢁⠂⠌⡀⢢⢀⠀⠘⠻⢿⣿⣷⣦⣔⡀⠁⠌⠀⠄⢀⠈⡙⠿⠿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣶⣶⣾⣶⣶⣿⣿⣿⣷⣶⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠿⠛⠋⠁⡀⠂⠄⠂⠁⣤⣿⣿⡿⠁⠀⠄⠁⡀⠀
⢀⠁⡀⢂⠄⠌⡐⢀⠂⡁⠰⢀⠂⠄⡉⠰⠀⠤⢁⠂⠄⡉⠄⡉⠤⢁⠂⠡⠈⢄⠂⡐⠠⠁⠄⠡⢈⠂⢁⠂⠌⠐⡀⠂⠄⡉⠄⠠⠀⠘⠛⠿⣿⣿⣷⣦⣥⣈⡀⠄⠠⢀⠠⠀⡀⢀⠉⢈⠉⠙⠋⠛⠛⠛⠻⢿⠿⡿⢿⠿⡿⢿⠿⡿⢿⠿⡿⢿⠿⠿⠛⠋⠛⠉⡉⠉⢉⠠⢀⠠⠀⠄⡐⠀⠆⠐⢀⠂⡈⣰⣿⣿⣿⠁⠠⡑⠈⠐⠀⡀
⢀⠂⡐⠤⡈⣄⠒⣠⠐⡨⣐⠠⣈⠐⠤⠁⠌⠐⠠⠈⠐⠠⠈⠐⡀⠂⠌⠁⠌⠀⠂⠄⠁⠌⠀⡁⠂⠌⠠⠈⠄⠡⢀⠡⢂⠈⠄⠐⠀⠂⢀⠀⠈⠉⠙⢿⣿⣿⣿⣶⣥⣆⣄⣂⡐⢀⠐⡀⠈⠄⠂⡐⠀⢂⠐⠀⠠⠀⠄⠠⠀⠄⠠⠀⠄⡀⠄⠠⠐⠀⢂⠐⠠⠁⡀⠡⠀⠄⠂⢀⠂⠄⠠⢌⣠⣈⣄⣲⣼⣿⣿⠋⠁⢀⠐⢈⠁⠂⠐⠀
⠀⠠⠈⢁⠐⠈⠘⠀⠋⡐⠁⠑⠀⡈⠐⠀⡐⠈⠀⠄⠁⡀⠂⠁⠀⠄⠀⠂⢀⠁⡀⠂⠈⢀⠐⠀⡀⠂⠁⠐⠀⡐⠀⠄⠠⠈⠄⠂⠁⡀⠂⠀⢬⣄⣤⣦⡀⣌⠙⣛⠻⣿⣿⣿⣿⣿⣷⣶⣷⣶⣶⣶⣮⣤⣆⣡⣦⣥⣴⣆⣡⣆⢤⣡⣆⣴⣶⣶⣶⣷⣶⣶⣶⣶⣶⣶⣾⣶⣾⣶⣶⣾⣿⣿⣿⣿⣿⣿⡿⢏⡁⢀⠐⠀⠠⠀⠠⠈⠀⠄*/
}

void t4() {
    /*Грузовой самолет должен пролететь с грузом из пункта А в пункт С через пункт В.
    Емкость бака для топлива у самолета – 300 литров.
    Потребление топлива на 1 км в зависимости от веса груза у самолета следующее:

    • до 500 кг — 1 литров/км;
    • до 1000 кг — 4 литров/км;
    • до 1500 кг — 7 литров/км;
    • до 2000 кг — 9 литров/км;
    • более 2000 кг — самолет не поднимает.
    
    Пользователь вводит расстояние между пунктами А и В,
    расстояние между пунктами В и С, а также вес груза.
    Программа должна рассчитать какое минимальное количество топлива
    необходимо для дозаправки самолету в пункте В, чтобы долететь из пункта
    А в пункт С. В случае невозможности преодолеть любое из расстояний —
    программа должна вывести сообщение о невозможности полета по введенному маршруту.*/

    int SAB, SBC, weight;
    cout << "Enter distance (km) between: " << endl
        << "AB >> ";
    cin >> SAB;
    cout << "BC >> ";
    cin >> SBC;
    cout << "\n" << "cargo weight (kg) >> ";
    cin >> weight;

    if (weight < 2000) {
        int Consumption[] = { 1, 4, 7, 9 };
        int fuelRate = Consumption[weight / 500];
        cout << fuelRate;
    } else {
        cout << "Poor plane cant handle this, you, monster";
    }


}

class Time
{
public:
    int sec = 0, min = 0, hours = 0, days = 0;

    void convertEverythingToSeconds() {
        sec += days * 86400;
        days = 0;
        sec += hours * 3600;
        hours = 0;
        sec += min * 60;
        min = 0;
    }
};

class displayTime : public Time
{
public:
    int Fsec = 0, Fmin = 0, Fhours = 0, Fdays = 0;

    void timeHMS() {
        int tmpSec = sec;
        toHMS(tmpSec);
    }

    void timeBeforeMidnightHMS() {
        int tmpSec = sec;
        tmpSec %= dayL;
        tmpSec = dayL - tmpSec;
        toHMS(tmpSec);
    }

private:

    const int dayL = 86400, hourL = 3600, minL = 60;
    void toHMS(int tmpSec) {
        if (tmpSec < 0) {
            tmpSec = dayL + (tmpSec % dayL);
        }
        Fdays = tmpSec / dayL;
        Fhours = tmpSec % dayL / hourL;
        Fmin = tmpSec % dayL % hourL / minL;
        Fsec = tmpSec % dayL % hourL % minL;

        cout << Fhours << " : " << setw(2) << setfill('0') << Fmin << " : " << setw(2) << setfill('0') << Fsec;
    }
};

int main() {
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