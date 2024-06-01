#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int flip(void);
int main(void) {
    int countH = 0, countT = 0;
    srand(time(NULL));
    for(int i = 1; i <= 100; i++) {
        flip();
        if(flip() == 1) {
            puts("Head\n");
            countH++;
        } else {
            puts("Tails\n");
            countT++;
        }
    }
    printf("%d\n%d", countH, countT);
    return 0;
}
int flip(void){
    return 1 + rand() % 2;
}