#include <stdio.h>
int mystery (int a, int b);
int main (void) {
    int x;
    int y;
    printf("%s", "Enter two integers ");
    scanf("%d%d", &x, &y);
    printf("The result %d\n", mystery(x, y));
    return 0;
}
int mystery(int a, int b) {
    if( b == 1) return a;
    else return a + mystery(a, b - 1);
}