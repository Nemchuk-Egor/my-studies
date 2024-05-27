#include <stdio.h>
int del(int a, int b);
int ost(int a, int b);
int main(void) {
    int number, count = 1, temp, temp1;
    scanf("%d", &number);
    temp = number;
    while(temp > 0) {
        temp = del(temp, 10);
        count *= 10;
    }
    count /= 10;
    while(count > 0) {
        temp1 = del(number, count);
        printf("%d  ", ost(temp1, 10));
        count /= 10;
    }
    return 0;
}
int del(int a, int b) {
    return a / b;
}
int ost(int a, int b) {
    return a % b;
}