#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int roll_dice(void);
bool play_game(int point);

int main(void)
{
    char input;
    int point = 0, win = 0, lose = 0;
    srand((unsigned)time(NULL));

    do
    {
        point = roll_dice();
        printf("You rolled: %d\n", point);
        if (point == 7 || point == 11)
        {
            printf("You win!\n");
            win++;
        }
        else if (point == 2 || point == 3 || point == 12)
        {
            printf("You lose!\n");
            lose++;
        }
        else
        {
            if (play_game(point))
            {
                win++;
            }
            else
            {
                lose++;
            }
        }

        printf("Play again? ");
        scanf(" %c", &input);
    } while (input == 'Y' || input == 'y');

    printf("Wins: %-3dLosses:%-3d\n", win, lose);

    return 0;
}

int roll_dice(void)
{
    int dice1 = rand() % 6 + 1;
    int dice2 = rand() % 6 + 1;

    return dice1 + dice2;
}

bool play_game(int point)
{
    int num = roll_dice();
    printf("You rolled: %d\n", num);

    if (num == 7)
    {
        printf("You lose!\n");
        return false;
    }
    if (num == point)
    {
        printf("You win!\n");
        return true;
    }

    return play_game(point);
}