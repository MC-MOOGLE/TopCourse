import webbrowser
import sys
from pathlib import Path
sys.path.append(str(Path(__file__).parent.parent))
from CustomModule import mmodule as md

#Я знаю, что мы должны были решать это через циклы for, но я не хотел тратить час на ручной труд,
#поэтому потратил 4 часа на автоматизацию, которая не способна вывести заданный нам пример в задании 👍

# ɴᴏᴡ ᴘʟᴀʏɪɴɢ: Im in Spain, but p is silent ───────────⚪────── ◄◄⠀▐▐ ⠀►► 5:12/ 96:𝟻𝟼 ───○ 🔊⠀ ᴴᴰ ⚙️

def drawsquare(size, id):
    global layer
    print(id + ".)\n")
    match id:
        case "а" | "f":
            for layer in range(size):
                print("  " * layer, end="")
                print("* " * (size - layer))

        case "б" | ",":
            for layer in range(size):
                print("* " * (layer + 1))

        case "в" | "d":
            for layer in range(size):
                print("  " * layer, end="")
                print("* " * (size - (layer * 2)))

        case "г" | "u":
            for layer in range(int(size / 2)):
                print()
            if size % 2:
                print("  " * int(size / 2), end="")
                print("*")
            for layer in range(int(size / 2), 0, -1):
                layer -= 1
                print("  " * layer, end="")
                print("* " * (size - (layer * 2)))

        case "д" | "l":
            for layer in range(int(size / 2)):
                print("  " * layer, end="")
                print("* " * (size - (layer * 2)))
            if size % 2:
                print("  " * int(size / 2), end="")
                print("*")
            for layer in range(int(size / 2), 0, -1):
                layer -= 1 # Очень тупой костыль, но я слишком сонный, чтобы что-то фиксить
                print("  " * layer, end="")
                print("* " * (size - (layer * 2)))

        case "е" | "t":
            for layer in range(1, int(size / 2) + 1):
                print("* " * layer, end="")
                print("  " * int((size - (layer * 2))), end="")
                print("* " * layer)
            if size % 2:
                print("* " * (layer * 2 + 1))
            for layer in range(int(size / 2), 0, -1):
                print("* " * layer, end="")
                print("  " * int((size - (layer * 2))), end="")
                print("* " * layer)
        
        case "ж" | ";":
            for layer in range(1, int(size / 2) + 1):
                print("* " * layer)
            if size % 2:
                print("* " * (layer + 1))
            for layer in range(int(size / 2), 0, -1):
                print("* " * layer)     

        case "з" | "p":
            for layer in range(1, int(size / 2) + 1):
                print("  " * (size - layer), end="")
                print("* " * layer)
            if size % 2:
                print("  " * (size - (layer + 1)), end="")
                print("* " * (layer + 1))
            for layer in range(int(size / 2), 0, -1):
                print("  " * (size - layer), end="")
                print("* " * layer)

        case "и" | "b":
            for layer in range(size):
                    print("* " * (size - layer))

        case "к" | "r":
            for layer in range(size):
                    print("  " * (size - layer), end="")
                    print("* " * (layer + 1))

        case _:
            md.printcolor("Такой фигуры нет! Выход!", "red")
            exit(666)       
                    
for i in range(20):
    for j in ["а", "б", "в", "г", "д", "е", "ж", "з", "и", "к"]:
        drawsquare(i, j)
    input(">")
if str(input("Открыть таблицу квадратов (не корней)? y/n: ")).lower() == "y":
     webbrowser.open("https://github.com/MC-MOOGLE/TopCourse/blob/main/Python/23.11.21/Squares.png")
print("Для выхода, введите любой несуществующий id")
while True:
    id = str(input("Введите id квадрата: "))
    drawsquare(md.getnumber("сторону квадрата"), id)

# А вот как делать не надо

