#include <stdio.h>
int main(void){
    long int fact;
    printf("%s%12s\n", "№", "Factorial");
    for(int j = 1; j <= 20; j++) {
        fact = 1;
        for (int i = 1; i <= j; i++) fact *= i;
        printf("%d%20ld\n", j, fact);
    }
    return 0;
}