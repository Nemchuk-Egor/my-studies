#include <stdio.h>
int main(void) {
    int b[] = {10, 20, 30, 40};
    int *bPtr = b;
    int i;
    int offset;
    puts("Array b printed with:\nArray subscript notation");
    for(i = 0; i < 4; i++) {
        printf("b[%d] = %d\n", i, b[i]);
    }
    puts("\nPointer/offser notation where\n");
    for(offset = 0; offset < 4; offset++) {
        printf("*(b + %d) = %d\n", offset, *(b + offset));
    }
    puts("\nPointer subscript notation");
    for(i = 0; i < 4; i++) {
        printf("bPtr[%d] = %d\n", i, bPtr[i]);
    }
    puts("");
    for(offset = 0; offset < 4; offset++) {
        printf("*(bPtr + %d) = %d\n", offset, *(bPtr + offset));
    }
    return 0;
}