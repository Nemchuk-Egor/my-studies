#include <stdio.h>
#include <stdbool.h>
#define SIZE 10
void someFunction(const int b[], int startIndex, int size);
int main(void) {
    int a[SIZE] = {8, 3, 1, 2, 6, 0, 9, 7, 4, 5};
    puts("Answer is:");
    someFunction(a, 9, 0);
    puts("");
    return 0;
}
void someFunction(const int b[], int startIndex, int size) {
    if(startIndex >= size) {
        someFunction(b,startIndex - 1, size);
        printf("%d ", b[startIndex]);
    }
}