#include <stdio.h>
void perfect(int number);
int main(void) {
    for(int i = 1; i <= 1000000; i++) {
        perfect(i);
    }
    return 0;
}
void perfect(int number) {
    int count = 0;
    for(int i = 1; i < number; i++) {
        if(number % i == 0) {
            count += i;
        }
    }
    if(count == number) {
        printf("%d\n", count);
    }
}