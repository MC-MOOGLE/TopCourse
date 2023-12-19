import random
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
            print(error)
            md.printcolor("Выход", "red")
            break

########################
        
tasks = [

"""Пользователь вводит с клавиатуры арифметическое выражение.
Например, «23+12». Необходимо вывести на экран результат выражения.
В примере выше это «35». Арифметическое выражение может состоять только из трёх частей:
число, операция, число. Возможные операции: +, -,*,/.""",

"""В списке целых, заполненном случайными числами, определить минимальный и максимальный элементы,
посчитать количество отрицательных элементов, посчитать количество положительных элементов,
посчитать количество нулей. Результаты вывести на экран. Список генерировать на 10 элементов,
значения списка от -10 до 10."""]

########################
        

def parseExpression(expression:str):
    numbers = []
    operators = []
    expression = expression.replace(" ", "")

    for i in range(len(expression)):
        if expression[i].isdigit():
            number = ""
            while i < len(expression) and expression[i].isdigit():
                number += expression[i]
                i += 1
            numbers.append(int(number))
        elif expression[i] in "+-*/":
            operators.append(expression[i])
        else:
            raise ValueError("Некорректное выражение")

    return numbers, operators
        
def t1():
    print(tasks[0])
    expression = str(input("Введите алгебраическое выражение: "))
    numbers, operators = parseExpression(expression)
    result = numbers[0]
    for i in range(len(operators)):
      match operators[i]: # Я не сделал порядок действий, так как отбой, а домашку надо сделать до завтра, но в задании не говорилось, что нужно соблютать порядок действий
          case "+":
              result += numbers[i + 1]
          case "-":
              result -= numbers[i + 1]
          case "*":
              result *= numbers[i + 1]
          case "/":
              result /= numbers[i + 1]

    print(expression, "=", result)

def t2():
    print(tasks[1])
    numbers = [random.randint(-10, 10) for i in range(10)]

    minNumber = min(numbers)
    maxNumber = max(numbers)
    negatives = len([i for i in numbers if i < 0])
    positives = len([i for i in numbers if i > 0])
    zeros = len([i for i in numbers if i == 0])

    print("\n\n")
    print(f"Список: {numbers}")
    print("Минимальный элемент:", minNumber)
    print("Максимальный элемент:", maxNumber)
    print("Количество отрицательных элементов:", negatives)
    print("Количество положительных элементов:", positives)
    print("Количество нулей:", zeros)

cycletasks(2)