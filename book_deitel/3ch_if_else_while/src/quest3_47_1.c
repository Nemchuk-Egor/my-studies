#include <stdio.h>
int main(void) {
    int number, count = 1, result = 1;
    scanf("%d", &number);
    while (count <= number) {
        result *= count;
        count++;
    }
    printf("%d", result);
    return 0;
}