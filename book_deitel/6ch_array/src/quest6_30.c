#include <stdio.h>
#include <stdlib.h>
#define SIZE 30
int main(void) {
    int arr[SIZE] = {0};
    for(int i = 0; i < SIZE; i++) arr[i] = 1 + rand() % 1;
    arr[0] = 0;
    arr[1] = 0;
    for(int i = 2; i * i < SIZE; i++) {
        if(arr[i] == 1) {
            for(int j = i * i; j < SIZE; j += i) {
                arr[j] = 0;
            }
        }
    }
    printf("Index ");
    for(int i = 0; i < SIZE; i++) {
        printf("%2d ", i);
    }
    printf("\nValue ");
    for(int i = 0; i < SIZE; i++) {
        printf("%2d ", arr[i]);
    }
    return 0;
}