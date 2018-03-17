[![Build Status](https://travis-ci.org/DmitrichevNick/PPHoareSort.svg?branch=master)](https://travis-ci.org/DmitrichevNick/PPHoareSort)

# PPHoareSort

# Сортировка хоара со слиянием "Разделяй и влавствуй"

## Структура

|---- build  
|
|---- images   
|  
|---- src  
|     |---- checker_  
|     |---- generator_ 
|     |---- solver_ 
|     |---- typerANDviewer      
|  
|---- tests

### В папках `src`, `tests` находятся свои README.md

### genTests.bat 

Создает папку `tests`.
Чтобы скрипт выполнился, в той же папке, где он запускается, должны лежать файлы `generator.exe` и `solver.exe`.
Генерирует 15 тестов и дает имена начиная с `0`, максимальное генерируемое количество тестов за один проход `20`, если поменять `15` на `20` в скрипте.
Тесты перемещаются в папку `tests`
