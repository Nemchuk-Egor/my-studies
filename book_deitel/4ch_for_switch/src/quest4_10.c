#include <stdio.h>
int main(void) {
    int count, number, total = 0;
    scanf("%d", &number);
    while(number != 9999) {
        total += number;
        count++;
        scanf("%d", &number);
    }
    printf("%d", total / count);
    return 0;
}