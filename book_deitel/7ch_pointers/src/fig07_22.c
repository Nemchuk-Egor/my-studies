#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 4
#define COLUMN 13
void shuffle(int deck[][COLUMN]);
void deal(const int wDeck[][COLUMN], const char *wFace[],
    const char *wSuit[]);
int main(void) {
    const char *suit[ROW] = {"Hearts", "Diamonds", "Clubs", "Spaders"};
    const char *face[COLUMN] = {"Ace", "Deuce", "Three", "Four", "Five",
    "Six", "Seven", "Eight", "Nine",
    "Ten", "Jack", "Queen", "King"};
    int deck[ROW][COLUMN] = {0};
    srand(time(NULL));
    shuffle(deck);
    deal(deck, face, suit);
}
void shuffle(int deck[][COLUMN]) {
    int count = 1;
    int i,j;
    while(count++ <= 52) {
        do {
            i = rand() % 4;
            j = rand() % 13;
        } while (deck[i][j] != 0);
        deck[i][j] = count;
    }
}
void deal(const int wDeck[][COLUMN], const char *wFace[],
    const char *wSuit[]) {
        int count = 1;
        for(count = 1; count <= 52; count++) {
            for(int i = 0; i < ROW; i++) {
                for(int j = 0; j < COLUMN; j++) {
                    if(wDeck[i][j] == count)
                        printf("%5s of %-8s%c", *(wFace + j), *(wSuit + i), count % 2 == 0 ? '\n' : '\t');
                }
            }
        }
}
