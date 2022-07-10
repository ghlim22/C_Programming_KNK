#include <stdio.h>

#define NUM_NUMS (10);
#define NUM_SEGMENTS (7);

int main(void)
{
    const int segments[10][7] =
        {{1, 1, 1, 1, 1, 1},
         {[1] = 1, [2] = 1},
         {[0] = 1, [1] = 1, [3] = 1, [4] = 1, [6] = 1},
         {1, 1, 1, 1, [6] = 1},
         {[1] = 1, [2] = 1, [5] = 1, [6] = 1},
         {1, 0, 1, 1, 0, 1, 1},
         {1, 0, 1, 1, 1, 1, 1},
         {1, 1, 1},
         {1, 1, 1, 1, 1, 1, 1},
         {1, 1, 1, 1, 0, 1, 1}};

    int temperature_readings[30][24];
    float month_average = 0.00f, day_average, sum, num_days, num_hours;
    for (int i = 0; i < 30; ++i)
    {
        sum = 0.00f;
        for (int j = 0; j < 24; ++j)
        {
            sum += temperature_readings[i][j];
        }
        month_average += sum / 24.00f;
    }

    printf("Month temperature average: %6.2f", month_average / 30.00f);

    char chess_board[8][8] =
        {
            {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
            {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
            {' ', '.', ' ', '.', ' ', ' ', ' ', '.'},
            {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
            {' ', '.', ' ', '.', ' ', ' ', ' ', '.'},
            {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
            {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
            {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}};

    char checker_board[8][8];
    printf("\n");

    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            if ((i + j) % 2 == 0)
            {
                checker_board[i][j] = 'B';
            }
            else
            {
                checker_board[i][j] = 'R';
            }
            printf("%c%c", checker_board[i][j], j == 7 ? '\n' : ' ');
        }
    }
}