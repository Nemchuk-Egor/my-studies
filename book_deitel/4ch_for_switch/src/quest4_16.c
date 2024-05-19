#include <stdio.h>
int main(void){
/*A*/
    for(int i = 0; i <= 10; i++) {
        for(int j = 0; j <= i; j++) {
            printf("*");
        }
        puts("");
    }
/*B*/
    for(int i = 0; i <= 10; i++) {
        for(int j = 10; j >= i; j--) {
            printf("*");
        }
        puts("");
    }
/*C*/
    for(int i = 0; i <= 10; i++) {
        for(int j = 1; j <= i; j++) {
            printf(" ");
        }
        for(int g = 10; g >= i; g--) {
            printf("*");
        }
        puts("");
    }
/*D*/
    for(int i = 0; i <= 10; i++) {
        for(int j = 9; j >= i; j--) {
            printf(" ");
        }
        for(int g = 0; g <= i; g++) {
            printf("*");
        }
        puts("");
    }
    return 0;
}