#include <math.h>
#include <stdio.h>
int main(void) {
    int i = 0;
    float x;
    while (i++ != 3) {
        scanf("%f", &x);
        printf("%.2f %.2f\n", x, floor(x + .5));
    }
    return 0;
}