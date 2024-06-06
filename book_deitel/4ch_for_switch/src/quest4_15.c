#include <math.h>
#include <stdio.h>
int main(void) {
    double amount;
    double principal = 1000.0;
    double rate = .05;
    unsigned int year;
    printf("%s%8s%21s\n", "Year", "Rate", "Amount on deposit");
    for (year = 1; year <= 10; year++) {
        for (rate = .05; rate <= .10; rate += .01) {
            amount = principal * pow(1.0 + rate, year);
            printf("%4d%8.2f%21.2f\n", year, rate, amount);
        }
    }
    return 0;
}