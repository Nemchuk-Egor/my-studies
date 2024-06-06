#include <stdio.h>
#define SIZE 9
#define BASE_SALARY 200
#define RATE 0.09
int main(void) {
    int a[SIZE] = {0};
    double sell;
    for(int i = 0; i < SIZE; i++) {
        scanf("%lf", &sell);
        double zarp = BASE_SALARY + sell * RATE;
        int index = (zarp - BASE_SALARY) / 100;
        if(index >= 0 && index < SIZE) a[index]++;
        else if(index >= SIZE) a[SIZE - 1]++;
    }
    int total = 0;
    for(int i = 0; i < SIZE; i++) {
        if(i < SIZE - 1) printf("%d. $%d-$%d is %d\n", i + 1, BASE_SALARY + total, BASE_SALARY + total + 99, a[i]);
        else printf("%d. $%d- and over is %d\n", i + 1, BASE_SALARY + total, a[i]);
        total += 100;
    }
    return 0;
}