# To be fair, you have to have a very high IQ to understand matrix method.
# The humour is extremely subtle, and without a solid grasp of theoretical physics
# most of the jokes will go over a typical reader’s head. There’s also this method nihilistic outlook,
# which is deftly woven into his characterisation- his personal philosophy draws heavily from Narodnaya Volya literature,
# for instance. The fans understand this stuff;
# they have the intellectual capacity to truly appreciate the depths of these jokes,
# to realise that they’re not just funny—they say something deep about LIFE.
# As a consequence people who dislike matrix method truly ARE idiots- of course they wouldn’t appreciate,
# for instance, the humour in Rick’s existential catchphrase “Т. к я использую матрицы 3х3, число всегда будет округлятся к ближайшему числу / 3”
# which itself is a cryptic reference to Turgenev’s Russian epic Fathers and Sons.
# I’m smirking right now just imagining one of those addlepated simpletons scratching their heads in confusion
# as My genius wit unfolds itself on their cmd screens.

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
                  1,1,1],
        
        "л":    ["MYLIVEISPAIN","MYLIVEISPAIN","MYLIVEISPAIN","MYLIVEISPAIN","MYLIVEISPAIN","MYLIVEISPAIN","MYLIVEISPAIN","MYLIVEISPAIN","MYLIVEISPAIN"]}

