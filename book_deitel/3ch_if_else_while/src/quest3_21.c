#include <stdio.h>
int main(void) {
    int hour;
    float rate, over_rate;
    printf("%s", "Введите количество отработыных часов (-1 если ввод закончен): ");
    scanf("%d", &hour);
    while (hour != -1) {
        printf("%s", "Введите почасовой тариф работника ($00.00): ");
        scanf("%f", &rate);
        if (hour > 40) {
            over_rate = (hour - 40) * rate * 1.5;
            printf("Зарплата составляет $%.2f\n", rate * 40 + over_rate);
            puts("");
        } else {
            printf("Зарплата составляет $%.2f\n", hour * rate);
            puts("");
        }
        printf("%s", "Введите количество отработыных часов (-1 если ввод закончен): ");
        scanf("%d", &hour);
    }
    return 0;
}