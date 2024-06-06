#include <stdio.h>
void func(int a);
int main(void) {
    int a;
    scanf("%d", &a);
    func(a);
    return 0;
}
void func(int a) {
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= a; j++) printf("*");
        puts("");
    }
}