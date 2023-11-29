import webbrowser

"""Я знаю, что мы должны были решать это через циклы for и условия, но я не хотел тратить час на ручной труд,
поэтому потратил 4 часа на автоматизацию, которая не способна вывести заданный нам пример в задании 👍"""

matrix = {"а": [1,1,1,
                0,1,1,
                0,0,1],

        "б":    [1,0,0,
                 1,1,0,
                 1,1,1],

        "в":    [1,1,1,
                 0,1,0,
                 0,0,0],
        
        "г":    [0,0,0,
                 0,1,0,
                 1,1,1],

        "д":     [1,1,1,
                  0,1,0,
                  1,1,1],

        "е":    [1,0,1,
                 1,1,1,
                 1,0,1],

        "ж":     [1,0,0,
                 1,1,0,
                 1,0,0],

        "з":    [0,0,1,
                 0,1,1,
                 0,0,1],

        "и":    [1,1,1,
                1,1,0,
                1,0,0],
                
        "к":     [0,0,1,
                  0,1,1,
                  1,1,1]}

def printsquare(leng, squrei):
    if leng < 3:
        leng = 3
    localmatrix = matrix[squrei]
    tile = int(leng/3) # Т. к я использую матрицы 3х3, число всегда будет округлятся к близжайшему числу / 3
    for row in range(3):
        a = row * 3
        for i in range(tile):
            u = d = l = r = 0
            for j in range(3):
                indx = a + j
                grad = 1
                mirror = False
                sidemirror = False
                center = False

                # Находим соседей
                if indx > 2:
                    u = localmatrix[indx - 3]
                if indx < 6:
                    d = localmatrix[indx + 3]
                if indx and indx != 3 and indx != 6:
                    l = localmatrix[indx - 1] 
                if indx != 2 and indx != 5 and indx != 8:
                    r = localmatrix[indx + 1]

                # Формулы треугольника (подбирал методом тыка)
                if d and not u:
                    if l and not r or r and not l:
                        grad = (i + 1) / tile
                elif u and not d:
                    if l and not r or r and not l:
                        grad = 1 - (i / tile)

                # Зеркалим, если надо
                if l and not r:
                    mirror = False
                else:
                    mirror = True

                # Исключения для угловых

                # Заполенные угловые
                if indx == 0 and d and r:
                    grad = 1
                elif indx == 2 and d and l:
                    grad = 1 # Не хочу писать длинные условия, мне проще ctrl c v сделать
                elif indx == 6 and u and r:
                    grad = 1
                elif indx == 8 and u and l:
                    grad = 1

                # Углоыве под наклоном
                if indx == 0 and d and not r:
                    grad = (i + 1) / tile
                    mirror = False
                elif indx == 2 and d and not l:
                    pass
                elif indx == 6 and u and not r:
                    grad = 1 - (i / tile)
                    mirror = False
                elif indx == 8 and u and not l:
                    pass

                if indx == 0 and not d and r:
                    grad = 1 - (i / tile)
                elif indx == 2 and not d and l:
                    grad = 1 - (i / tile)
                    mirror = False
                elif indx == 6 and not u and r:
                    grad = (i + 1) / tile
                    mirror = True
                elif indx == 8 and not u and l:
                    grad = (i + 1) / tile
                    mirror = False


                # Исключения для центральных

                if indx == 4:

                    # Исключение для одиночных центральных

                    if u and not (d or l or r):
                        grad = 1 - (i / tile)
                        center = True
                    elif d and not (u or l or r):
                        grad = (i + 1) / tile
                        center = True
                    elif l and not (u or d or r):
                        if i / tile <= 0.5:
                            grad = (i + 1) / tile
                        else:
                            grad = 1 - (i / tile)
                    elif r and not (u or d or l):
                        if i / tile <= 0.5:
                            grad = (i + 1) / tile
                        else:
                            grad = 1 - (i / tile)
                    
                    # Исключения для зеркальных центральных

                    if u and d and not (l or r):
                        if i / tile >= 0.5:
                            grad = (i + 1) / tile
                        else:
                            grad = 1 - (i / tile)
                        center = True
                    elif r and l and not (u or d):
                        if i / tile >= 0.5:
                            grad = 1 - (i / tile)  
                        else:
                            grad = (i + 1) / tile
                        center = True
                        center = True
                        sidemirror = True

                # Определяем кол-во точек и пробелов
                dots = int(((localmatrix[indx]) * tile * (grad + 0.001)))  # (grad - 0.001) используется из-за неточности плавающей точки, он 0.99999998 округляет до 0
                spaces = min((int(int(not (localmatrix[indx])) * tile + tile * (1 - (grad - 0.001)))), tile) # Min, чтобы не вылазил за пределы
                # В зависимости от того, в какую сторону скос треугольника, используются разные принты
                if not center:
                    if not mirror:
                        print(f'{"* " * dots}{"  " * spaces}', end="")
                    else:
                        print(f'{"  " * spaces}{"* " * dots}', end="") 
                else:
                    # Исключение для зеркализации по горизонтали
                    if sidemirror:
                        if dots * 2 <= tile:
                            print(f'{"* " * dots}', end="")
                        else:
                            print(f'{"* " * (dots - 1)}', end="")
                        print(f'{"  " * int(spaces - dots)}{"* " * dots}', end="") 
                    else:
                        print(f'{"  " * spaces}{"* " * int(dots - spaces)}', end="") 
                                        
            print()


# for i in range(1, 20, 3):
#     for j in ["а", "б", "в", "г", "д", "е", "ж", "з", "и", "к"]:
#         printsquare(i, j)
#         print("\n")

# Я решил не использовать свой модуль ради одной функции
side = int(input(f"""Введите размер квадрата
\033[31m{("Значение округлится в меньшую сторону до числа, делящегося на 3")}\033[0m: """))
if str(input("Открыть таблицу квадратов (не корней)? y/n: ")).lower() == "y":
    webbrowser.open("https://github.com/MC-MOOGLE/TopCourse/blob/main/Python/23.11.21/Squares.png")
while True:
    figure = str(input("""Введите номер фигуры
Для выхода введите любое другое значение: """))
    if figure in ["а", "б", "в", "г", "д", "е", "ж", "з", "и", "к"]:
        printsquare(side, figure)
    else:
        break
    side = int(input(f"Введите размер квадрата:")) # Вынес отдельно, так как предупреждение надоедливое
