#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10
int main(void) {
    srand(time(NULL));
    int hold, sorted,count = 0;;
    int a[SIZE] = {10,18,42,46,50,53,59,60,83,0};
    for(int i = 0; i < SIZE - 1 && sorted == 0; i++) {
        sorted = 1;
        for(int j = 0; j < SIZE - i - 1; j++) {
            count++;
            if(a[j] > a[j + 1]) {
                hold = a[j + 1];
                a[j + 1] = a[j];
                a[j] = hold;
                sorted = 0;
            }
        }
    }
    for(int i = 0; i < SIZE; i++) {
        printf("%2d ", a[i]);
    }
    printf("\n%d", count);
    return 0;
}