#include <stdio.h>
int chislo (int number);
int main(void) {
    int number;
    scanf("%d", &number);
    printf("%d", chislo(number));
    return 0;
}
int chislo(int number) {
    int temp, count = number, temp1 = 1, chislo;
    while(count > 0) {
        count /= 10;
        temp1 *= 10;
    }
    temp1 /= 10;
    while(number > 0) {
        temp = number % 10;
        chislo += temp * temp1;
        temp1 /= 10;
        number /= 10;
    }
    return chislo;
}