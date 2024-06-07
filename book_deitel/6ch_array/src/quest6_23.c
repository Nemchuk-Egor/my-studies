#include <stdio.h>
#include <stdbool.h>
#define X 50
#define Y 50

int main(void) {
    int array[X][Y];
    int end = 1;
    bool flag = true;
    while(end != 9)
        sacnf("%d", &end);
        switch (end)
        {
        case 1:
            flag = false;
            break;
        case 2:
            flag = true;
            break;
        case 3:
            break;
        case 4:
            break;
        case 6:
            break;
        case 9:
            break;

        default:
            break;
        }
    return 0;
}