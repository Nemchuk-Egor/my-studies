#include <stdio.h>
/* Написать программу разделяющую пятизначное число на отедльные цифры
*/

int main(void) {
    int num;
    scanf("%d", &num);
    printf("%d\t", (num / 10000) % 10);
    printf("%d\t", (num / 1000) % 10);
    printf("%d\t", (num / 100) % 10);
    printf("%d\t", (num / 10) % 10);
    printf("%d", num % 10);
    return 0;
}