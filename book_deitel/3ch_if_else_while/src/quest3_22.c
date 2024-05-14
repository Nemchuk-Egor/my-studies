#include <stdio.h>
/* Написать программу показывающую различие между операциями предекремента
и постдекремента*/
int main (void) {
    int x = 5;
    printf("%d\n", x);
    printf("%d\n", --x);
    printf("%d\n", x);
    puts("");
    x = 5;
    printf("%d\n", x);
    printf("%d\n", x--);
    printf("%d\n", x);
    return 0;
}