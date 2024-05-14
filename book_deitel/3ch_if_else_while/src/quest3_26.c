#include <stdio.h>
int main(void){
    int i = 0;
    printf("%-10s%-10s%-10s%-10s\n", "A", "A+2", "A+4", "A+6");
    puts("");
    while(i < 15) {
        i += 3;
        printf("%-10d%-10d%-10d%-10d\n", i, i + 2, i + 4, i + 6);
    }
    return 0;
}