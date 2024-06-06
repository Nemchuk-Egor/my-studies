#include <stdio.h>
int main(void) {
    float sum_sell;
    printf("%s", "Введите сумму продаж в долларах (-1 если ввод закончен): ");
    scanf("%f", &sum_sell);
    while (sum_sell != -1) {
        printf("Зарплата: $%.2f\n", 200 + (sum_sell * 0.09));
        puts("");
        printf("%s", "Введите сумму продаж в долларах (-1 если ввод закончен): ");
        scanf("%f", &sum_sell);
    }
    return 0;
}