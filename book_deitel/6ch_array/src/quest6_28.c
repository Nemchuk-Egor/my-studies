#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 20
int main(void) {
    srand(time(NULL));
    int count = 0, number;
    int a[SIZE] = {0};
    for(int i = 0; i < SIZE; i++) {
        int flag = 0;
        number = 1 + rand() % 20;
        for(int j = 0; j < count; j++) {
            if(number == a[j]) {
                flag = 1;
                break;
            }
        }
        if(flag == 0) {
            a[count] = number;
            count++;
        }
    }
    for(int i = 0; i < count; i++) printf("%d ", a[i]);
    return 0;
}