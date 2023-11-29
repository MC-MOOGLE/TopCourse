import math
import sys
from pathlib import Path
sys.path.append(str(Path(__file__).parent.parent))
from CustomModule import mmodule as md

def cycletasks(tasks:int):
    strnum = ""
    for i in range(tasks):
        strnum += f"{i+1} "
    while True:
        print("\n\n")
        task = md.getnumber(f"номер задания. Доступные задания: {md.color(strnum, 'green')} \nДля выхода введите любое другое число")
        print("\n\n")
        try:
            exec(f"t{task}()")
        except Exception as error:
            # print(error)
            md.printcolor("Выход", "red")
            break

def t1():

    md.printcolor("""Показать на экран все простые числа в диапазоне, указанном пользователем.
Число называется простым, если оно делится без остатка только на себя и на единицу.
Например, три — это простое число, а четыре нет.""")

    def is_prime(number):
        if number < 2:
            return False
        for i in range(2, int(math.sqrt(number)) + 1): # Квадратный корень числа - самый большой его делитель
            if number % i == 0:
                return False
        return True

    start = md.getnumber("начало диапазона")
    end = md.getnumber("конец диапазона")
    prime_numbers = []
    prime_numbers = [i for i in range(min(start, end), max(start, end) + 1) if is_prime(i)]
    # for i in range(min(start, end), max(start, end) + 1):
    #     if is_prime(i):
    #         prime_numbers.append(i)
    print('Простые числа:' + md.color(str(prime_numbers), "yellow"))

def tableofmul(start, end, maxm=10):
    end += 1
    for i in range(min(start, end), max(start, end)):
        for j in range(1, maxm + 1):
            print(f"{i} * {j} = {i*j}", end="\t")
        print()

def t2():
    md.printcolor("""Показать на экране таблицу умножения для всех чисел от 1 до 10.""")
    tableofmul(1, 10)

def t3():
    md.printcolor("Показать на экран таблицу умножения в диапазоне, указанном пользователем.")
    start = md.getnumber("начало диапазона")
    end = md.getnumber("конец диапазона")
    maxm = md.getnumber("макс. второй множитель")
    tableofmul(start, end, maxm)



cycletasks(3)