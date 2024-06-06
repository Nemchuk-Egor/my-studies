#include <math.h>
#include <stdio.h>
float roundToInteger(float number);
float roundToTenth(float number);
float roundToHunreths(float number);
float roundToThousandths(float number);
int main(void) {
    int i = 0;
    float x;
    while (i++ != 3) {
        scanf("%f", &x);
        printf("%.4f %.4f\n", x, roundToInteger(x));
        printf("%.4f %.4f\n", x, roundToTenth(x));
        printf("%.4f %.4f\n", x, roundToHunreths(x));
        printf("%.4f %.4f\n", x, roundToThousandths(x));
    }
    return 0;
}
float roundToInteger(float number) { return number = floor(number * 10 + .5) / 10; }
float roundToTenth(float number) { return number = floor(number * 100 + .5) / 100; }
float roundToHunreths(float number) { return number = floor(number * 1000 + .5) / 1000; }
float roundToThousandths(float number) { return number = floor(number * 10000 + .5) / 10000; }