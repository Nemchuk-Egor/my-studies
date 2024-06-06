#include <stdio.h>
int main(void) {
    int year;
    scanf("%d", &year);
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
        year = 1;
    else
        year = 0;
    for (int i = 1; i <= 2; i++) {
        int moth = 0;
        if (i == 1) {
            printf("%23s\n", "Январь");
            moth = 31;
        }
        if (i == 2) {
            printf("%23s\n", "Февраль");
            moth = 28 + year;
        }
        for (int j = 1; j <= moth; j++) {
            printf("%3d ", j);
            if (j % 7 == 0) puts("");
        }
        puts("");
    }
    return 0;
}