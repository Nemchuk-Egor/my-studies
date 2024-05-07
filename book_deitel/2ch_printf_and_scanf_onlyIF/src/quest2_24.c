#include <stdio.h>
/* Написать программу считывающее целое число и затем определяет
четное оно или нет*/

int main(void) {
    int num;
    scanf("%d", &num);
    if(num % 2 == 0) printf("YES");
    if(num % 2 == 1) printf("NO");
    return 0;
}