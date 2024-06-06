#include <stdio.h>
int main(void) {
    /* Замена цикла do while на обычный while */
    int x = 7;
    do {
        printf("%d ", x);
    } while (x++ < 5);
    puts("");
    x = 7;
    while (1) {
        printf("%d ", x);
        x++;
        if (x >= 6) break;
    }
    /*Замена цикла while на do while */
    while (x < 7) {
        printf("%d ", x);
    }
    if (x < 7) {
        do {
            printf("%d ", x);
        } while (x < 7);
    }
    return 0;
}