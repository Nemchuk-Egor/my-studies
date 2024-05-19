#include <stdio.h>
int main(void){
    int number, number1, total = 0;
    scanf("%d", &number);
    for(int x = 1; x <= number; x++) {
        scanf("%d", &number1);
        total += number1;
    }
    printf("%d", total);
}