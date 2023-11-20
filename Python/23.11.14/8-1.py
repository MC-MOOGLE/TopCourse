import sys
from pathlib import Path
sys.path.append(str(Path(__file__).parent.parent))
from CustomModule import mmodule as md #very original

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

#i = 100
for i in iter(int, 1):
    print(i)


def t1():
    print("""Напишите программу, которая запрашивает два целых числа X и Y, после чего 
вычисляет и выводит значение X в степени Y. При расчете значения разрешено 
использовать только циклы! Использовать встроенный оператор возведения в 
степень запрещено!""")
    md.printcolor("Постройте кирпичный дом, кирпичи использовать запрещено", "yellow")
    print("\n")
    x = md.getnumber("первое число: ")
    y = md.getnumber("второе число")
    result = 1
    for i in range(y):
        result *= x
    print(f"Ответ: {md.color(result, 'green')}")

def t2():
    print(f"""Подсчитать количество целых чисел в диапазоне от 100 до 999 {md.color("(как я понял, включительно)", "yellow")}, у которых есть 
две одинаковые цифры. При расчете значения разрешено использовать только 
циклы! Использовать формулы из теории вероятностей запрещено!""")
    md.printcolor("\"Использовать формулы из теории вероятностей запрещено!\" 🤓", "yellow")
    counter = 0
    for i in range(100, 1000):
        for j in str(i):
            if str(i).count(j) == 2:
                counter += 0.5
    print(f"\nЧисел, у которых только 2 одинаковые цифры: {md.color(counter, 'Green')}")

def t3():
    print("""Подсчитать количество целых чисел в диапазоне от 100 до 9999, у которых все 
цифры разные. При расчете значения разрешено использовать только циклы! 
Использовать формулы из теории вероятностей запрещено!""")
    counter = 0
    for i in range(100, 10000):
        alldif = True
        for j in str(i):
            if not str(i).count(j) == 1:
                alldif = False
        if alldif == True:
            counter += 1
    print(f"\nЧисел, у которых нет одинаковых цифр: {md.color(counter, 'Green')}")

def t4():
    print("""Пользователь вводит любое целое число. Необходимо из этого целого числа 
удалить все цифры 3 и 6 и вывести обратно на экран.""")
    num = md.getnumber()
    num = str(num)
    newnum = ""
    for i in num:
        if i == "3" or i == "6":
            pass
        else:
            newnum += i
    print(f"\nНовое число: {md.color(newnum, 'Green')}")
    



cycletasks(4)
