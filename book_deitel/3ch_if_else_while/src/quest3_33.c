#include <stdio.h>
int main(void) {
    int sqr;
    scanf("%d", &sqr);
    if(sqr < 1) {
        puts("fail");
    } else {
        if(sqr > 20) {
            puts("fail");
        } else {
            int i = 0;
            while(i != sqr) {
                int j = 0;
                while(j != sqr) {
                    printf("*");
                    j++;
                }
                printf("\n");
                i++;
            }
        }
    }
    return 0;
}