#include <stdio.h>

void create_magic_square(int size, char magic_square[size][size]);
void print_magic_square(int size, char magic_square[size][size]);

int main(void)
{
    int size;

    printf("This program creates a magic square of a specified size.\n");
    printf("The size must be an odd number between 1 and 99.\n");
    printf("Enter size of magic square: ");
    scanf("%d", &size);
    char magic_square[size][size];

    create_magic_square(size, magic_square);
    print_magic_square(size, magic_square);

    return 0;
}

void create_magic_square(int size, char magic_square[size][size])
{
    int row = 0;
    int column = size / 2;

    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            magic_square[i][j] = 0;
        }
    }
    magic_square[row][column] = 1;

    for (int i = 2; i <= size * size; ++i)
    {
        int row_move, column_move;

        if (row == 0)
        {
            row_move = size - 1;
        }
        else
        {
            row_move = -1;
        }

        if (column == size - 1)
        {
            column_move = -(size - 1);
        }
        else
        {
            column_move = 1;
        }

        if (magic_square[row + row_move][column + column_move] != 0)
        {
            row_move = 1;
            column_move = 0;
        }
        row += row_move;
        column += column_move;

        magic_square[row][column] = i;
    }
}

void print_magic_square(int size, char magic_square[size][size])
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            printf("%3d ", magic_square[i][j]);
        }

        printf("\n");
    }
}