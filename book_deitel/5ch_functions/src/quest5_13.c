#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void) {
    srand(time(NULL));
    /*a*/
    for (int x = 1; x <= 5; x++) {
        printf("%d ", 1 + rand() % 2);
        if (x % 5 == 0) puts("");
    }
    /*b*/
    for (int x = 1; x <= 5; x++) {
        printf("%d ", 1 + rand() % 100);
        if (x % 5 == 0) puts("");
    }
    /*c*/
    for (int x = 1; x <= 5; x++) {
        printf("%d ", rand() % 10);
        if (x % 5 == 0) puts("");
    }
    /*d*/
    for (int x = 1; x <= 5; x++) {
        printf("%d ", 1000 + rand() % 113);
        if (x % 5 == 0) puts("");
    }
    /*e*/
    for (int x = 1; x <= 5; x++) {
        printf("%d ", -1 + rand() % 3);
        if (x % 5 == 0) puts("");
    }
    /*f*/
    for (int x = 1; x <= 5; x++) {
        printf("%d ", -3 + rand() % 15);
        if (x % 5 == 0) puts("");
    }
    return 0;
}