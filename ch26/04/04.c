#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
    int month, day, year, n;

    printf("Enter month day year n: ");
    scanf("%d %d %d %d", &month, &day, &year, &n);

    struct tm t;
    t.tm_mday = day;
    t.tm_mon = month;
    t.tm_year = year - 1900;
    t.tm_sec = 0;
    t.tm_min = 0;
    t.tm_hour = 0;
    t.tm_isdst = -1;

    t.tm_mday += n;
    mktime(&t);

    printf("%s\n", asctime(&t));

    return 0;
}