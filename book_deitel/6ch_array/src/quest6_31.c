#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int main(void) {
    int arr[SIZE] = {0}, arr_two[SIZE][SIZE] = {0};
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) arr[i] = rand() % (SIZE * SIZE) + 1;

    printf("Исходный массив: ");
    for (int i = 0; i < SIZE; i++) printf("%d ", arr[i]);

    for(int i = 0; i < SIZE; i++) {
        int index = arr[i] / SIZE;
        int count = 0;
        while(arr_two[index][count] != 0)
            count++;
        arr_two[index][count] = arr[i];
    }

    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE - 1; j++) {
            for(int k = 0; k - i - 1 < SIZE; k++) {
                if(arr_two[i][k] > arr_two[i][k + 1]) {
                    int temp = arr_two[i][k + 1];
                    arr_two[i][k + 1] = arr_two[i][k];
                    arr_two[i][k + 1] = temp; 
                }
            }
        }
    }

    int index_1 = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (arr_two[i][j] != 0) {
                arr[index_1++] = arr_two[i][j];
            }
        }
    }
    printf("\nОтсортированный массив: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}