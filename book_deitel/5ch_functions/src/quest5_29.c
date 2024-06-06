#include <stdio.h>
int gcd(int number1, int number2);
int main(void) {
    int number1, number2;
    scanf("%d%d", &number1, &number2);
    printf("%d", gcd(number1, number2));
    return 0;
}
int gcd(int number1, int number2) {
    if (number2 == 0)
        return number1;
    else
        return gcd(number2, number1 % number2);
}
