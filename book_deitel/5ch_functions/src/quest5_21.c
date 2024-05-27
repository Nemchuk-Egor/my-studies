#include <stdio.h>
void func(int a, char fill_Character, int b);
int main(void) {
    int a, b;
    char fill_Character;
    scanf("%d %c %d", &a, &fill_Character, &b);
    func(a, fill_Character, b);
    return 0;
}
void func(int a, char fill_Character, int b) {
    if(b == 1) {
        for(int i = 1; i <= a; i++) {
            for(int j = 1; j <= a; j++) printf("%c", fill_Character);
            puts("");
        }
    }
    if(b == 2) {
        for(int i = 1; i <= a; i++) {
            for(int j = a; j >= i; j--) printf("%c", fill_Character);
            puts("");
        }
    }
    if(b == 3) {
        for(int i = 1; i <= a; i++) {
            for(int j = 1; j <= i; j++) printf("%c", fill_Character);
            puts("");
        }        
    }
}