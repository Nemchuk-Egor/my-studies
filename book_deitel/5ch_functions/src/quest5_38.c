#include <stdio.h>
void fibonaci(int n);
int main(void) {
    int n;
    scanf("%d", &n);
    fibonaci(n);
    return 0;
}
void fibonaci(int n) {
    double first = 0, second = 1, next;
    for (int i = 0; i < n; i++) {
        if (i <= 1)
            next = i;
        else {
            next = first + second;
            first = second;
            second = next;
        }
        printf("%.0lf ", next);
    }
}