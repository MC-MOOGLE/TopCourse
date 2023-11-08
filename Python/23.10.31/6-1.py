# Функции (может быть когда-нибудь вынесу в модуль)

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


def printcolor(string:str, code:int=34, end="\n"):
    print(f"\033[{code}m{string}\033[0m")

def allcolors():
    print("bro forgor again 💀")
    for i in range(30, 37):
        printcolor(i, i)

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
        except:
            printcolor("Выход", 31)
            break

def t1():
    printcolor("""Пользователь вводит с клавиатуры число в диапазоне от 1 до 100. Если число 
кратно 3 (делится на 3 без остатка), то нужно вывести на экран слово «Fizz». Если 
число кратно 5, то нужно вывести на экран слово «Buzz». Если число кратно и 3, и 
5, то нужно вывести на экран «Fizz Buzz». Если число не кратно ни 3, ни 5, то 
нужно вывести на экран само число.
Если пользователь ввел значение не в диапазоне от 1 до 100, требуется вывести 
сообщение об ошибке.""")
    msg = ""
    num = getnumber("число для проверки на делимость")
    if num < 1 or num > 100:
        printcolor(f"К вашему сведению, {num} не входит в диапозон от 1 до 100",31)
    else:
        if not num % 3 and not num % 5:
            msg = "Fizz Buzz"
        elif not num % 3:
            msg = "Fizz"
        elif not num % 5:
            msg = "Buzz"
        else:
            msg = num
        printcolor(msg, 33)
    
def t2():
    printcolor("""Написать программу, которая по выбору пользователя возводит введенное им 
число в степень от 0 до 7 включительно.
Если пользователь выбрал степень вне диапазона от 0 до 7, требуется вывести 
сообщение об ошибке.""")
    num = getnumber("число для возведения в степень")
    power = getnumber("степень числа от 0 до 7")
    if power < 0 or power > 7:
        printcolor(f"К вашему сведению, {power} не входит в диапозон от 0 до 7",31)
    else:
        printcolor(f"Результат: {num**power}",33)

def t3():
    printcolor("""Написать программу подсчета стоимости разговора для разных мобильных 
операторов. Пользователь вводит стоимость разговора и выбирает с какого на 
какой оператор он звонит. Вывести стоимость на экран.""")
    print("""В задании не написано как высчитывать итоговую стоимость.
Может быть следовало приложить таблицу с операторами и стоимостями,
я 4 раза задание прочитал, так и не понял что от меня требовалось.\n""")
    basecost = getnumber("базовую стоимость разговора")
    operators = ["Beeline", "Megafon", "MTS", "Tele2", "Yota"]
    operatorsstr = ""
    for i in operators:
        operatorsstr += f"{i} "
    printcolor("Комиссии: ", 35)
    for i in range(0, len(operators)):
        for j in range(0 + i, len(operators)):
            print(f"{operators[i]} - {operators[j]}: {max(0, 100 * (abs(i - j) / 5))}%")
    printcolor(f"Доступные операторы: {operatorsstr}")
    o1 = str(input("Ваш оператор: "))
    o2 = str(input("Оператор собеседника: "))
    ind = []
    for i in [o1, o2]:
        try:
            ind.append(operators.index(i))
            comission = max(ind) - min(ind)
            printcolor(f"Итоговая стоимость: {basecost + (basecost * (comission / 5))}")
        except:
            printcolor("Такого оператора нет",31)

def t4():
    printcolor("""Зарплата менеджера составляет $200 + процент от продаж: продажи до $500 – 
3%, от $500 до $1000 – 5%, свыше $1000 – 8%. Пользователь вводит с 
клавиатуры уровень продаж для трех менеджеров. Необходимо определить:
Зарплату каждого менеджера
Лучшего менеджера (выполнившего больше продаж в $)
Лучшему менеджеру выписать премию $200.
Вывести итоговые зарплаты каждого менеджера на экран.""")
    managers = []
    for i in range(3):
        sellvolume = getnumber(f"сумму продаж {i+1} менеджера")
        percent = 1.03
        # if sellvolume > 500:
        #     sum += 500 * 1.03
        #     sellvolume -= 500
        # else:
        #     sum += sellvolume * 1.03
        #     sellvolume = 0
        
        # if sellvolume > 500:
        #     sum += 500 * 1.05
        #     sellvolume -= 500
        # else:
        #     sum += sellvolume * 1.05
        #     sellvolume = 0
        
        # sum += sellvolume * 1.08

        if sellvolume >= 1000:
            percent = 1.08
        elif sellvolume >= 500:
            percent = 1.05
        sellvolume *= percent
        sellvolume += 200
        managers.append(sellvolume)
    print(max(managers))
    managers[managers.index(max(managers))] += 200
    maximum = managers[managers.index(max(managers))]
    for i in managers:
        cid = 37
        if i == maximum:
            cid = 32
        printcolor(f"{managers.index(i) + 1} менеджер: {i}", cid)

cycletasks(4)