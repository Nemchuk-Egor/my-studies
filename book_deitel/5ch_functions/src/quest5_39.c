#include <stdio.h>
#include <time.h>

void hanoi(int n, char A, char B, char C, double *steps);

int main() {
    int n;
    double start, end, steps = 1;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    printf("Moves:\n");

    start = (double)clock() / CLOCKS_PER_SEC;

    hanoi(n, '1', '2', '3', &steps);

    end = (double)clock() / CLOCKS_PER_SEC;
    printf("%lf", end - start);

    return 0;
}

void hanoi(int n, char A, char B, char C, double *steps) {
    if (n == 1) {
        printf("%c > %c - %.0lf\n", A, C, (*steps));
        (*steps)++;
    } else {
        hanoi(n - 1, A, C, B, steps);
        printf("%c > %c - %0.lf\n", A, C, (*steps));
        (*steps)++;
        hanoi(n - 1, B, A, C, steps);
    }
}
