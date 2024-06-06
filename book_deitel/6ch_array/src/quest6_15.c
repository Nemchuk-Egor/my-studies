#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 20
int main(void){
    int a[SIZE];
    int b[SIZE] = {0};
    int count = 0;
    srand(time(NULL));
    for(int i = 0; i < SIZE; i++) {
        int flag = 0;
        for(int j = 0; j < count; j++) {
            if(a[i] == b[j]) {
                flag = 1;
                break;
            }
        }
        if(flag == 0) {
            b[count] = a[i];
            count++;
        }
    }
    for(int i = 0; i < SIZE; i++) {
        printf("%d ", a[i]);
    }
    puts("");
    for(int i = 0; i < count; i++) {
        printf("%d ", b[i]);
    }
    return 0;
}