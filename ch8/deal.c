#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define NUM_SUITS (4)
#define NUM_RANK (13)

int main(void)
{
    bool in_hand[4][13] = {false};

    const char rank_code[13] = {'2', '3', '4', '5', '6', '7', '8', '9', 't', 'j', 'q', 'k', 'a'};
    const char suit_code[4] = {'c', 'd', 'h', 's'};
    int num_cards, rank, suit;

    srand((unsigned)time(NULL));

    printf("Enter number of cards in hand: ");
    scanf("%d", &num_cards);

    printf("Your hand: ");
    while (num_cards > 0)
    {
        suit = rand() % NUM_SUITS;
        rank = rand() % NUM_RANK;

        if (!in_hand[suit][rank])
        {
            in_hand[suit][rank] = true;
            num_cards--;
            printf(" %c%c", suit_code[suit], rank_code[rank]);
        }
    }
    printf("\n");

    return 0;
}