#include <stdio.h>
void perfect(int number);
int main(void) {
    for(int i = 1; i <= 1000; i++) {
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
        for(int j = 1; j < count; ++j) {
            if(count % j == 0) {
                printf("%d", j);
                if(j < count) printf("+");
            }
        }
        printf(" = %d\n", count);
    }
}