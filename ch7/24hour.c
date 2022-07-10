#include <stdio.h>

int main(void)
{
    int hour, min;
    char noon;
    printf("Enter a 12-hour time: ");
    scanf("%d:%d %c", &hour, &min, &noon);

    if (noon == 'P' || noon == 'p')
    {
        if (hour != 12)
        {
            hour += 12;
        }
    }

    printf("Equivalent 24-hour time: %d:%d\n", hour, min);

    return 0;
}