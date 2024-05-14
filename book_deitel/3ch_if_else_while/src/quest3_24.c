#include <stdio.h>
int main(void) {
    int number, counter = 0, largest;
    while(counter != 10) {
        scanf("%d", &number);
        if(number > largest) largest = number;
        counter++;
    }
    printf("%d", largest);
    return 0;
}