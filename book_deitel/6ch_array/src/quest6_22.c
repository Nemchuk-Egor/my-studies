#include <stdio.h>
#define SELL_MAN 4
#define PRODUCT 5
int main(void) {
    int sales[SELL_MAN][PRODUCT] = {0};
    int number, total_summ = 0;
    int sell_summ[SELL_MAN] = {0}, sell_summ_two[PRODUCT] = {0};
    for(int i = 0; i < SELL_MAN; i++) {
        for(int j = 0; j < PRODUCT; j++) {
            printf("Номер продавца %d, Номер изделия %d"
            " Введите общую сумму в долларах за данный товар в месяц \n", i + 1, j + 1);
            scanf("%d", &number);
            sales[i][j] = number;
            sell_summ[i] += number;
            sell_summ_two[j] += number;
            total_summ += number;
        }
    }
    printf("%2s%10s%10s%8s%8s%8s%8s\n", "№", "Т1", "Т2", "T3", "T4", "T5", "SUM");
    for(int i = 0; i < SELL_MAN; i++) {
        printf("%2d", i + 1);
        for(int j = 0; j < PRODUCT; j++) {
            printf("%8d",sales[i][j]);
            if(j == PRODUCT - 1) printf("%8d", sell_summ[i]); 

        }
        puts("");
    }
    printf("%10d%8d%8d%8d%8d%8d\n", sell_summ_two[0], sell_summ_two[1], sell_summ_two[2], sell_summ_two[3], sell_summ_two[4], total_summ);
    return 0;
}