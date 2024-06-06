#include <stdio.h>
int integerPower(int base, int exponent);
int main(void) {
    int base, exponent;
    scanf("%d%d", &base, &exponent);
    printf("%d", integerPower(base, exponent));
    return 0;
}
int integerPower(int base, int exponent) {
    int count = 1;
    for (int i = 1; i <= exponent; i++) count *= base;
    return count;
}