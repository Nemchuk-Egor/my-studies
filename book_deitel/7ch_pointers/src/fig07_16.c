#include <stdio.h>
#include <stddef.h>
size_t getSize(double *ptr);
int main(void) {
    double array[22];
    printf("The number of bytes in the array is %ld"
    "\nThe number of bytes returned by getSize is %ld\n",
    sizeof(array), getSize(array));
    return 0;
}
size_t getSize(double *ptr) {
    return sizeof(ptr);
}