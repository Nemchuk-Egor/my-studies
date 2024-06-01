#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
int chislo(void);
void text(int number, bool value);
int main(void) {
    srand(time(NULL));
    int result, number, count = 0, countP = 0;
    number = chislo();
    while(count++ != 10){
        scanf("%d", &result);
        if(result == number) {
            text(1 + rand() % 4, true);
            number = chislo();
            countP++;
        }else if (result != -1) {
            text(1 + rand() % 4, false);
        }
    }
    if(countP / 10 * 100 < 75) puts("Попросите вашего учителя о доп занятиях!");        
    return 0;
}
int chislo(void){
    int number1, number2;
    number1 = 1 + rand() % 10;
    number2 = 1 + rand() % 10;
    printf("How much is %d times %d\n",number1, number2);
    return number1 * number2;
}
void text(int number, bool value) {
    if(value) {
        switch (number)
        {
        case 1:
            puts("Очень хорошо\n");
            break;
        case 2:
            puts("Превосходно!\n");
            break;
        case 3:
            puts("Отличная работа!\n");
            break;
        case 4:
            puts("Продолжай в том же духе!\n");
            break;
        }
    } else {
        switch (number)
        {
        case 1:
            puts("Нет попробуй снова\n");
            break;
        case 2:
            puts("Неправильно попытайтесь еще раз\n");
            break;
        case 3:
            puts("Не сдавайтесь\n");
            break;
        case 4:
            puts("Нет продолжайте пробовать\n");
            break;
        }
    }
}