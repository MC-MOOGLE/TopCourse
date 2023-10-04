# Функции
import itertools
import webbrowser

def getnumber(msg):
    IsFound = False
    while not IsFound:
        try:
          num = input("Введите " + msg)
          float(num)
          IsFound = True
          return num
        except ValueError:
            print("Вы ввели неправильный тип данных. Попробуйте снова.")
   
def printcolor(string, code):
    # Почему вы нам не рассказали про f-строки? Я теберь без них жить не смогу
    print(f"\033[{code}m{string}\033[0m")

# Задание 1
def t1():
    printcolor("Задание 1. Пользователь вводит с клавиатуры три числа. Необходимо найти сумму чисел и их произведение. Вывести результаты на экран.", 33)
    numbers = []

    for i in range(3):
        s = getnumber(str(i + 1) + "-е число: ")
        numbers.append(float(s))

    summ = sum(numbers)
    multiply = 1
    for n in numbers:
        multiply *= n

    printcolor(f"Сумма чисел равна {summ}", 35)
    printcolor(f"Произведение чисел равно {multiply}", 35)
# Задание 2
def t2():
    printcolor("Задание 2. Пользователь вводит с клавиатуры три числа. \n Первое число – зарплата за месяц, \n второе число – сумма месячного платежа по кредиту в банке, \n третье число – задолженность за коммунальные услуги. \nВывести на экран сумму, которая останется у пользователя после всех выплат.", 33)
    revenue = float(getnumber("зарплату: "))
    credit = float(getnumber("кредитную плату: "))
    debt = float(getnumber("задолженость: "))
    delta = revenue - credit - debt
    msg = f"У вас останется {delta}"
    if delta < 0:
        msg = f"Вы в долгу на {-delta}"
    printcolor(msg + " чего бы это не было", 35)

# Задание 3
def t3():
    printcolor("Задание 3. Написать программу, вычисляющую площадь ромба по длинам двух его диагоналей. Длины диагоналей вводятся с клавиатуры пользователем.", 33)
    d1 = float(getnumber("первую диагональ: "))
    d2 = float(getnumber("вторую диагональ: "))
    printcolor(f"Площадь ромба равна {(d1*d2)/2}", 35)

# Задание 4
def t4():
    printcolor("Вывести на экран надпись “To be or not to be” на разных строках. Отформатируйте строку, используя escape-последовательности ‘\\t’, ‘\\n’.", 33)
    printcolor("Понятия не имею как именно нужно отформатировать по заданию, так что перепробую все возможные варианты", 30)
    printcolor("ВНИМАНИЕ! Строки повторяются по два раза, так как \\t не играет никакой роли, если следующее слово все равно уезжает вниз, можете написать 1 в инпуте, чтобы убедится в этом", 31)
    print("Введите любой символ, чтобы продолжить", end=" ")
    tmp = input()
    symbols = ["\n", "\t"]
    if tmp == 1 or tmp == "1":
        symbols = ["\\n", "\\t"]
    text = "To be or not to be"
    parts = text.split()
    # - В пайтон походу для всего есть функции, никакого креатива *Я после того как убил 10 минут на создания этой функции вручную
    combinations = itertools.product(symbols, repeat=len(parts))
    for symbols in combinations:
        text = " ".join(itertools.chain(*zip(parts, symbols)))
        print(text)
        print("")
    Meme = getnumber("1 , если хотите мемчик (Откроется браузер)")
    if Meme == "1":
        webbrowser.open("https://raw.githubusercontent.com/MC-MOOGLE/TopCourse/main/Python/3.10/Do%20be%20do%20be%20do%20wah.jpg")
   
    

while True:
    printcolor("Доступные задания: 1,2,3,4", 32)
    task = getnumber("номер задания: ")
    task = float(task)
    if task == 1:
        t1()
    elif task == 2:
        t2()
    elif task == 3:
        t3()
    elif task == 4:
        t4()
    print("\n\n\n\n")


