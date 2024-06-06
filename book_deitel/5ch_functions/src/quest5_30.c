#include <stdio.h>
int qualityPoints(void);
int main(void) {
    printf("%d", qualityPoints());
    return 0;
}
int qualityPoints(void) {
    int number, choice;
    scanf("%d", &number);
    if (number >= 90 && number <= 100) choice = 4;
    if (number >= 80 && number <= 89) choice = 3;
    if (number >= 70 && number <= 79) choice = 2;
    if (number >= 60 && number <= 69) choice = 1;
    if (number < 60) choice = 0;
    return choice;
}