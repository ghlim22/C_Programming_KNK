#include <stdio.h>

#define WEEK_LENGTH (7)

int main(void)
{
    int first_day, last_date;
    printf("Enter the first day of month(sun - 0; sat - 6): ");
    scanf("%d", &first_day);
    printf("Enter the last date of month: ");
    scanf("%d", &last_date);

    int count = 0;
    printf("sun mon tue wed thu fri sat\n");
    for (int i = 0; i < first_day; ++i)
    {
        printf("    ");
        count++;
    }
    for (int i = 1; i <= last_date; ++i)
    {
        count++;
        printf("%3d%c", i, (count % 7 == 0) ? '\n' : ' ');
    }
    printf("\n");

    return 0;
}