#include <stdio.h>
void printCharacters (const char *sPtr);
int main(void) {
    char string[] = "characters and $32.98";
    puts("The string is: ");
    printCharacters(string);
    puts("");
    return 0;
}
void printCharacters(const char *sPtr){
    while (*sPtr != '\0') {
        printf("%c", *sPtr);
        ++sPtr;
    }
}