#include <stdio.h>
float calculateCharges(float hours);
int main(void) {
    float car1, car2, car3, hours1, hours2, hours3;
    scanf("%f%f%f", &hours1, &hours2, &hours3);
    car1 = calculateCharges(hours1);
    car2 = calculateCharges(hours2);
    car3 = calculateCharges(hours3);
    printf("%s%12s%12s\n", "Car", "Hours", "Charge");
    printf("1%12.2f%12.2f\n", hours1, car1);
    printf("2%12.2f%12.2f\n", hours2, car2);
    printf("3%12.2f%12.2f\n", hours3, car3);
    printf("TOTAL%8.2f%12.2f\n", hours1 + hours2 + hours3, car1 + car2 + car3);
    return 0;
}
float calculateCharges(float number) {
    float charges;
    if (number <= 3.0) charges = 2.00;
    if (number > 3.0) charges = (number - 3.0) * 0.50 + 2.0;
    if (charges > 10.0) charges = 10.0;
    return charges;
}