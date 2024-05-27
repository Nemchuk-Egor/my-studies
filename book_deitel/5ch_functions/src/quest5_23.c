#include <stdio.h>
int time_oclock(int hous, int min, int sec);
int main(void) {
    int hous, min, sec;
    scanf("%d%d%d", &hous, &min, &sec);
    printf("%d", time_oclock(hous, min, sec));
    return 0;
}
int time_oclock(int hous, int min, int sec) {
    if(hous >= 12) hous -= 12;
    return hous * 3600 + min * 60 + sec;
}