#include <stdio.h>
int main(void){
    int number, quantity, count = 0;
    float total; 
    while (count++ != 5) {
        scanf("%d", &number);
        scanf("%d", &quantity);
        switch (number)
        {
        case 1:
            total += (float)quantity * 2.98;
            break;
        case 2:
            total += (float)quantity * 4.50;
            break;
        case 3:
            total += (float)quantity * 9.98;
            break;
        case 4:
            total += (float)quantity * 4.49;
            break;
        case 5:
            total += (float)quantity * 6.87;
            break;
        default:
            puts("Fail input");
            break;
        }       
    }
    printf("%.2f", total);
    return 0;
}