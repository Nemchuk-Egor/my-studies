#include <stdio.h>

int main(void) {
    int number;
    float start_balance, sum_sell, sum_credit, credit;
    printf("%s", "Введите номер счета (-1, если ввод закончен): ");
    scanf("%d", &number);
    while (number != -1) {
        printf("%s", "Введите начальный баланс: ");
        scanf("%f", &start_balance);
        printf("%s", "Введите общую сумму расходов: ");
        scanf("%f", &sum_sell);
        printf("%s", "Введите общую сумму кредита: ");
        scanf("%f", &sum_credit);
        printf("%s", "Введите предельный размер кредита: ");
        scanf("%f", &credit);
        if(start_balance + sum_sell - sum_credit > credit) {
            printf("Счет %d\n", number);
            printf("Предельный размер кредита: %.2f\n", credit);
            printf("Баланс %.2f\n", start_balance + sum_credit);
            puts("Предельный размер кредита превышен.");
        }
        puts("");
        printf("%s", "Введите номер счета (-1, если ввод закончен): ");
        scanf("%d", &number);
    }
    return 0;
}