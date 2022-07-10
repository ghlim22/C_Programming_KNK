#include <stdio.h>

int main(void)
{
    int hour, min;
    char *noon;

    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hour, &min);

    if (hour > 12)
    {
        hour -= 12;
        noon = "PM";
    }
    else if (hour == 12)
    {
        noon = "PM";
    }
    else
    {
        noon = "AM";
    }

    printf("Equivalent 12-hour time: %d:%.2d %s\n", hour, min, noon);

    return 0;
}