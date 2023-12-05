import webbrowser
import gradio as gr
# Я не шутил насчет фронтенда. 
# Документация: https://github.com/gradio-app/gradio 
# Установка: pip install gradio
# Если не будет работать, или что-нибудь не устроит, напишите мне, я переделаю все под консоль (Но лучше так делать не надо)
# Да, готовое решение, но я ж не веб-дизайнер
# P.s Решение домашки не меняется, кроме ввода инпутов

def t1(textInput:str):
    processedText = str(textInput.replace(" ", "")).lower()
    if processedText[::-1] == processedText:
        return "Это палиндром"
    else:
        return "Это не палиндром"
    
def t2(text, origText):
    wordsToFind = text.split()
    origTextLow = origText.lower()
    for word in wordsToFind:
        for i in range(len(origTextLow)):
            word = word.lower()
            if origTextLow.startswith(word, i):
                origText = origText[:i:] + origText[i:(i+len(word))].upper() + origText[(i+len(word))::]
    return origText
                
def t3(text:str):
    text = text.replace(" ", "")
    splitText = [text]
    for sep in [".", "!", "?"]:
        tempText = []
        for textChunk in splitText:
            if textChunk: # Вроде как не обязательная проверка, но я боюсь ее убирать
                tempText += textChunk.split(sep)
        splitText = tempText
    totalSentenses = 0
    for i in splitText:
        if i:
            totalSentenses += 1
    return totalSentenses

# Чтобы не мешались в коде

task1 = """Пользователь вводит с клавиатуры строку. Необходимо проверить, является ли
введенная строка палиндромом.
Для справки: палиндромом является слово или текст, которое читается одинаково
слева направо и справа налево. Например:
«кок»
«А роза упала на лапу Азора»
«доход»
«А буду я у дуба»
Учтите, что палиндромы – регистронезависимые, т.е. все символы исходного 
текста необходимо анализировать либо в нижнем, либо в верхнем регистре. Для 
удобства можно исходный текст перевести в верхний либо нижний регистр.
Учтите, что палиндромы не зависят от пробелов, т.е. при анализе необходимо 
либо избавиться от пробелов в исходном тексте, либо пропускать их."""

task2 = """Пользователь вводит с клавиатуры некоторый текст, после чего вводит список 
зарезервированных слов. Необходимо найти в тексте все зарезервированные 
слова и изменить их регистр на верхний. Вывести на экран измененный текст.
Пример:
«Мама мыла мылом раму»
[‘мыла’, ‘мыло’]
Результат:
«Мама МЫЛа МЫЛОм раму»"""

task3 = """Дан некоторый текст. Необходимо посчитать в этом тексте количество 
предложений и вывести на экран полученный результат.
Учтите, что несколько подряд стоящих знаков пунктуации (многоточие, три 
восклицательных знака, вопросительный и восклицательный знаки и пр.) не 
образуют несколько предложений."""

# Все что находится ниже - по сути хтмл разметка с готовыми блоками

with gr.Blocks() as mainInterface:
    with gr.Tab("Задание 1"):
        with gr.Row():
            with gr.Column():
                gr.Interface(
                    t1,
                    [gr.Textbox(label="Поле ввода")],
                    [gr.TextArea(label="Output", max_lines=1, lines=1)],
                    examples=["кок", "А роза упала на лапу Азора", "доход", "А буду я у дуба"],
                    allow_flagging='never'
                )
            with gr.Column():
                task = gr.TextArea(label="Задание:",value="")
                task.value = task1

    with gr.Tab("Задание 2"):
        with gr.Row():
            with gr.Column():
                textToCheck = gr.Textbox(label="Предложение", lines=2)
                findWords = gr.Textbox(label="Слова для поиска (Через пробел)") 
                output = gr.TextArea(label="Output", lines=2)

                examples = gr.Examples([["Мама мыла мылом раму", "мыла мыло"], ["Добры бобры идут в боры", "РЫ бо"], ["Купи кипу пик. Кипу пик купи. Пик кипу купи.", "кип куп пик"]], [textToCheck, findWords])

                gr.on([findWords.change, findWords.submit, findWords.input, textToCheck.change], t2, [findWords, textToCheck], output)
            with gr.Column():
                task = gr.TextArea(label="Задание:",value="")
                task.value = task2

    with gr.Tab("Задание 3"):
        with gr.Row():
            with gr.Column():
                textToCheck = gr.Textbox(label="Текст", lines=8)
                output = gr.TextArea(label="Output", lines=1)

                examples = gr.Examples(["Я... не знаю какой пример привести. Что бы написать!?", "1-е предложение. 2-е предложение... 3-е предложение! 4-е предложение!!! 5-е предложение? 6-е предложение?! 7-е предложение.!?. 8-е предложение??? 9-е предложение, все еще 9-е предложение! 10-е предложение."], [textToCheck])

                gr.on([textToCheck.change, textToCheck.submit], t3, [textToCheck], output)
            with gr.Column():
                task = gr.TextArea(label="Задание:",value="")
                task.value = task3
            
if __name__ == "__main__": # На будующее
    webbrowser.open("http://127.0.0.1:7860/")
    mainInterface.launch()
