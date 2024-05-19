#include <stdio.h>
int main(void) {
/* a */
    int value;
    for (int x = 100; x >= 1; x--) 
        printf("%d\n", x);
/* b */
    scanf("%d", &value);
    switch (value % 2) {
        case 0:
            printf("Even integer\n");
            break;
        case 1:
            printf("Odd integer\n");
            break;
        default:
            printf("Fail\n");
            break;
    }
/* c */
    int intVal;
    char charval;
    scanf("%d ", &intVal);
    charval = getchar();
    printf("Integer %d\nCharacter %c\n", intVal, charval);
/* d */
    for(float x = .000001; x <= .0001; x += .000001)
        printf("%.7f\n", x);
/* e */
    for (int x = 999; x >= 1; x -= 2)
        printf("%d\n", x);
/* f */
    int counter = 2;
    do {
        if (counter % 2 == 0)
            printf("%d\n", counter);
        counter++;
    } while (counter <= 100);
/* g */
    int total = 0;
    for (int x = 100; x <= 150; x++)
        total += x;
    printf("%d", total);
    return 0;
}