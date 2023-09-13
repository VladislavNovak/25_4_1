## CMAKE

<details open>
<summary><span style="color: Tomato; font-size: 16px">Задание: Симулятор проведения операций</span></summary>
Реализуйте простой симулятор проведения медицинской операции у пациента. 
Пользователь выступает в роли хирурга, который запрашивает инструменты у ассистента 
и применяет их сообразно ситуации.

Пользователь взаимодействует с программой с помощью команд.
Команды не имеют сложной встроенной логики: они просто принимают нужные данные в качестве аргументов
и выводят сообщения в консоль о выполнении.
Данные команд — это одна или две двумерные точки в формате double с координатами X и Y соответственно.

Команда scalpel — принимает на вход две двумерные координаты начала и конца разреза или линии отсечения.
При выполнении в консоль выводится сообщение о том, что был сделан разрез между введёнными координатами.

Команда hemostat принимает на вход одну точку, в которой требуется сделать зажим, о чём также сообщает в консоль.

Команда tweezers — пинцет, как и зажим, принимает одну точку для применения. Сообщение об этом выводится в консоль.

Команда suture — хирургическая игла, которая делает шов между двумя указанными точками.

Операция всегда начинается с команды scalpel и заканчивается командой suture.
Для окончания работы программы их параметры-точки должны совпасть.

Программу требуется реализовать именно с помощью одного заголовочного файла и
одного файла с исходным кодом (CPP).
В заголовочном файле должны находиться функции-инструменты.
В основном файле — основная логика программы, обработка ввода пользователя.

<details><summary>
<span style="color:tomato; font-size: 12px">Советы и рекомендации</span></summary>
Создайте структуру с типом двумерной координаты (точки) вместе
с набором функций для ввода этой координаты из консоли,
её вывода в консоль и сравнения на предмет равенства.
Для этих целей удобнее всего создать ещё один заголовочный файл.

Обратите внимание на порядок команд.

Заголовочные файлы с расширением `.h` следует расположить в папке `include`.
Файлы исходного кода с расширением `.cpp` — в папке `src`.
</details>
</details>

<details>
<summary><span style="color: Tomato; font-size: 16px">CMAKE</span></summary>

<details>
<summary><span style="color: Tomato; font-size: 12px">Базовый:</span></summary>

Нужен для правильного склеивания файлов.

В корне создаётся основной файл CMakeLists.txt:

```cmake
cmake_minimum_required(VERSION 3.25)
project(FirstApp VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)

add_executable(FirstApp src/main.cpp)
```

`cmake_minimum_required` - указывается версия линкера cmake, который может разобрать файл

`project` - указывается наименование проекта; версия (мажорная_часть.минорная_часть.патч)

`set(CMAKE_CXX_STANDARD 17)` - даёт информацию, на какой версии компилятора собирается проект

`set` - создает переменные

`set(PROGRAM_PATH ${CMAKE_SOURCE_DIR}/include)` - создает пользовательскую переменную PROGRAM_PATH,
которая представляет путь до папки include
(если заголовочные файлы были перенесены или созданы в папке src).
Наименование может быть любым.

`CMAKE_SOURCE_DIR` - это предопределенная переменная, которая содержит путь к исходному каталогу верхнего уровня.

`add_executable` - первое наименование - это будет имя исполняемого файла. 
Последующие наименования - это то, из чего будет получаться исполняемый файл.

`target_include_directories` - нужен для подключения к проекту заголовочных файлов.
Для этого указываем наименование проекта, уровень доступа к нему (PUBLIC) и путь до папки include

`add_subdirectory` - добавляет в каталог поддиректории. 
В качестве аргумента получает папку с исполняемыми файлами
(если они были перенесены или созданы в папке src)

</details>
<details>
<summary><span style="color: Tomato; font-size: 12px">Вложенные CMAKE:</span></summary>

Проект может быть достаточно большим. 
Чтобы сделать проект масштабируемым и легко сопровождаемым, 
нужно разнести компоненты по соответствующим директориям. 
Заголовочные файлы переносятся в директорию include, а все исполняемые - в директорию src.

Например, в src будут находиться main.cpp и my_file.cpp (файл с различными функциями). 
А в include - my_file.h. В нём будут расположены объявления к my_file.cpp.

Тогда в include/my_file.h, для того, чтобы он в процессе линковки включался лишь один раз, в самом начале объявим:

```c++
#pragma once 
// Далее: перечисляем все необходимые зависимости, если они необходимы. Типа:
// #include<имя>

// объявляем различные функции. Что-то типа:
// void firsFunc(int argA, int argB);
```

Теперь в исполняемом файле (my_file.cpp и main.cpp) укажем путь до заголовка:

```c++
#include "../include/my_math.h"

// Далее: обычное содержание исполняемого файла
```
Для линтера, в `add_executable`, перечисляем все необходимые пути. 
И добавить команду `target_include_directories`, которая добавляет к exe-файлу указанные директории:

```cmake
cmake_minimum_required(VERSION 3.25)
project(25_4_1 VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)

add_executable(FirstApp main.cpp ../include/my_math.h my_math.cpp)
target_include_directories(FirstApp PUBLIC include)
```
Теперь файлы понимают, где получать информацию.

---

Можно создать не только основной CMakeLists.txt, но и вложенные. 
Это упростит сопровождение проекта. 

В папке `src` создадим CMakeLists. 
В `add_executable` перечислим все зависимые файлы. 
А в `target_include_directories` добавим путь до корневой папки заголовочных файлов:

```cmake
cmake_minimum_required(VERSION 3.24)

add_executable(FirstApp main.cpp ${CMAKE_SOURCE_DIR}/include/my_math.h my_math.cpp)
target_include_directories(FirstApp PUBLIC ${CMAKE_SOURCE_DIR}/include)
```
Можно здесь же создать свою переменную и передать в неё повторяющийся код:

```cmake
cmake_minimum_required(VERSION 3.24)

set(MAIN_PATH ${CMAKE_SOURCE_DIR}/include)

add_executable(FirstApp main.cpp ${MAIN_PATH}/my_math.h my_math.cpp)
target_include_directories(FirstApp PUBLIC ${MAIN_PATH})
```
В главном же передадим инструкцию в add_subdirectory. Это позволит связать основной и зависимый CMakeLists:

```cmake
cmake_minimum_required(VERSION 3.24)
project(FirstApp VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(src)
```

Для лучшей читаемости, можно перенести `set(MAIN_PATH ${CMAKE_SOURCE_DIR}/include)` в заголовочный CMakeLists. 
В итоге весь код будет выглядеть так:

```cmake
#Основной cmake
cmake_minimum_required(VERSION 3.24)
project(FirstApp VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(MAIN_PATH ${CMAKE_SOURCE_DIR}/include)

add_subdirectory(src)
```
```cmake
#Вложенный cmake
cmake_minimum_required(VERSION 3.24)

add_executable(FirstApp main.cpp ${MAIN_PATH}/my_math.h my_math.cpp)
target_include_directories(FirstApp PUBLIC ${MAIN_PATH})
```
</details>
</details>
<details>
<summary><span style="color: Tomato; font-size: 16px">Полезные ссылки</span></summary>
<a href="https://radioprog.ru/post/1227" style="margin-left:16px">Определение функций-членов вне определения класса</a>
</details>
