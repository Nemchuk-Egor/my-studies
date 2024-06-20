#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10
void bublesort(int* const arr, const int size);
int main(void) {
    int arr[SIZE] = {0};
    srand(time(NULL));
    for(int i = 0; i < SIZE; i++) {
        arr[i] = rand() % SIZE * SIZE + 1;
        printf("%d ", arr[i]);
    }
    puts("");
    bublesort(arr, SIZE);
    for(int i = 0; i < SIZE; i++) printf("%d ", arr[i]);
    return 0;
}
void bublesort(int* const arr, int size){
    void swap(int *element1Ptr, int *element2Ptr);
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - 1; j++) {
            if(arr[j] > arr[j + 1]) swap(&arr[j], &arr[j + 1]);
        }
    }
}
void swap(int *element1Ptr, int *element2Ptr) {
    int temp = *element2Ptr;
    *element2Ptr = *element1Ptr;
    *element1Ptr = temp;
}