/*a
#include <stdio.h>
void prost(int number);
int main(void){
    int number;
    scanf("%d", &number);
    prost(number);
    return 0;
}
void prost(int number) {
    int count = 0;
    for(int i = number; i >= 1; i--) {
        if(number % i == 0) count++;
    }
    count == 2 ? puts("YES") : puts("NO");
}*/
/*b*/
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
bool prost(int number);
int main(void){
    for(int i = 1; i <= 100; i++) {
        if(prost(i)) printf("%d ", i);
    }
    return 0;
}
bool prost(int number) {
    for(int i = 2; i <= sqrt(number); i++) {
        if(number % i == 0) return false; 
    }
    return true;
}