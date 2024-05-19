#include <stdio.h>
int main(void) {
    int i = 0;
    printf("%s%12s", "10", "2");
    puts("");
    while(i++ != 256) {
        int decimal_number = i;
        int binary_number = 0;
        int place = 1;
        while(decimal_number > 0) {
            int remainder = decimal_number % 2;
            binary_number += remainder * place;
            decimal_number /= 2;
            place *= 10;
        }
        printf("%d%14d\n", i, binary_number);
    }
    return 0;
}