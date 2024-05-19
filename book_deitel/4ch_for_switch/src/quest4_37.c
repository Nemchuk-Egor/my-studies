#include <stdio.h>
int main(void) {
    unsigned int x;
    for(x= 1; x <= 10; x++) {
        if (x == 5) {
            x = 10;
        } else 
            printf("%d ", x);
    }
    return 0;
}