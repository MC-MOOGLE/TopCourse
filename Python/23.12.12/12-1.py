import webbrowser
import random
import gradio as gr

def getTask(filePath):
    if len(filePath) < 256: # Ломаем рекурсию
        try:
            with open(filePath, "r", encoding="utf-8") as f:
                if f:
                    text = f.read()
                    return text
        except FileNotFoundError as er:
            print(er)
            return getTask(f"Python\\23.12.12\\{filePath}") # Почему-то в консоли и в интопретаторе, нужно указывать разный относительный путь
    
lists = []
listSorts = ["элементы из всех списков", "элементы из всех списков без повторений значений", "элементы, являющиеся общими для всех списков", "только уникальные элементы каждого из списков", "только минимальное и максимальное значение каждого из списков"]

def prettyLists(listOfLists):
    msg = ""
    for i in listOfLists:
        msg += f"{i}\n\n"
    return msg

def generateLists(nLists, whichShow):
    global lists
    lists = [[random.randint(-10, 10) for _ in range(10)] for _ in range(nLists)]
    
    return prettyLists(lists), t1(whichShow)

def t1(whichShow):
    global lists
    msg = ""
    for i in whichShow:
        tmplist = []
        indx = listSorts.index(i)

        match indx:
            case 0:
                for l in lists:
                    tmplist += l
            case 1:
                for l in lists:
                    for s in l:
                        if not s in tmplist:
                            tmplist.append(s)
            case 2:
                for l in lists:
                    for s in l:
                        if not s in tmplist:
                            def testIfInAllLists():
                                for testedList in lists:
                                    if not s in testedList:
                                        return False
                                return True
                            
                            if testIfInAllLists():
                                tmplist.append(s)

            case 3:
                for l in lists:
                    for s in l:
                        if not s in tmplist:
                            def testIfInAllLists():
                                for testedList in lists:
                                    if s in testedList and testedList != l:
                                        return False
                                return True
                            
                            if testIfInAllLists():
                                tmplist.append(s)
            
            case 4:
                for l in lists:
                    tmplist.append(min(l))
                    tmplist.append(max(l))
        
        msg += str(f"Список содержащий {i}: {tmplist}\n\n")

    return msg

with gr.Blocks(theme="soft") as mainInterface:
    with gr.Tab("Задание 1"):
        with gr.Row():
            with gr.Column(scale=2):
                with gr.Row():
                    with gr.Column():
                        listsTextbox = gr.TextArea(label="Списки", value=generateLists(2, [])[0])
                        nLists = gr.Slider(2, 10, 2, step=1, label="Кол-во списков")
                        regenerate = gr.Button("Генерировать")

                    with gr.Column():
                        output = gr.TextArea(label="Вывод")
                        whichShow = gr.CheckboxGroup(listSorts, label="Сгенерировать список, содержащий")
                regenerate.click(
                    generateLists,
                    [nLists, whichShow],
                    [listsTextbox, output]
                )
                whichShow.input(
                    t1,
                    inputs=whichShow,
                    outputs=output
                )
            with gr.Column():
                task = gr.TextArea(label="Задание:", value=getTask("12-1.txt"), max_lines=40)

if __name__ == "__main__": # На будующее
    webbrowser.open("http://127.0.0.1:7860/")
    mainInterface.launch()