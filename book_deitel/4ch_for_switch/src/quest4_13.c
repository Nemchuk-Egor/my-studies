#include <stdio.h>
int main(void) {
    int total = 1;
    for (int x = 1; x <= 15; x++)
        if (x % 2 == 1) total *= x;
    printf("%d", total);
    return 0;
}