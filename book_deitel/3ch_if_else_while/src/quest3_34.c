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
                    if(i == 0) printf("*");
                    if(i == sqr - 1) printf("*");
                    if(i > 0) {
                        if(i < sqr - 1) {
                            if(j == 0) printf("*"); 
                            if(j == sqr - 1) printf("*");
                            if(j > 0) {
                                if(j < sqr - 1) {
                                    printf(" ");
                                }
                            }

                        }
                    }
                    j++;
                }
                printf("\n");
                i++;
            }
        }
    }
    return 0;
}