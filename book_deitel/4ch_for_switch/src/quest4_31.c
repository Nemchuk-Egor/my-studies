#include <stdio.h>
int main(void) {
    for(int i = 1; i <= 5; i++) {
        for(int j = 5; j > i; j--) printf(" ");
        for(int g = 1; g <= i; g++) printf("*");
        for(int d = 1; d < i; d++) printf("*");
        printf("\n");
    }
    for(int i = 1; i <= 4; i++) {
        for(int j = 0; j < i; j++) printf(" ");
        for(int g = 4; g >= i; g--) printf("*");
        for(int d = 4; d > i; d--) printf("*");
        printf("\n");
    }
    return 0;
}