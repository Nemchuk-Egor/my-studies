#include <stdio.h>
/* Написать программу которая считывает 5 целых чисел и
выводит наибольшее и наименьшее */
int main(void) {
    int n1, n2, n3, n4, n5, min, max;
    scanf("%d%d%d%d%d", &n1, &n2, &n3, &n4, &n5);
    min = n1;
    max = n1;
    if (n2 < min) min = n2;
    if (n3 < min) min = n3;
    if (n4 < min) min = n4;
    if (n5 < min) min = n5;
    printf("%d\n", min);
    if (n2 > max) max = n2;
    if (n3 > max) max = n3;
    if (n4 > max) max = n4;
    if (n5 > max) max = n5;
    printf("%d", max);
    return 0;
}