#include <stdio.h>
/* Программа принимает два числа затем выводит какое из двух чисел больше если 
они равны она пишет об этом*/

int main(void) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (x > y) {
        printf("is larger %d", x);
    }
    if (y > x) {
        printf("is larger %d", y);
    }
    if (y == x) {
        printf("These numbers are equal");
    }

    return 0;
}