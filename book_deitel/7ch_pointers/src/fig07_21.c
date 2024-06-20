#include <stdio.h>
void copy1(char *s1, const char *s2);
void copy2(char *s1, const char *s2);
int main(void){
    char string1[10];
    char string2[] = "Hello";
    char string3[10];
    char string4[] = "good by";
    copy1(string1, string2);
    printf("%s", string1);
    copy2(string3, string4);
    printf("\n%s", string3);
    return 0;
}
void copy1(char *s1, const char *s2) {
    for(int i = 0; (s1[i] = s2[i]); i++);
}
void copy2(char *s1, const char *s2) {
    for(;(*s1 = *s2); ++s1, ++s2);
}
