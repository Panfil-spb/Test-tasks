# 1. Числовые ребусы
Алиса изучает английский язык. Ей надоела обычная речь, поэтому она решила говорить числовыми ребусами:
Каждой строчной букве латинского алфавита Алиса сопоставила двоичный разряд, начиная с младшего: a — 0-й разряд, b — 1-й, …, z — 25-й.
Чтобы произнести букву, Алиса инвертирует соответствующий букве бит в специальной переменной W
 и сообщает новое значение 
W
 в десятичной системе.
Определение: инверсия бита 
j
 в числе 
x
  — изменение значения 
j
-го разряда числа 
x
 в двоичной системе на противоположное (
0
 становится 
1
, 
1
 становится 
0
).
Пример: число 
1
5
 (
1
1
1
1
) после инверсии бита 
2
 становится равным числу 
1
1
 (
1
0
1
1
).

Также Алиса произносит пробел, используя для этого 
2
6
-й разряд.
Значение переменной 
W
 перед произнесением Алисой первого символа равно 
0
.
Напишите программу, которая переведет сказанный Алисой числовой ребус.
Примечание: Алиса использует пробел наравне с буквами латинского алфавита  — для пробела не существует дополнительных ограничений и условий для его произнесения.

## Формат ввода
В первой строке содержится единственное целое число 
n
 (
1
≤
n
≤
5
0
0
)  — количество чисел, сказанных Алисой.
Во второй строке расположено 
n
 целых чисел 
W
i
 (
0
≤
W
i
<
2
2
7
)  — значения переменной 
W
 после произнесения Алисой 
i
-го символа.

## Формат вывода
В единственной строке выведите 
n
 символов  — строчные буквы латинского алфавита или пробел в порядке произнесения их Алисой.
 
# 2. Шестиугольники
На клетчатом поле нарисовали некоторую картину, состоящую из одинаковых шестиугольников.
Шестиугольники, из которых состоит картина, задаются с помощью следующих символов:

Нижнее подчеркивание (_) для верхней и нижней стороны.
Слеш (/) для верхней левой и нижней правой стороны.
Обратный слеш (\) для верхней правой и нижней левой стороны.
Любая заглавная латинская буква (например, X) в центре шестиугольника.
Ниже представлен пример шестиугольника:

 .....
 
 .._..
 
 ./X\\.
 
 .\\_/.
 
 .....


Нарисованные шестиугольники не пересекаются и не накладываются друг на друга, но могут иметь общую сторону (см. примеры).
Картина вписывается в клетчатое поле с наименьшими возможными высотой и шириной. После этого добавляется первая и последняя строка, и первый и последний столбец, состоящие из символов . (точка). Все клетки, которые не содержатся в картине, также заполняются символом . (точка).
Вам необходимо отразить поле с шестиугольниками по вертикали и горизонтали, после чего вывести итоговое отраженное поле.

## Формат ввода
В первой строке вводятся числа 
n
 и 
m
 (
5
≤
n
,
m
≤
1
0
0
)  — размеры поля. Далее в 
n
 строках вводится поле, по 
m
 символов в каждой строке.
## Формат вывода
Выведите 
n
 строк по 
m
 символов в каждой  — отраженное поле.
# 3. Домашнее задание
Борис прошел в школе сразу две новых темы - наибольший общий делитель (НОД) и простые числа.
Определение: наибольшим общим делителем двух целых положительных чисел 
A
 и 
B
 называют такое число 
G
, что:

A
 делится на 
G
 нацело (
G
 является делителем 
A
);
B
 делится на 
G
 нацело (
G
 является делителем 
B
);
не существует числа 
H
 такого, что 
G
<
H
 и 
H
 удовлетворяет условиям 
1
 и 
2
.
Определение: число 
P
 называется простым, если у него есть ровно два различных делителя: 
1
 и само число 
P
.
К примеру:

число 
1
 не является простым, так как у него только один делитель  — 
1
;
4
 не простое, так как у 
4
 есть три делителя  — 
1
, 
2
, 
4
;
6
 не простое, так как у 
6
 четыре различных делителя  — 
1
, 
2
, 
3
, 
6
.
В качестве домашнего задания Борису необходимо решить 
T
 заданий следующего вида:
«Даны два целых числа 
A
 и 
B
, можно ровно один раз умножить либо 
A
, либо 
B
 на любое простое число. Какого наибольшего значения НОД можно добиться с помощью такого умножения?»


## Формат ввода
В первой строке дано целое число 
T
 (
1
≤
T
≤
2
0
)  — количество заданий.
В каждой из следующих 
T
 строк содержатся два целых числа 
A
 и 
B
 (
1
≤
A
,
B
≤
1
0
1
2
)  — параметры задания.

## Формат вывода
Для каждого задания выведите единственное целое число  — наибольшее значение НОД, которого можно добиться умножением одного из чисел 
A
 и 
B
 на любое простое число.
# 5. Пересечения прямоугольников
Дан набор прямоугольников на плоскости со сторонами, параллельными осям координат.

Для каждого прямоугольника необходимо вычислить количество других прямоугольников, с которыми данный прямоугольник пересекается.

Определение: два прямоугольника пересекаются, если существует область ненулевой площади, принадлежащая обоим прямоугольникам. Внешнее касание по стороне образует общую область нулевой площади, поэтому пересечением не является.

## Формат ввода
В первой строке дано целое число n (1 ≤ n ≤ 100 000)  — количество прямоугольников.

В следующих n строках заданы описания прямоугольников: целые числа xL, yL, xR, yR (-109 ≤ xL, yL, xR, yR ≤ 109; xL < xR; yL < yR)  — координаты левого нижнего и правого верхнего углов.

## Формат вывода
В единственной строке выведите через пробел n чисел: i-е число равно количество прямоугольников, пересекающихся с i-м в порядке ввода прямоугольником.