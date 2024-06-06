#include <stdio.h>
int main(void) {
    int min, number, input;
    scanf("%d%d", &number, &min);
    for (int x = 1; x <= number - 1; x++) {
        scanf("%d", &input);
        if (input < min) min = input;
    }
    printf("%d", min);
    return 0;
}