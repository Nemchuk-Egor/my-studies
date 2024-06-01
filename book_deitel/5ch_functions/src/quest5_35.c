#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void) {
    srand(time(NULL));
    int number = 1 + rand() % 1000;
    printf("%d\n", number);
    int input = 0;
    while(input != number) {
        scanf("%d", &input);
        if(input == number) {
            int choice;
            puts("Превосходно вы уадали число!\nНе желаете попробовать еще раз?");
            scanf("%d", &choice);
            if(choice == 1) {
                input = 0;
                number = 1 + rand() % 1000;
                continue;
            } else break;
        }
        if(input > number) puts("Слишком большое попробуйте еще раз");
        else puts("Слишком маленькое, попробуйте еще раз");
    }
    return 0;
}
