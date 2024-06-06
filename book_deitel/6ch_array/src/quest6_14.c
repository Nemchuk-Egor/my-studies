#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 99
void mean(const int answer[]);
void median(int answer[]);
void mode(int freq[], const int answer[]);
void bublesort(int a[]);
void printArray(const int a[]);
int main(void) {
    int frequency[10] = {0};
    int response[SIZE] = {0};
    for (int i = 0; i < SIZE; i++) response[i] = 1 + rand() % 9;
    mean(response);
    median(response);
    mode(frequency, response);
    return 0;
}
void mean(const int answer[]) {
    int total = 0;
    printf("%s\n%s\n%s\n", "*******", " MEAN", "*******");
    for (int i = 0; i < SIZE; i++) total += answer[i];
    printf(
        "The mean is the average value of the data\n"
        "items. The mean is equal to the total of \n"
        "all the data items divided by tge number\n"
        "of data items (%d). The mean value for \n"
        "this run is %d / %d = %.4f\n\n",
        SIZE, total, SIZE, (double)total / SIZE);
}
void median(int answer[]) {
    printf("\n%s\n%s\n%s\n%s", "*******", "Median", "*******", "The unsorted array of responses is");
    printArray(answer);
    bublesort(answer);
    printf("%s", "\n\nThe sorted array is");
    printArray(answer);
    printf(
        "\n\nThe median is selement %d of\n"
        "the sorted %d element array. \n"
        "For this run the median is %d\n\n",
        SIZE / 2, SIZE, answer[SIZE / 2]);
}
void mode(int freq[], const int answer[]) {
    int largest = 0;
    int modeValue = 0;
    printf("\n%s\n%s\n%s\n", "*******", "Mode", "********");
    for (int i = 1; i <= 9; i++) freq[i] = 0;
    for (int i = 0; i < SIZE; i++) ++freq[answer[i]];
    printf("%s%11s%19s\n\n%54s\n%54s\n\n", "Response", "Frequency", "Histogramm", "1 1 2 2", "5 0 5 0 5");
    for (int i = 1; i <= 9; i++) printf("%8d%11d        ", i, freq[i]);
    if (freq[]) }