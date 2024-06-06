#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void) {
    /*a*/
    int number = 0;
    srand(time(NULL));
    number = rand() % 5;
    printf("%d\n", 2 + number * 2);
    /*b*/
    printf("%d\n", 3 + number * 2);
    /*c*/
    printf("%d\n", 6 + number * 4);
    return 0;
}