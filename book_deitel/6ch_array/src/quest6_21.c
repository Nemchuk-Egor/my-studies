#include <stdio.h>
#define SIZE 10
int inputClass(void);
int ticket(int a[], int class);
void printTicket(int class, int place);
void printArray(const int a[], int size);
int main(void) {
    int class, count = 0;
    int a[SIZE] = {0};
    while (count != SIZE) {
        class = inputClass();
        if (ticket(a, class)) count++;
        printArray(a, SIZE);
    }
    return 0;
}
int inputClass(void) {
    int number;
    puts("Введите 1 для \"Для первого класса\"");
    puts("Введите 2 для \"Для экономического класса\"");
    scanf("%d", &number);
    return number;
}
int ticket(int a[], int class) {
    int i;
    if (class == 1) {
        for (i = 0; i <= SIZE - 5; i++) {
            if (a[i] == 0 && i <= SIZE - 6) {
                a[i]++;
                printTicket(class, i);
                return 1;
            } else
                continue;
        }
        if (i > SIZE - 5) puts("Следующий рейс через 3 часа");
    } else {
        for (i = 5; i < SIZE; i++) {
            if (a[i] == 0 && i <= SIZE - 1) {
                a[i]++;
                printTicket(class, i);
                return 1;
            } else
                continue;
        }
        if (i >= SIZE) puts("Следующий рейс через 3 часа");
    }
    return 0;
}
void printTicket(int class, int place) {
    if (class == 1) printf("Ваша место %d У вас первый класс \n", place + 1);
    if (class == 2) printf("Ваша место %d У вас эконом класс \n", place + 1);
    puts("");
}
void printArray(const int a[], int size) {
    int i;
    puts("Места в первом классе");
    for (i = 0; i < size - 5; i++) printf("%d ", a[i]);
    puts("");
    puts("Места в эконом классе");
    for (i = 5; i < size; i++) printf("%d ", a[i]);
    printf("\n\n");
}
