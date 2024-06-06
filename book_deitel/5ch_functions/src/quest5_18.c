#include <stdio.h>
int even(int a);
int main(void) {
    int a;
    for (int x = 1; x <= 5; x++) {
        scanf("%d", &a);
        even(a) == 1 ? puts("Yes") : puts("No");
    }
    return 0;
}
int even(int a) {
    if (a % 2 == 0)
        return 1;
    else
        return 0;
}