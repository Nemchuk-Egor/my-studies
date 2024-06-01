#include <stdio.h>
#include <math.h>
float distance(void);
int main(void) {
    printf("%.0f",distance());
    return 0;
}
float distance(void) {
    float x1,y1,x2,y2;
    scanf("%f%f%f%f", &x1, &y1, &x2, &y2);
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}