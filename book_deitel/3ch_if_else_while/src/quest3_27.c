#include <stdio.h>
int main(void) {
    int number, counter = 0, largestOne, largestTwo;
    while(counter != 10) {
        scanf("%d", &number);
        if(number > largestOne) {
            largestTwo = largestOne;
            largestOne = number;
        }     
        counter++;
    }
    printf("%d %d", largestOne, largestTwo);
    return 0;
}