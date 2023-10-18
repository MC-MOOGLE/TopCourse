def getnumber(msg:str) -> int:
    IsFound = False
    while not IsFound:
        try:
            num = input("Введите " + msg)
            float(num)
            IsFound = True
            return float(num)
        except ValueError:
            print("Вы ввели неправильный тип данных. Попробуйте снова.")


def printcolor(string:str, code:int):
    print(f"\033[{code}m{string}\033[0m")


def checksym(n1:float, n2:float, n3:float) -> str:
    print("\n")
    printcolor("Сумма чисел: +", 32)
    printcolor("Произведение чисел: *", 32)
    printcolor("Максимальное число: max | ^", 32)
    printcolor("Минимальное число: min | v", 32)
    printcolor("Среднее чисел: avg | =/ | 💀 | (┬┬﹏┬┬)", 32)
    sym = str(input("Введите действие из списка: "))
    result = float
    match sym:
        case "+":
            result = n1 + n2 + n3
        case "*":
            result = n1 * n2 * n3
        case "max" | "^":
            result = max(n1, n2, n3)
        case "min" | "v":
            result = min(n1, n2, n3)
        case "avg" | "=/" | "💀" | "(┬┬﹏┬┬)":
            result = (n1 + n2 + n3) / 3
        case _:
            print("\n")
            printcolor("Данного действия нет в списке, выберите другое", 38)
            checksym(n1, n2, n3)
    return str(result)

def convertm(m):
    print("\n")
    printcolor("Перевести в мили: miles", 32)
    printcolor("Перевести в дюймы: inches", 32)
    printcolor("Перевести в ярды: yards", 32)
    conv = str(input("Введите действие из списка: "))
    result = float
    match conv:
        case "miles":
            result = m / 1609
        case "inches":
            result = m * 39.37
        case "yards":
            result = m * 1.094
        case _:
            print("\n")
            printcolor("Данного действия нет в списке, выберите другое", 38)
            convertm(m)
    return str(result) + " " + conv
            

def t1():
    printcolor("Задание 1. Пользователь вводит с клавиатуры три числа. В зависимости от выбора пользователя программа выводит на экран сумму трех чисел или произведение трех чисел.", 33)
    printcolor("Я не совсем понял зачем делить это задание на два, так что я объединю их", 35)
    printcolor("Задание 2. ... программа выводит на экран максимум из трех, минимум из трех или среднеарифметическое трех чисел.", 33)
    printcolor("Результат: " + checksym(getnumber("первое число: "), getnumber("второе число: "), getnumber("третье число: ")), 34)

def t2():
    printcolor("Пользователь вводит с клавиатуры количество метров. В зависимости от выбора пользователя программа переводит метры в мили, дюймы или ярды.", 33)
    meters = convertm(getnumber("количество метров: "))
    printcolor(f"Результат: {meters}", 34)

while True:
    task = getnumber("номер задания. Доступные задания: 1, 2 ; Для выхода введите 0: ")
    if task == 1:
        t1()
    elif task == 2:
        t2()
    elif task == 0:
        break    
    print("\n\n")
    

