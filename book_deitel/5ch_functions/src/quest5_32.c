#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int chislo(void);
int main(void) {
    srand(time(NULL));
    int result, number;
    number = chislo();
    while (result != -1) {
        scanf("%d", &result);
        if (result == number) {
            puts("Очень хорошо\n");
            number = chislo();
        } else if (result != -1) {
            puts("Неверно, пожалуйста попробуйте снова");
        }
    }
    return 0;
}
int chislo(void) {
    int number1, number2;
    number1 = 1 + rand() % 10;
    number2 = 1 + rand() % 10;
    printf("How much is %d times %d\n", number1, number2);
    return number1 * number2;
}