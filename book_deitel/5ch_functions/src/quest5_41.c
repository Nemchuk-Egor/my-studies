#include <stdio.h>
int factorial(int number);
int main(void) {
    int number;
    printf("Введите число: ");
    scanf("%d", &number);
    printf("Факториал числа %d равен: %d\n", number, factorial(number));
    return 0;
}
int factorial(int number){
    printf("Вычисляем факториал для %d...\n", number);
    if(number == 1) {
        printf("Достигнуто условие рекурсии : %d == 1, возвращаем 1\n", number);
        return 1;
    }
    else {
        int result = number * factorial(number - 1);
        printf("Шаг рекурсии: %d * факториал(%d - 1) = %d, возвращаем %d...\n", number, number, number * factorial(number - 1), result);
        return result;
    }
}
