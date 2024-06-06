#include <stdio.h>
void func(int a, char fill_Character);
int main(void) {
    int a;
    char fill_Character;
    scanf("%d %c", &a, &fill_Character);
    func(a, fill_Character);
    return 0;
}
void func(int a, char fill_Character) {
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= a; j++) printf("%c", fill_Character);
        puts("");
    }
}