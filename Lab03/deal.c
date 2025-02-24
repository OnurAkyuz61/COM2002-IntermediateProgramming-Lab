#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SUITS 4
#define NUM_RANKS 13

int main() {
    const char *suits[] = {"clubs", "diamonds", "hearts", "spades"};
    const char *ranks[] = {"Two", "Three", "Four", "Five", "Six", "Seven","Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"};
    
    int num_cards;
    int cards_dealt[NUM_SUITS][NUM_RANKS] = {0}; // Track dealt cards
    
    // Initialize random number generator
    srand((unsigned) time(NULL));
    
    printf("Enter number of the cards in hand: ");
    scanf("%d", &num_cards);
    
    if (num_cards < 1 || num_cards > 52) {
        printf("Invalid number of cards. Please enter a number between 1 and 52.\n");
        return 1;
    }
    
    printf("Your hand:\n");
    
    // Deal the cards
    for (int i = 0; i < num_cards; i++) {
        int suit, rank;
        
        // Keep generating random cards until we find one that hasn't been dealt
        do {
            suit = rand() % NUM_SUITS;
            rank = rand() % NUM_RANKS;
        } while (cards_dealt[suit][rank]);
        
        // Mark the card as dealt
        cards_dealt[suit][rank] = 1;
        
        // Print the card
        printf("%s of %s\n", ranks[rank], suits[suit]);
    }
    
    return 0;
}