# 😂G̭̺̙͔̦̖̭E̞̫͙T͕͇😂̩̩̭̗O̝̗̯̖͍͙̬͎U̲͎͕̳͓̱̖̯T̤😂̞̮͓̙O͍͉̥̻̣̺̩̗F͔̜̻͙̥̱ͅ😂̦͖͚͚̺͚M͙Y̘😂͉̝̘̖̮̜H̱̬̲̯E̘̗̥̹͚͕ͅA̠̰̳͇̻̖͇̬D̩͍̩͔̭͓😂͖̹G̻̞̺̬͓̫͙͔E̻̫̙̞T̹̙̹😂̞͙͔̣̪̩O͙̪̹͙͈̪͖̘U͍͚̱͖T̫̫̝̰̝😂̫̤̥̱̖̳̜O͎̼͔͖̥̩F͇̫̳͔̝😂̬͉M͎̙̤̦̰̱͙Y̫̭̜͚̦͈̰😂͈̖̰͎͉H̳̳̬͔͙̲ͅͅE̻͇̹̬̰̜̖̱A͈̜D̜̣͕̫̯̻̝̭😂̰G̠̲͔̻͔̙̯E̯͚̙̘T̙̜͍̳̩̣͕̭😂̠̪̪͎̱O̹̰̺͙̘̪̭̞̱U̻̮͔͈̠ͅT̫͍͖̪̞͚😂͎̖̥͇O͕̩̯̠̹̜͖F̗͉͚͈̤😂̘̠͈̲̦͉̠M̝͈̰̥̹̗̯ͅY̻͕̳͔̠̟̼̙̣😂̜̗̩̼͓͖H̪͍̞͓̟̠̼̻E̥̰͕̳̣͉̪̭A͔D̗̮😂͔̜̜͙̤̹̩G̗̤͙̩̤̳E̜̗̥̼̲̺T̫͇̞̺̞😂̭̩̦̹̹̭O̭̯͉̫͎̻̮U̮͇͇͔̗T̞̭̦̼̗̹😂̜̪͖͍O̰͓͎̘̜̙͕F̞̝̖😂̩̟͖̭͍̦M̺̖̙̺Y͙̫̤̺̠̰😂̞̫̩H̖̤͍̣͔̟ͅE̞̹̞̗̭̳Ḁ̗͚͔͖D͓͇̱͍̖͙ͅ😂͈̳G̟̫̣͎̞͖͔͇Ẹ̘̦̭ͅT̩̻͎̹͓̭😂̺̦̞͔̫̟O̫U̪̪̩T͉̻̰͎̙̹̣̯😂͍̲̰̟O̞̬͚̻̞̹̪̳ͅF͚͓̤͓͕̱͖😂̦̟̣̖͇̦͕̞M͍̬͚̠̪̙Y̖̮̟̜̗̻̺😂̪H̬̝̬̼̫̺̗̦E͈̱A͈̗̜͚̭̱͇̙ͅD̳̻😂G̭̺̙͔̦̖̭E̞̫͙T͕͇😂̩̩̭̗O̝̗̯̖͍͙̬͎U̲͎͕̳͓̱̖̯T̤😂̞̮͓̙O͍͉̥̻̣̺̩̗F͔̜̻͙̥̱ͅ😂̦͖͚͚̺͚M͙Y̘😂͉̝̘̖̮̜H̱̬̲̯E̘̗̥̹͚͕ͅA̠̰̳͇̻̖͇̬D̩͍̩͔̭͓😂͖̹G̻̞̺̬͓̫͙͔E̻̫̙̞T̹̙̹😂̞͙͔̣̪̩O͙̪̹͙͈̪͖̘U͍͚̱͖T̫̫̝̰̝😂̫̤̥̱̖̳̜O͎̼͔͖̥̩F͇̫̳͔̝😂̬͉M͎̙̤̦̰̱͙Y̫̭̜͚̦͈̰😂͈̖̰͎͉H̳̳̬͔͙̲ͅͅE̻͇̹̬̰̜̖̱A͈̜D̜̣͕̫̯̻̝̭😂̰G̠̲͔̻͔̙̯E̯͚̙̘T̙̜͍̳̩̣͕̭😂̠̪̪͎̱O̹̰̺͙̘̪̭̞̱U̻̮͔͈̠ͅT̫͍͖̪̞͚😂͎̖̥͇O͕̩̯̠̹̜͖F̗͉͚͈̤😂̘̠͈̲̦͉̠M̝͈̰̥̹̗̯ͅY̻͕̳͔̠̟̼̙̣😂̜̗̩̼͓͖H̪͍̞͓̟̠̼̻E̥̰͕̳̣͉̪̭A͔D̗̮😂͔̜̜͙̤̹̩G̗̤͙̩̤̳E̜̗̥̼̲̺T̫͇̞̺̞😂̭̩̦̹̹̭O̭̯͉̫͎̻̮U̮͇͇͔̗T̞̭̦̼̗̹😂̜̪͖͍O̰͓͎̘̜̙͕F̞̝̖😂̩̟͖̭͍̦M̺̖̙̺Y͙̫̤̺̠̰😂̞̫̩H̖̤͍̣͔̟ͅE̞̹̞̗̭̳Ḁ̗͚͔͖D͓͇̱͍̖͙ͅ😂͈̳G̟̫̣͎̞͖͔͇Ẹ̘̦̭ͅT̩̻͎̹͓̭😂̺̦̞͔̫̟O̫U̪̪̩T͉̻̰͎̙̹̣̯😂͍̲̰̟O̞̬͚̻̞̹̪̳ͅF͚͓̤͓͕̱͖😂̦̟̣̖͇̦͕̞M͍̬͚̠̪̙Y̖̮̟̜̗̻̺😂̪H̬̝̬̼̫̺̗̦E͈̱A͈̗̜͚̭̱͇̙ͅD̳̻😂G̭̺̙͔̦̖̭E̞̫͙T͕͇😂̩̩̭̗O̝̗̯̖͍͙̬͎U̲͎͕̳͓̱̖̯T̤😂̞̮͓̙O͍͉̥̻̣̺̩̗F͔̜̻͙̥̱ͅ😂̦͖͚͚̺͚M͙Y̘😂͉̝̘̖̮̜H̱̬̲̯E̘̗̥̹͚͕ͅA̠̰̳͇̻̖͇̬D̩͍̩͔̭͓😂͖̹G̻̞̺̬͓̫͙͔E̻̫̙̞T̹̙̹😂̞͙͔̣̪̩O͙̪̹͙͈̪͖̘U͍͚̱͖T̫̫̝̰̝😂̫̤̥̱̖̳̜O͎̼͔͖̥̩F͇̫̳͔̝😂̬͉M͎̙̤̦̰̱͙Y̫̭̜͚̦͈̰😂͈̖̰͎͉H̳̳̬͔͙̲ͅͅE̻͇̹̬̰̜̖̱A͈̜D̜̣͕̫̯̻̝̭😂̰G̠̲͔̻͔̙̯E̯͚̙̘T̙̜͍̳̩̣͕̭😂̠̪̪͎̱O̹̰̺͙̘̪̭̞̱U̻̮͔͈̠ͅT̫͍͖̪̞͚😂͎̖̥͇O͕̩̯̠̹̜͖F̗͉͚͈̤😂̘̠͈̲̦͉̠M̝͈̰̥̹̗̯ͅY̻͕̳͔̠̟̼̙̣😂̜̗̩̼͓͖H̪͍̞͓̟̠̼̻E̥̰͕̳̣͉̪̭A͔D̗̮😂͔̜̜͙̤̹̩G̗̤͙̩̤̳E̜̗̥̼̲̺T̫͇̞̺̞😂̭̩̦̹̹̭O̭̯͉̫͎̻̮U̮͇͇͔̗T̞̭̦̼̗̹😂̜̪͖͍O̰͓͎̘̜̙͕F̞̝̖😂̩̟͖̭͍̦M̺̖̙̺Y͙̫̤̺̠̰😂̞̫̩H̖̤͍̣͔̟ͅE̞̹̞̗̭̳Ḁ̗͚͔͖D͓͇̱͍̖͙ͅ😂͈̳G̟̫̣͎̞͖͔͇Ẹ̘̦̭ͅT̩̻͎̹͓̭😂̺̦̞͔̫̟O̫U̪̪̩T͉̻̰͎̙̹̣̯😂͍̲̰̟O̞̬͚̻̞̹̪̳ͅF͚͓̤͓͕̱͖😂̦̟̣̖͇̦͕̞M͍̬͚̠̪̙Y̖̮̟̜̗̻̺😂̪H̬̝̬̼̫̺̗̦E͈̱A͈̗̜͚̭̱͇̙ͅD̳̻😂G̭̺̙͔̦̖̭E̞̫͙T͕͇😂̩̩̭̗O̝̗̯̖͍͙̬͎U̲͎͕̳͓̱̖̯T̤😂̞̮͓̙O͍͉̥̻̣̺̩̗F͔̜̻͙̥̱ͅ😂̦͖͚͚̺͚M͙Y̘😂͉̝̘̖̮̜H̱̬̲̯E̘̗̥̹͚͕ͅA̠̰̳͇̻̖͇̬D̩͍̩͔̭͓😂͖̹G̻̞̺̬͓̫͙͔E̻̫̙̞T̹̙̹😂̞͙͔̣̪̩O͙̪̹͙͈̪͖̘U͍͚̱͖T̫̫̝̰̝😂̫̤̥̱̖̳̜O͎̼͔͖̥̩F͇̫̳͔̝😂̬͉M͎̙̤̦̰̱͙Y̫̭̜͚̦͈̰😂͈̖̰͎͉H̳̳̬͔͙̲ͅͅE̻͇̹̬̰̜̖̱A͈̜D̜̣͕̫̯̻̝̭😂̰G̠̲͔̻͔̙̯E̯͚̙̘T̙̜͍̳̩̣͕̭😂̠̪̪͎̱O̹̰̺͙̘̪̭̞̱U̻̮͔͈̠ͅT̫͍͖̪̞͚😂͎̖̥͇O͕̩̯̠̹̜͖F̗͉͚͈̤😂̘̠͈̲̦͉̠M̝͈̰̥̹̗̯ͅY̻͕̳͔̠̟̼̙̣😂̜̗̩̼͓͖H̪͍̞͓̟̠̼̻E̥̰͕̳̣͉̪̭A͔D̗̮😂͔̜̜͙̤̹̩G̗̤͙̩̤̳E̜̗̥̼̲̺T̫͇̞̺̞😂̭̩̦̹̹̭O̭̯͉̫͎̻̮U̮͇͇͔̗T̞̭̦̼̗̹😂̜̪͖͍O̰͓͎̘̜̙͕F̞̝̖😂̩̟͖̭͍̦M̺̖̙̺Y͙̫̤̺̠̰😂̞̫̩H̖̤͍̣͔̟ͅE̞̹̞̗̭̳Ḁ̗͚͔͖D͓͇̱͍̖͙ͅ😂͈̳G̟̫̣͎̞͖͔͇Ẹ̘̦̭ͅT̩̻͎̹͓̭😂̺̦̞͔̫̟O̫U̪̪̩T͉̻̰͎̙̹̣̯😂͍̲̰̟O̞̬͚̻̞̹̪̳ͅF͚͓̤͓͕̱͖😂̦̟̣̖͇̦͕̞M͍̬͚̠̪̙Y̖̮̟̜̗̻̺😂̪H̬̝̬̼̫̺̗̦E͈̱A͈̗̜͚̭̱͇̙ͅD̳̻😂G̭̺̙͔̦̖̭E̞̫͙T͕͇😂̩̩̭̗O̝̗̯̖͍͙̬͎U̲͎͕̳͓̱̖̯T̤😂̞̮͓̙O͍͉̥̻̣̺̩̗F͔̜̻͙̥̱ͅ😂̦͖͚͚̺͚M͙Y̘😂͉̝̘̖̮̜H̱̬̲̯E̘̗̥̹͚͕ͅA̠̰̳͇̻̖͇̬D̩͍̩͔̭͓😂͖̹G̻̞̺̬͓̫͙͔E̻̫̙̞T̹̙̹😂̞͙͔̣̪̩O͙̪̹͙͈̪͖̘U͍͚̱͖T̫̫̝̰̝😂̫̤̥̱̖̳̜O͎̼͔͖̥̩F͇̫̳͔̝😂̬͉M͎̙̤̦̰̱͙Y̫̭̜͚̦͈̰😂͈̖̰͎͉H̳̳̬͔͙̲ͅͅE̻͇̹̬̰̜̖̱A͈̜D̜̣͕̫̯̻̝̭😂̰G̠̲͔̻͔̙̯E̯͚̙̘T̙̜͍̳̩̣͕̭😂̠̪̪͎̱O̹̰̺͙̘̪̭̞̱U̻̮͔͈̠ͅT̫͍͖̪̞͚😂͎̖̥͇O͕̩̯̠̹̜͖F̗͉͚͈̤😂̘̠͈̲̦͉̠M̝͈̰̥̹̗̯ͅY̻͕̳͔̠̟̼̙̣😂̜̗̩̼͓͖H̪͍̞͓̟̠̼̻E̥̰͕̳̣͉̪̭A͔D̗̮😂͔̜̜͙̤̹̩G̗̤͙̩̤̳E̜̗̥̼̲̺T̫͇̞̺̞😂̭̩̦̹̹̭O̭̯͉̫͎̻̮U̮͇͇͔̗T̞̭̦̼̗̹😂̜̪͖͍O̰͓͎̘̜̙͕F̞̝̖😂̩̟͖̭͍̦M̺̖̙̺Y͙̫̤̺̠̰😂̞̫̩H̖̤͍̣͔̟ͅE̞̹̞̗̭̳Ḁ̗͚͔͖D͓͇̱͍̖͙ͅ😂͈̳G̟̫̣͎̞͖͔͇Ẹ̘̦̭ͅT̩̻͎̹͓̭😂̺̦̞͔̫̟O̫U̪̪̩T͉̻̰͎̙̹̣̯😂͍̲̰̟O̞̬͚̻̞̹̪̳ͅF͚͓̤͓͕̱͖😂̦̟̣̖͇̦͕̞M͍̬͚̠̪̙Y̖̮̟̜̗̻̺😂̪H̬̝̬̼̫̺̗̦E͈̱A͈̗̜͚̭̱͇̙ͅD̳̻😂G̭̺̙͔̦̖̭E̞̫͙T͕͇😂̩̩̭̗O̝̗̯̖͍͙̬͎U̲͎͕̳͓̱̖̯T̤😂̞̮͓̙O͍͉̥̻̣̺̩̗F͔̜̻͙̥̱ͅ😂̦͖͚͚̺͚M͙Y̘😂͉̝̘̖̮̜H̱̬̲̯E̘̗̥̹͚͕ͅA̠̰̳͇̻̖͇̬D̩͍̩͔̭͓😂͖̹G̻̞̺̬͓̫͙͔E̻̫̙̞T̹̙̹😂̞͙͔̣̪̩O͙̪̹͙͈̪͖̘U͍͚̱͖T̫̫̝̰̝😂̫̤̥̱̖̳̜O͎̼͔͖̥̩F͇̫̳͔̝😂̬͉M͎̙̤̦̰̱͙Y̫̭̜͚̦͈̰😂͈̖̰͎͉H̳̳̬͔͙̲ͅͅE̻͇̹̬̰̜̖̱A͈̜D̜̣͕̫̯̻̝̭😂̰G̠̲͔̻͔̙̯E̯͚̙̘T̙̜͍̳̩̣͕̭😂̠̪̪͎̱O̹̰̺͙̘̪̭̞̱U̻̮͔͈̠ͅT̫͍͖̪̞͚😂͎̖̥͇O͕̩̯̠̹̜͖F̗͉͚͈̤😂̘̠͈̲̦͉̠M̝͈̰̥̹̗̯ͅY̻͕̳͔̠̟̼̙̣😂̜̗̩̼͓͖H̪͍̞͓̟̠̼̻E̥̰͕̳̣͉̪̭A͔D̗̮😂͔̜̜͙̤̹̩G̗̤͙̩̤̳E̜̗̥̼̲̺T̫͇̞̺̞😂̭̩̦̹̹̭O̭̯͉̫͎̻̮U̮͇͇͔̗T̞̭̦̼̗̹😂̜̪͖͍O̰͓͎̘̜̙͕F̞̝̖😂̩̟͖̭͍̦M̺̖̙̺Y͙̫̤̺̠̰😂̞̫̩H̖̤͍̣͔̟ͅE̞̹̞̗̭̳Ḁ̗͚͔͖D͓͇̱͍̖͙ͅ😂͈̳G̟̫̣͎̞͖͔͇Ẹ̘̦̭ͅT̩̻͎̹͓̭😂̺̦̞͔̫̟O̫U̪̪̩T͉̻̰͎̙̹̣̯😂͍̲̰̟O̞̬͚̻̞̹̪̳ͅF͚͓̤͓͕̱͖😂̦̟̣̖͇̦͕̞M͍̬͚̠̪̙Y̖̮̟̜̗̻̺😂̪H̬̝̬̼̫̺̗̦E͈̱A͈̗̜͚̭̱͇̙ͅD̳̻😂G̭̺̙͔̦̖̭E̞̫͙T͕͇😂̩̩̭̗O̝̗̯̖͍͙̬͎U̲͎͕̳͓̱̖̯T̤😂̞̮͓̙O͍͉̥̻̣̺̩̗F͔̜̻͙̥̱ͅ😂̦͖͚͚̺͚M͙Y̘😂͉̝̘̖̮̜H̱̬̲̯E̘̗̥̹͚͕ͅA̠̰̳͇̻̖͇̬D̩͍̩͔̭͓😂͖̹G̻̞̺̬͓̫͙͔E̻̫̙̞T̹̙̹😂̞͙͔̣̪̩O͙̪̹͙͈̪͖̘U͍͚̱͖T̫̫̝̰̝😂̫̤̥̱̖̳̜O͎̼͔͖̥̩F͇̫̳͔̝😂̬͉M͎̙̤̦̰̱͙Y̫̭̜͚̦͈̰😂͈̖̰͎͉H̳̳̬͔͙̲ͅͅE̻͇̹̬̰̜̖̱A͈̜D̜̣͕̫̯̻̝̭😂̰G̠̲͔̻͔̙̯E̯͚̙̘T̙̜͍̳̩̣͕̭😂̠̪̪͎̱O̹̰̺͙̘̪̭̞̱U̻̮͔͈̠ͅT̫͍͖̪̞͚😂͎̖̥͇O͕̩̯̠̹̜͖F̗͉͚͈̤😂̘̠͈̲̦͉̠M̝͈̰̥̹̗̯ͅY̻͕̳͔̠̟̼̙̣😂̜̗̩̼͓͖H̪͍̞͓̟̠̼̻E̥̰͕̳̣͉̪̭A͔D̗̮😂͔̜̜͙̤̹̩G̗̤͙̩̤̳E̜̗̥̼̲̺T̫͇̞̺̞😂̭̩̦̹̹̭O̭̯͉̫͎̻̮U̮͇͇͔̗T̞̭̦̼̗̹😂̜̪͖͍O̰͓͎̘̜̙͕F̞̝̖😂̩̟͖̭͍̦M̺̖̙̺Y͙̫̤̺̠̰😂̞̫̩H̖̤͍̣͔̟ͅE̞̹̞̗̭̳Ḁ̗͚͔͖D͓͇̱͍̖͙ͅ😂͈̳G̟̫̣͎̞͖͔͇Ẹ̘̦̭ͅT̩̻͎̹͓̭😂̺̦̞͔̫̟O̫U̪̪̩T͉̻̰͎̙̹̣̯😂͍̲̰̟O̞̬͚̻̞̹̪̳ͅF͚͓̤͓͕̱͖😂̦̟̣̖͇̦͕̞M͍̬͚̠̪̙Y̖̮̟̜̗̻̺😂̪H̬̝̬̼̫̺̗̦E͈̱A͈̗̜͚̭̱͇̙ͅD̳̻😂G̭̺̙͔̦̖̭E̞̫͙T͕͇😂̩̩̭̗O̝̗̯̖͍͙̬͎U̲͎͕̳͓̱̖̯T̤😂̞̮͓̙O͍͉̥̻̣̺̩̗F͔̜̻͙̥̱ͅ😂̦͖͚͚̺͚M͙Y̘😂͉̝̘̖̮̜H̱̬̲̯E̘̗̥̹͚͕ͅA̠̰̳͇̻̖͇̬D̩͍̩͔̭͓😂͖̹G̻̞̺̬͓̫͙͔E̻̫̙̞T̹̙̹😂̞͙͔̣̪̩O͙̪̹͙͈̪͖̘U͍͚̱͖T̫̫̝̰̝😂̫̤̥̱̖̳̜O͎̼͔͖̥̩F͇̫̳͔̝😂̬͉M͎̙̤̦̰̱͙Y̫̭̜͚̦͈̰😂͈̖̰͎͉H̳̳̬͔͙̲ͅͅE̻͇̹̬̰̜̖̱A͈̜D̜̣͕̫̯̻̝̭😂̰G̠̲͔̻͔̙̯E̯͚̙̘T̙̜͍̳̩̣͕̭😂̠̪̪͎̱O̹̰̺͙̘̪̭̞̱U̻̮͔͈̠ͅT̫͍͖̪̞͚😂͎̖̥͇O͕̩̯̠̹̜͖F̗͉͚͈̤😂̘̠͈̲̦͉̠M̝͈̰̥̹̗̯ͅY̻͕̳͔̠̟̼̙̣😂̜̗̩̼͓͖H̪͍̞͓̟̠̼̻E̥̰͕̳̣͉̪̭A͔D̗̮😂͔̜̜͙̤̹̩G̗̤͙̩̤̳E̜̗̥̼̲̺T̫͇̞̺̞😂̭̩̦̹̹̭O̭̯͉̫͎̻̮U̮͇͇͔̗T̞̭̦̼̗̹😂̜̪͖͍O̰͓͎̘̜̙͕F̞̝̖😂̩̟͖̭͍̦M̺̖̙̺Y͙̫̤̺̠̰😂̞̫̩H̖̤͍̣͔̟ͅE̞̹̞̗̭̳Ḁ̗͚͔͖D͓͇̱͍̖͙ͅ😂͈̳G̟̫̣͎̞͖͔͇Ẹ̘̦̭ͅT̩̻͎̹͓̭😂̺̦̞͔̫̟O̫U̪̪̩T͉̻̰͎̙̹̣̯😂͍̲̰̟O̞̬͚̻̞̹̪̳ͅF͚͓̤͓͕̱͖😂̦̟̣̖͇̦͕̞M͍̬͚̠̪̙Y̖̮̟̜̗̻̺😂̪H̬̝̬̼̫̺̗̦E͈̱A͈̗̜͚̭̱͇̙ͅD̳̻😂G̭̺̙͔̦̖̭E̞̫͙T͕͇😂̩̩̭̗O̝̗̯̖͍͙̬͎U̲͎͕̳͓̱̖̯T̤😂̞̮͓̙O͍͉̥̻̣̺̩̗F͔̜̻͙̥̱ͅ😂̦͖͚͚̺͚M͙Y̘😂͉̝̘̖̮̜H̱̬̲̯E̘̗̥̹͚͕ͅA̠̰̳͇̻̖͇̬D̩͍̩͔̭͓😂͖̹G̻̞̺̬͓̫͙͔E̻̫̙̞T̹̙̹😂̞͙͔̣̪̩O͙̪̹͙͈̪͖̘U͍͚̱͖T̫̫̝̰̝😂̫̤̥̱̖̳̜O͎̼͔͖̥̩F͇̫̳͔̝😂̬͉M͎̙̤̦̰̱͙Y̫̭̜͚̦͈̰😂͈̖̰͎͉H̳̳̬͔͙̲ͅͅE̻͇̹̬̰̜̖̱A͈̜D̜̣͕̫̯̻̝̭😂̰G̠̲͔̻͔̙̯E̯͚̙̘T̙̜͍̳̩̣͕̭😂̠̪̪͎̱O̹̰̺͙̘̪̭̞̱U̻̮͔͈̠ͅT̫͍͖̪̞͚😂͎̖̥͇O͕̩̯̠̹̜͖F̗͉͚͈̤😂̘̠͈̲̦͉̠M̝͈̰̥̹̗̯ͅY̻͕̳͔̠̟̼̙̣😂̜̗̩̼͓͖H̪͍̞͓̟̠̼̻E̥̰͕̳̣͉̪̭A͔D̗̮😂͔̜̜͙̤̹̩G̗̤͙̩̤̳E̜̗̥̼̲̺T̫͇̞̺̞😂̭̩̦̹̹̭O̭̯͉̫͎̻̮U̮͇͇͔̗T̞̭̦̼̗̹😂̜̪͖͍O̰͓͎̘̜̙͕F̞̝̖😂̩̟͖̭͍̦M̺̖̙̺Y͙̫̤̺̠̰😂̞̫̩H̖̤͍̣͔̟ͅE̞̹̞̗̭̳Ḁ̗͚͔͖D͓͇̱͍̖͙ͅ😂͈̳G̟̫̣͎̞͖͔͇Ẹ̘̦̭ͅT̩̻͎̹͓̭😂̺̦̞͔̫̟O̫U̪̪̩T͉̻̰͎̙̹̣̯😂͍̲̰̟O̞̬͚̻̞̹̪̳ͅF͚͓̤͓͕̱͖😂̦̟̣̖͇̦͕̞M͍̬͚̠̪̙Y̖̮̟̜̗̻̺😂̪H̬̝̬̼̫̺̗̦E͈̱A͈̗̜͚̭̱͇̙ͅD̳̻

def printsquare(leng, squrei):
    if leng < 3:
        leng = 3
    localmatrix = matrix[squrei]
    tile = int(leng/3) # Т. к я использую матрицы 3х3, число всегда будет округлятся к ближайшему числу / 3

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
