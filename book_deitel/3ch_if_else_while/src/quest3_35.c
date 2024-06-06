#include <stdio.h>

int main(void) {
    int number, num1, num2, i = 0, temp = 10000;
    scanf("%d", &number);
    while (number > 0) {
        num1 = number % 10;
        num2 = (number / temp) % 10;
        if (num1 == num2) i++;
        number /= 10;
        temp /= 10;
    }
    i >= 2 ? puts("YES") : puts("NO");
    return 0;
}