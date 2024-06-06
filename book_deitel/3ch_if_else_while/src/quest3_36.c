#include <stdio.h>
int main(void) {
    int number, num, num2, temp = 0, i = 1;
    scanf("%d", &number);
    while (number > 0) {
        num = number % 10;
        num2 = num * i;
        temp += num2;
        i *= 2;
        number /= 10;
    }
    printf("%d", temp);
    return 0;
}