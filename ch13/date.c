#include <stdio.h>

int main(void)
{
    char *months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int month, date, year;
    printf("Enter a date (mm/dd/yyyy): ");
    scanf("%d/ %d/ %d", &month, &date, &year);

    printf("You entered the date %s %d, %d\n", months[month - 1], date, year);

    return 0;
}
