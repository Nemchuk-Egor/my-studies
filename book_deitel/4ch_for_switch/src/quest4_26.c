#include <stdio.h>
int main(void) {
    double pi = 4.0;
    int sign = -1;
    for (int i = 3; ; i += 2) {
        double temp = 4.0 / i;
        pi += sign * temp;
        printf("%f\n", pi);
        sign *= -1;
        if(pi >= 3.14159) break;
    }
    return 0;
}