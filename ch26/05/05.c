#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
    struct tm t1, t2;

    t1.tm_sec = 0;
    t1.tm_min = 0;
    t1.tm_hour = 0;
    t1.tm_isdst = -1;
    t2 = t1;

    printf("Date1\nEnter month/day/year: ");
    scanf("%d/%d/%d", t1.tm_mon, t1.tm_mday, t1.tm_year);
    t1.tm_mon--;
    t1.tm_year -= 1900;

    printf("Date2\nEnter month/day/year: ");
    scanf("%d/%d/%d", t2.tm_mon, t2.tm_mday, t2.tm_year);
    t2.tm_mon--;
    t2.tm_year -= 1900;

    printf("The difference between two days: %d", (int)(difftime(mktime(&t2), mktime(&t1)) / 60 / 60 / 24));
}