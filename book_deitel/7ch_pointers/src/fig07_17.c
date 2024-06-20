#include <stdio.h>
#include <stddef.h>
int main(void) {
    char c;
    short s;
    int i;
    long l;
    float f;
    double d;
    long double ld;
    int array[20];
    int *ptr = array;
    printf("sizeof c = %ld\tsizeof(char) = %ld"
    "\nsizeof s = %ld\tsizeof(short) = %ld"
    "\nsizeof i = %ld\tsizeof(int) = %ld"
    "\nsizeof l = %ld\tsizeof(long) = %ld"
    "\nsizeof f = %ld\tsizeof(float) = %ld"
    "\nsizeof d = %ld\tsizeof(double) = %ld"
    "\nsizeof ld = %ld\tsizeof(long double) = %ld"
    "\n sizeof array = %ld"
    "\n sizeof ptr = %ld\n",
    sizeof c, sizeof(char),sizeof s, sizeof(short),
    sizeof i, sizeof(int),sizeof l, sizeof(long),
    sizeof f, sizeof(float),sizeof d, sizeof(double),
    sizeof ld, sizeof(long double),sizeof array, sizeof *ptr);
    return 0;
}