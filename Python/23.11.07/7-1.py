# Modules and libraries #

import random
import os

# Functions #

def getnumber(msg:str, type:type=int) -> int:
    IsFound = False
    while not IsFound:
        try:
            num = input("Введите " + msg + ": ")
            type(num)
            IsFound = True
            return type(num)
        except ValueError:
            print("Вы ввели неправильный тип данных. Попробуйте снова.")


def printcolor(string:str, code:int=34, ends="\n"):
    print(f"\033[{code}m{string}\033[0m", end=ends)

def coloredtext(string:str, code:int=34):
    return f"\033[{code}m{string}\033[0m"

def allcolors():
    print("bro forgor again 💀")
    for i in range(30, 37):
        printcolor(i, i)

def getrange() -> list:
    n1 = getnumber("первое число")
    n2 = getnumber("второе число")
    numbers = []
    for i in range(min(n1, n2), max(n1, n2) + 1):
        numbers.append(i)
    return numbers

def cycletasks(tasks:int):
    strnum = ""
    for i in range(tasks):
        strnum += f"{i+1} "
    while True:
        print("\n\n")
        task = getnumber(f"номер задания. Доступные задания: \033[35m{strnum}\033[0m\nДля выхода введите любое другое число")
        print("\n\n")
        try:
            exec(f"t{task}()")
        except Exception as error:
            #print(error)
            printcolor("Выход", 31)
            break

# Code #

def t1():
    printcolor("""Пользователь вводит с клавиатуры два числа. Нужно посчитать в указанном 
данными числами диапазоне отдельно сумму четных, нечетных и чисел, кратных 
9, а также среднеарифметическое каждой группы.""")
    numbers = getrange()
    odd = oddcount = even = evencount = nines = ninescount = 0
    for i in numbers:
        if i % 2:
            odd += i
            oddcount += 1
        else:
            even += i
            evencount += 1

        if not i % 9:
            nines += i
            ninescount += 1

    print(f"""\n{coloredtext("Game over!", 31)} Team scores:

{coloredtext("Четные", 36)} | сумма: {coloredtext(odd, 33)}, количество игроков: {coloredtext(oddcount, 33)}

{coloredtext("Нечетные", 36)} | сумма: {coloredtext(even, 33)}, количество игроков: {coloredtext(evencount, 33)}

{coloredtext("Делимые на девять", 36)} | сумма: {coloredtext(nines, 33)}, количество игроков: {coloredtext(ninescount, 33)}""")

    #Science isn't about WHY. It's about WHY NOT. Why is so much of our science dangerous? Why not marry safe science if you love it so much.
    #In fact, why not invent a special safety door that won't hit you on the butt on the way out, because you are fired.

    #Cave Johnson (Portal 2)

def t2():
    printcolor("""Пользователь вводит с клавиатуры длину линии и символ для заполнения линии. 
Нужно отобразить на экране вертикальную линию из введенного символа, 
указанной длины.""")
    
    sym = str(input("Ввeдите символ: "))
    repeats = getnumber("Длину змейки (желательно больше 20)")
    tmp = 1
    inc = -1
    for i in range(max(0, repeats)):
        print(" "*(tmp), end="")
        if not i%5:
            inc *= -1
        tmp += inc
        printcolor(sym, random.randint(30, 37))
    print(" "*(tmp), end="")
    printcolor("._.", random.randint(30, 37),"")
    print("  <--- snak")

def t3():

    printcolor("""Пользователь вводит с клавиатуры числа. Если число больше нуля нужно 
вывести надпись «Число положительное», если меньше нуля, то вывести «Число 
отрицательное», если равно нулю, то вывести «Число равно нулю». Когда 
пользователь вводит число 7 программа прекращает свою работу и выводит на 
экран надпись «Goodbye».""")
    
    num = getnumber("число")
    msg = ""
    while num != 7:
        if num > 0:
            msg = "положительное"
        elif num < 0:
            msg = "отрицательное"
        else:
            msg = "равно нулю"
        print("Число " + msg)
        num = getnumber("новое число (только не 7, я его боюсь ^_^")
    
    printcolor("AAAAH number 7 is my only fear! I hate you! Goodbye 😡😡😡",31)

def t4():
    printcolor("""Пользователь вводит с клавиатуры числа. Программа должна подсчитывать 
сумму, максимум и минимум введенных чисел. Когда пользователь вводит число 7 
программа прекращает свою работу и выводит на экран надпись «Goodbye». 
Число 7 не учитывать в подсчетах!""")
    
    # Why computer afraid of 7? Is he stupid? Is there any lore reasone?
    
    numbers = []
    num = getnumber("число")
    while num != 7:
        numbers.append(num)
        print(f"""\nFunne statz:
              
Min number: {coloredtext(min(numbers), 33)}
Max number: {coloredtext(max(numbers), 33)}
Sum: {coloredtext(sum(numbers), 33)}""")
        
        num = getnumber("еще одно число (только не 7 😭)")

    printcolor("ОПЯТЬ ТЫ ВВЕЛ 7? ТЕПЕРЬ ЭТО ТОЧНО КОНЕЦ, Я БОЛЬШЕ НЕ ХОЧУ ТЕБЯ ВИДЕТЬ! Goodbye 😡😡🤬",31)
    printcolor(f"Farewell, {coloredtext(os.getlogin(), 33)}.", 31)
    exit()

    

########

cycletasks(4)