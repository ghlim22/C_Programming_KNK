#include <stdio.h>

int main(void)
{
    int month, date, year;
    printf("enter a date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &month, &date, &year);

    printf("you entered the date: %d/%d/%d\n", year, month, date);

    return 0;
}