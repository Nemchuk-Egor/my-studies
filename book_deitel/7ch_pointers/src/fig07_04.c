#include <stdio.h>
int main(void) {
    int a;
    int *aPtr;
    a = 7;
    aPtr = &a;
    /* Адрес переменной а и содержимое переменной аПтр совпадают
    отсюда делаем вывод что в переменной аПтр находится адрес переменной а*/
    printf("The address of a is %p"
    "\nThe value of aPtr is %p", &a, aPtr);
    /* значения переменной идентичный так как мы возвращаем с помощью * значение переменной а*/
    printf("\n\nThe value of a is %d"
    "\nThe value of *aPtr is %d", a, *aPtr);
    printf("\n\nShowing tha * and & are complements of "
    "each other\n&*aPtr = %p"
    "\n*&aPtr = %p\n", &*aPtr, *&aPtr);
    return 0;
}