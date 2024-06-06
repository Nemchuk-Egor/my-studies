#include <stdio.h>
int main(void) {
    /* a */
    for (int x = 0; x <= 7; x++) printf("%d ", x);
    /* b */
    puts("");
    for (int x = 3; x <= 23; x += 5) printf("%d ", x);
    /* c */
    puts("");
    for (int x = 20; x >= -10; x -= 6) printf("%d ", x);
    /* d */
    puts("");
    for (int x = 19; x <= 51; x += 8) printf("%d ", x);
    return 0;
}