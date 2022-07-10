#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define CARDS_MAX (5)
#define NUM_IN_RANK (13)
#define NUM_IN_SUIT (4)

int ranks[NUM_IN_RANK];
int suits[NUM_IN_SUIT];
bool three, four, straight, flush;
int pair_cnt, rank_cnt;

void get_in_hand(void);
void analyze_hand(void);
void print_result(void);

int main(void)
{
    get_in_hand();
    analyze_hand();
    print_result();

    return 0;
}

void get_in_hand(void)
{
    char ch;
    /*
    int rank = getchar();
    int suit = getchar();
    while ((ch = getchar()) != '\n')
    {
        //
    }
    */
    int rank;
    int suit;

    for (int i = 0; i < CARDS_MAX; ++i)
    {
        printf("Enter a card: ");
        scanf(" %d %d", &rank, &suit);

        ranks[rank]++;
        suits[suit]++;
    }
}

void analyze_hand(void)
{
    pair_cnt = 0;
    rank_cnt = 0;
    bool isConsecutive = true;
    for (int i = 0; i < NUM_IN_RANK; ++i)
    {
        switch (ranks[i])
        {
        case 1:
            // rank_cnt++;
            break;
        case 2:
            pair_cnt++;
            isConsecutive = false;
            break;
        case 3:
            three = true;
            isConsecutive = false;
            break;
        case 4:
            four = true;
            isConsecutive = false;
            break;
        case 5:
            four = true;
            pair_cnt++;
            break;
        default:
            // isConsecutive = false;
            break;
        }
    }
    if (isConsecutive)
    {
        for (int i = 0; i < NUM_IN_RANK - CARDS_MAX; ++i)
        {
            if ((ranks[i] + ranks[i + 1] + ranks[i + 2] + ranks[i + 3] + ranks[i + 4]) == 5)
            {
                straight = true;
            }
        }
    }

    for (int i = 0; i < NUM_IN_SUIT; ++i)
    {
        if (suits[i] == 5)
        {
            flush = true;
            break;
        }
    }
}

void print_result(void)
{
    if (straight && flush)
    {
        printf("Straight flush\n");
        return;
    }
    if (four)
    {
        printf("Four of a kind\n");
        return;
    }
    if (three && pair_cnt == 3)
    {
        printf("Full house\n");
        return;
    }
    if (flush)
    {
        printf("flush\n");
        return;
    }
    if (straight)
    {
        printf("Straight\n");
        return;
    }
    if (three)
    {
        printf("Three of a kind\n");
        return;
    }
    if (pair_cnt >= 2)
    {
        printf("Two pairs\n");
        return;
    }
    if (pair_cnt == 1)
    {
        printf("Pair\n");
        return;
    }
    printf("High card\n");
    return;
}
