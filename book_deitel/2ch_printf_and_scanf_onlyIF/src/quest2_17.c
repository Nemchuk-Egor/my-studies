#include <stdio.h>
/* Написать программу выводящую на печать числа от одного до 4 тремя способами
 */

int main(void) {
    int n1 = 1, n2 = 2, n3 = 3, n4 = 4;
    printf("1 2 3 4\n");
    printf("%d %d %d %d\n", n1, n2, n3, n4);
    printf("%d ", n1);
    printf("%d ", n2);
    printf("%d ", n3);
    printf("%d \n", n4);
    return 0;
}