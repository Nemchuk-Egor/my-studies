#include <stdio.h>
double celsius (int number);
int fahrenheit(int number);
int main(void) {
    printf("%s%12s\n", "celsius", "fahrenheit");
    for(int i = 0; i <= 100; i++) {
        printf("%4d%12d", i, fahrenheit(i));
        puts("");
    }
    printf("%s%10s\n", "fahrenheit", "celsius");
    for(int j = 32; j <= 212; j++) {
        printf("%4d%10.4f", j, celsius(j));
        puts("");
    }
    return 0;
}
int fahrenheit (int number) {
    return (number * (9/5)) + 32;
}
double celsius (int number) {
    double i;
    return i = (number - 32) * 5.0/9.0;
}
