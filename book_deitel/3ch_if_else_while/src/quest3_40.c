#include <stdio.h>
int main(void) {
    int i = 0;
    while (i != 8) {
        int j = 0;
        if (i % 2 == 1) printf(" ");
        while (j != 8) {
            printf("* ");
            j++;
        }
        printf("\n");
        i++;
    }
    return 0;
}