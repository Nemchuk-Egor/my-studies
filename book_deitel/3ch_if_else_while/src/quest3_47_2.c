#include <stdio.h>

int main(void) {
    int i = 1, number, count;
    double e = 1.0, result = 1.0;

    scanf("%d", &number);

    while (i <= number) {
        count = 1;

        while (count <= i) {
            result *= count;
            count++;
        }

        e += 1.0 / result;
        result = 1.0;
        i++;
    }

    printf("%.15f\n", e);

    return 0;
}