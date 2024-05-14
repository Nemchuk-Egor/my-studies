#include <stdio.h>

int main(void) {
    unsigned int total_distance = 0;
    int distance;
    float fuel, total_fuel = 0;
    printf("%s", "Введите расход бензина (-1 если ввод закончен): ");
    scanf("%f", &fuel);
    while (fuel != -1) {
        printf("%s", "Введите пройденный путь: ");
        scanf("%d", &distance);
        printf("Для этой заправки получено миль/галон %f\n", distance / fuel);
        total_distance += distance;
        total_fuel += fuel;
        printf("%s", "Введите расход бензина (-1 если ввод закончен): ");
        scanf("%f", &fuel);
    }
    if (total_distance != 0) printf("Среднее число миль/галон %f\n", total_distance / total_fuel);
    return 0;
}