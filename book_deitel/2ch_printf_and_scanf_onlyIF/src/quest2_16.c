#include <stdio.h>
/* Пользователь вводит два целочисленных числа затем на выход получает сумму, произведение
разность, частное и результат взятия по модулю этих чисел*/
int main(void) {
    int num1, num2;
    scanf("%d%d", &num1, &num2);
    printf("%d\n", num1 + num2);
    printf("%d\n", num2 * num2);
    printf("%d\n", num1 - num2);
    printf("%d\n", num1 / num2);
    printf("%d\n", num1 % num2);
    return 0;
}
