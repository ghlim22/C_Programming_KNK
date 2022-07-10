#include <stdio.h>

int main(void)
{
    int month, date, year, e_month, e_date, e_year;

    e_year = 9999;

    while (1)
    {
        printf("Enter date: ");
        scanf("%d/%d/%d", &month, &date, &year);

        if (month == 0 || date == 0 || year == 0)
        {
            break;
        }

        if (year < e_year)
        {
            e_year = year;
            e_month = month;
            e_date = date;
        }
        else if (year == e_year && month < e_month)
        {
            e_year = year;
            e_month = month;
            e_date = date;
        }
    }

    printf("The earliest date: %d/%d/%d\n", e_month, e_date, e_year);

    return 0;
}