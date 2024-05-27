#include <stdio.h>
double min(double x, double y, double z);
int main(void) {
    double x, y, z;
    scanf("%lf%lf%lf", &x, &y, &z);
    printf("%.2lf", min(x,y,z));
    return 0;
}
double min(double x, double y, double z) {
    double min = x;
    if(y < x && y < z) min = y;
    if(z < x && z < y) min = z;
    return min;
}