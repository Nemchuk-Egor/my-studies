#include <stdio.h>
int main(void) {
    int row, column, count = 0;
    int sales[3][5];
    for(row = 0; row <= 2; row++) {
        for(column = 0; column <= 4; column++) {
            sales[row][column] = 0;
            count++;
            printf("%2d. row [%d] column [%d] = %d\n", count, row, column, sales[row][column]);
        }
    }
    return 0;
}