#include <stdio.h>
int multiple (int a, int b);
int main(void) {
    int a, b;
    scanf("%d%d", &a, &b);
    multiple(a, b) == 1 ? puts("yes") : puts("no");
    return 0;
}
int multiple(int a, int b) {
    if(b % a == 0) return 1;
    else return 0;
}