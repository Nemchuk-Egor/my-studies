#include <stdio.h>
void cubeByValue(int *nPtr);
int main(void) {
    int number = 5;
    printf("The original value of number is %d", number);
    cubeByValue(&number);
    printf("\nThe new value of number is %d", number);
    return 0;
}
void cubeByValue(int *nPtr) {
    *nPtr = *nPtr * *nPtr * *nPtr;
}