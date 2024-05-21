// Задание 3. Не пара

// Преподаватели Geek Brains создали набор, содержащий N (1 ≤ N ≤ 1 000 000) натуральных чисел, не превосходящих 1 000 000. Известно, что ровно одно число в этом наборе встречается один раз, а остальные — ровно по два раза. Помогите им найти это число. Входные данные: в первой входной строке вводится число N, затем по одному числу в строке вводятся N натуральных чисел, не превосходящих 2 000 000 000. Выходные данные: ваша программа должна определить число, встречающееся один раз, и вывести его на экран.

// Указание: использовать массивы запрещается.

// Данные на входе: Натуральное число N (N > 0), после которого следует
// последовательность из N целых чисел.
// Данные на выходе: Одно целое число.

#include <stdio.h>
#include <inttypes.h>

int main()
{
    uint32_t N, inpt, res;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &inpt);
        res ^=inpt;
    }
    printf("%u\n", res);
    return 0;
}
