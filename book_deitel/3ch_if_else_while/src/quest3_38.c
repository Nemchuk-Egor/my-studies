#include <stdio.h>
int main(void) {
    int i = 0;
    while (i != 100) {
        printf("*");
        if (i % 10 == 0) printf("\n");
        i++;
    }
    return 0;
}