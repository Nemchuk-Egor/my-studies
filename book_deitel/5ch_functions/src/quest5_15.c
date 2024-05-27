#include <stdio.h>
#include <math.h>
double hypotenuse (double a, double b);
int main(void) {
    double a, b;
    scanf("%lf%lf", &a, &b);
    printf("%.2lf", hypotenuse(a,b));
    return 0;
}
double hypotenuse (double a, double b) {
    return sqrt(a * a + b * b);
}