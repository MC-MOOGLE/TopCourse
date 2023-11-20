import random
import os

# Functions #

def getnumber(msg:str="число", type:type=int) -> float:
    IsFound = False
    while not IsFound:
        try:
            num = input("Введите " + msg + ": ")
            type(num)
            IsFound = True
            return type(num)
        except ValueError:
            print("Вы ввели неправильный тип данных. Попробуйте снова.")


def getcolorcode(color):
    code = 30
    colors = ["black", "red", "green", "yellow", "blue", "magenta", "cyan"]
    color = color.lower()
    if colors.count(color):
        code += colors.index(color)
        return code
    else:
        print(f"Wrong color! Avaible colors: {colors}")
        return 39

def printcolor(string:str, color:str="blue", ends="\n"):
    code = getcolorcode(color)
    print(f"\033[{code}m{string}\033[0m", end=ends)

def color(string:str, color:str="blue"):
    code = getcolorcode(color)
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