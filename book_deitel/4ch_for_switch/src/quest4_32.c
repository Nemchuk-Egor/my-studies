#include <stdio.h>
int main(void) {
    int number;
    scanf("%d", &number);
    for (int i = 1; i <= number; i++) {
        for (int j = number; j > i; j--) printf(" ");
        for (int g = 1; g <= i; g++) printf("*");
        for (int d = 1; d < i; d++) printf("*");
        printf("\n");
    }
    for (int i = 1; i <= number - 1; i++) {
        for (int j = 0; j < i; j++) printf(" ");
        for (int g = number - 1; g >= i; g--) printf("*");
        for (int d = number - 1; d > i; d--) printf("*");
        printf("\n");
    }
    return 0;
}