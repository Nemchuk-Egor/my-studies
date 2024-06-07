#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
void selectionSort(int a[], int size);
int main(void) {
    int a[SIZE] = {0};
    for(int i = 0; i < SIZE; i++) a[i] = rand() % SIZE * SIZE + 1;
    selectionSort(a, SIZE);
    for(int i = 0; i < SIZE; i++) printf("%d ", a[i]);
    return 0;
}
void selectionSort(int a[], int size) {
    
    return 
}