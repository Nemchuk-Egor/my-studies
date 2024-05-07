#include <stdio.h>
/*Напишите программу которая предлагает пользователю ввести три целых числа и находит их сумму
среднее наибольшее и наименьшее */
int main(void) {
    int n1, n2, n3, max, min;
    scanf("%d%d%d", &n1, &n2, &n3);
    printf("Sum is %d\n", n1 + n2 + n3);
    printf("Average is %d\n", (n1 + n2 + n3) / 3);
    printf("Product is %d\n", n1 * n2 * n3);
    min = n1;
    max = n1;
    if (n2 < min) {
        min = n2;
    }
    if (n3 < min) {
        min = n3;
    }
    printf("Smallest is %d\n", min);
    if (n2 > max) {
        max = n2;
    }
    if (n3 > max) {
        max = n3;
    }
    printf("Largest is %d\n", max);
    return 0;
}