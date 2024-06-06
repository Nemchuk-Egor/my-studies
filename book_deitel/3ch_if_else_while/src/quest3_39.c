#include <stdio.h>
int main(void) {
    int number, count;
    scanf("%d", &number);
    while (number > 0) {
        if (number % 10 == 7) count++;
        number /= 10;
    }
    printf("%d", count);
    return 0;
}