#include <stdio.h>
int main(void) {
    int i = 1;
    printf("%-10s%-10s%-10s%-10s\n", "N", "10*N", "100*N", "1000*N");
    puts("");
    while(i != 11) {
        printf("%-10d%-10d%-10d%-10d\n", i, 10 * i, 100 * i, 1000 * i);
        i++;
    }
    return 0;
}