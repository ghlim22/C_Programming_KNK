#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE (10)
#define UP (0)
#define RIGHT (1)
#define DOWN (2)
#define LEFT (3)

void generate_random_walk(char map[10][10]);
void print_array(char map[10][10]);

int main(void)
{
    char map[MAP_SIZE][MAP_SIZE];
    generate_random_walk(map);
    print_array(map);

    return 0;
}

void generate_random_walk(char map[10][10])
{
    int i, j, count = 0, direction, row = 0, column = 0, row_move = 0, column_move = 0;

    for (i = 0; i < MAP_SIZE; ++i)
    {
        for (j = 0; j < MAP_SIZE; ++j)
        {
            map[i][j] = '.';
        }
    }

    map[row][column] = 'A';
    count = 1;

    srand((unsigned)time(NULL));

    while (count < 26)
    {
        direction = rand() % 4;
        row_move = 0;
        column_move = 0;

        switch (direction)
        {
        case UP:
            row_move = -1;
            break;
        case RIGHT:
            column_move = 1;
            break;
        case DOWN:
            row_move = 1;
            break;
        case LEFT:
            column_move = -1;
            break;
        default:
            break;
        }

        if (row + row_move < 0 || row + row_move > MAP_SIZE - 1)
        {
            continue;
        }
        if (column + column_move < 0 || column + column_move > MAP_SIZE - 1)
        {
            continue;
        }

        if (map[row + row_move][column + column_move] != '.')
        {
            continue;
        }

        if (map[row + 1][column] != '.' && map[row][column + 1] != '.' && map[row - 1][column] != '.' && map[row][column - 1] != '.')
        {
            break;
        }

        row += row_move;
        column += column_move;
        map[row][column] = 'A' + count;
        count++;
    }
}

void print_array(char map[10][10])
{
    int i, j;
    for (i = 0; i < MAP_SIZE; ++i)
    {
        for (j = 0; j < MAP_SIZE; ++j)
        {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}