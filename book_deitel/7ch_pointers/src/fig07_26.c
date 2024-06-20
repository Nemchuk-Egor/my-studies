#include <stdio.h>
#define SIZE 10
void buble(int work[], const int size,
    int (*compare)(int a, int b));
int ascending(int a, int b);
int descending(int a, int b);
int main(void) {
    int order;
    int counter;
    int a[SIZE] = {2,6,4,8,10,12,89,68,45,37};
    printf("%s", "Enter 1 to sort in ascending order,\n"
    "Enter 2 to sort in descending order: ");
    scanf("%d", &order);
    puts("\nData items in original order");
    for(counter = 0; counter < SIZE; counter++) {
        printf("%5d", a[counter]);
    }
    if(order == 1) {
        buble(a, SIZE,ascending);
        puts("\nData items in ascending order");
    } else {
        puts("");
        buble(a, SIZE, descending);
    }
    for(counter = 0; counter < SIZE; counter++) {
        printf("%5d", a[counter]);
    }
    return 0;
}
void buble(int work[], const int size,
    int (*compare)(int a, int b)) {
        void swap(int *element1Ptr, int *element2Ptr);
        for(int i = 0; i < size - 1; i++) {
            for(int j = 0; j < size - 1; j++) {
                if( (*compare) (work[j], work[j + 1])) {
                    swap(&work[j], &work[j + 1]);
                }
            }
        }
    }
void swap(int *element1Ptr, int *element2Ptr) {
    int temp = *element1Ptr;
    *element1Ptr = *element2Ptr;
    *element2Ptr = temp;
}
int ascending(int a, int b) {
    return b < a;
}
int descending(int a, int b) {
    return b > a;
}