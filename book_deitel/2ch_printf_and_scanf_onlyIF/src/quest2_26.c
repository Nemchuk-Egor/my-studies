#include <stdio.h>
/* Написать программу которая считывает два целых числа после чего определяет
кратно ли первое второму и выводит эту информацию на печать.*/

int main(void) {
    int n1, n2;
    scanf("%d%d", &n1, &n2);
    if (n1 % n2 == 0) printf("YES");
    if (n1 % n2 != 0) printf("NO");
    return 0;
}