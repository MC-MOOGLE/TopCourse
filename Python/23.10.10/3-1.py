# Функции
import random

def getnumber(msg):
    IsFound = False
    while not IsFound:
        try:
            num = input("Введите " + msg)
            int(num)
            IsFound = True
            return int(num)
        except ValueError:
            print("Вы ввели неправильный тип данных. Попробуйте снова.")

def getLenght(n):
    IsFound = False
    while IsFound == False:
        num = getnumber(f"число из {n} цифр: ")
        if len(str(num)) == n:
            IsFound = True
            return num
        else:
            print(f"Вы ввели неправильное число. Требуется цифр: {n}, получено: {len(str(num))}.")

     
def printcolor(string, code):
    print(f"\033[{code}m{string}\033[0m")

def t1():
    printcolor("Пользователь вводит с клавиатуры три цифры (три числа!). Необходимо создать число, содержащее эти цифры. Например, с клавиатуры введено 1, 5, 7, тогда нужно сформировать число 157.",33)
    string = str()
    for i in range(3):
        string += str(random.randint(1, 9)) + str(getnumber(f"{i + 1}-e число: "))
    printcolor("Число, содержащие данные числа: " + string, 35)

def t2():
    printcolor("Пользователь вводит с клавиатуры число, состоящее из четырех цифр. Требуется найти произведение цифр. Например, если с клавиатуры введено 1324, тогда результат произведения 1*3*2*4 = 20.",33)
    printcolor("Не хочу быть занудой, но 1*3*2*4 != 20, 1*3*2*4 == 24.",34)
    n = getLenght(4)
    mult = 1
    for i in str(n):
        mult *= int(i)
    printcolor(f"Произведение чисел: {mult}", 35)

def t3():
    printcolor("Пользователь вводит с клавиатуры количество метров. Требуется вывести результат перевода метров в следующие величины: сантиметры, дециметры, миллиметры, мили (морские).",33)
    meters = getnumber("количество метров: ")
    printcolor("Это равняется...", 33)
    printcolor(f"{meters * 100} сантиметра (-ов)", 33)
    printcolor(f"{meters * 10} дециметра (-ов)", 33)
    printcolor(f"{meters * 1000} миллиметра (-ов)", 33)
    printcolor(f"{meters / 1852} морскую (-их) милю (-ь)", 33)

def t4():
    printcolor("Напишите программу, вычисляющую площадь треугольника. Пользователь с клавиатуры вводит размер основания треугольника и размер высоты.",33)
    a = getnumber("длину основания: ")
    h = getnumber("высоту: ")
    printcolor(f"Площадь равна {a * h * 0.5}", 35)

def t5():
    printcolor("Пользователь с клавиатуры вводит четырехзначное число. Необходимо перевернуть число и отобразить результат. Например, если введено 4512 результат: 2154.",33)
    n = getLenght(4)
    newnum = str()
    for tmp in str(n):
        newnum = tmp + newnum
    printcolor(f"Зеркальное ему число: {newnum}", 35)

while True:
    printcolor("Доступные задания: 1,2,3,4,5", 32)
    task = getnumber("номер задания: ")
    if task == 1:
        t1()
    elif task == 2:
        t2()
    elif task == 3:
        t3()
    elif task == 4:
        t4()
    elif task == 5:
        t5()
    print("\n\n\n\n")

