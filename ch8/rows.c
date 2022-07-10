#include <stdio.h>

#define ROW_LEN (5)
#define COLUMN_LEN (5)

int main(void)
{
    int array[ROW_LEN][COLUMN_LEN], row_sum[ROW_LEN] = {0}, column_sum[COLUMN_LEN] = {0}, i, j;

    for (i = 0; i < ROW_LEN; ++i)
    {
        printf("Enter student %d's scores: ", i);
        scanf("%d %d %d %d %d", &array[i][0], &array[i][1], &array[i][2], &array[i][3], &array[i][4]);
    }

    for (i = 0; i < ROW_LEN; ++i)
    {
        for (j = 0; j < COLUMN_LEN; ++j)
        {
            row_sum[i] += array[i][j];
            column_sum[i] += array[j][i];
        }
    }

    printf("Row totals: ");
    for (i = 0; i < ROW_LEN; ++i)
    {
        printf("Student %d's total: %d  / average: %.2f \n", i, row_sum[i], row_sum[i] / (float)ROW_LEN);
    }
    printf("\n");

    for (i = 0; i < COLUMN_LEN; ++i)
    {
        printf("Quiz %d average: %.2f ", i, column_sum[i] / (float)COLUMN_LEN);
        int high = 0;
        int low = 100;
        for (j = 0; j < ROW_LEN; ++j)
        {
            if (array[j][i] > high)
            {
                high = array[j][i];
            }
            if (array[j][i] < low)
            {
                low = array[j][i];
            }
        }
        printf("high score: %d low score: %d\n", high, low);
    }

    printf("\n");

    return 0;
}