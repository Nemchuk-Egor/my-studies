#include <stdio.h>
int main(void) {
    int total = 0;
    for (int x = 2; x <= 30; x++)
        if (x % 2 == 0) total += x;
    printf("%d", total);
    return 0;
}