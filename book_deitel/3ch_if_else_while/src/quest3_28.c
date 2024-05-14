#include <stdio.h>
int main (void) {
    unsigned int passes = 0, failures = 0, student = 1;
    int result;
    while (student <= 10) {
        scanf("%d", &result);
        if(result == 1) {
            passes++;
            student++;
        }
        if(result == 2) {
            failures++;
            student++;
        }
    }
    printf("Passed %d\n", passes);
    printf("Failed %d\n", failures);
    if (passes > 8) puts("Bonus to insructor");
    return 0;
}