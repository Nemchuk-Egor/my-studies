#include <stdio.h>
int main(void) {
    int number, i = 1, count, count2;
    double fact, e = 1.0, x = 1.0;
    scanf("%d", &number);
    while(i <= number) {
        count = 1;
        fact = 1.0;
        while(count <= i) {
            fact *= count;
            count++;
        }
        count2 = 1;
        x = 1.0;
        while(count2 <= i) {
            x *= number;
            count2++;
        }
        e += x / fact;
        i++;
    }
    printf("%f", e);
    return 0;
}