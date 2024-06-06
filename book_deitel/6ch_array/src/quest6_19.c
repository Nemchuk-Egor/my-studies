#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 13
#define SIZE1 36000
int my_random(void);
int main(void) {
    srand(time(NULL));
    int a[SIZE1];
    int b[SIZE] = {0};
    for(int i = 0; i < SIZE1; i++) {
        a[i] = my_random() + my_random();
        ++b[a[i]];
    }
    for(int i = 2; i < SIZE; i++) {
        printf("%d. %d\n", i, b[i]);
    }
    return 0;
}
int my_random(void) {
    return 1 + rand() % 6;
}