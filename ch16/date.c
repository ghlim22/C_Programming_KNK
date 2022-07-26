#include <stdio.h>

typedef struct date
{
    int month;
    int day;
    int year;
} Date;

int main(void)
{
    Date d;

    printf("Enter date (mm/dd/yy): ");
    scanf("%d/%d/%d", &d.month, &d.day, &d.year);

    printf("Dated this %d", d.day);

    switch (d.day)
    {
    case 1:
    case 21:
    case 31:
        printf("st");
        break;
    case 2:
    case 22:
        printf("nd");
        break;
    case 3:
    case 23:
        printf("rd");
    default:
        printf("th");
        break;
    }

    printf(" day of ");

    switch (d.month)
    {
    case 1:
        printf("January");
        break;
    case 2:
        printf("Feburary");
        break;
    case 3:
        printf("March");
        break;
    case 4:
        printf("April");
        break;
    case 5:
        printf("May");
        break;
    case 6:
        printf("June");
        break;
    case 7:
        printf("July");
        break;
    case 8:
        printf("August");
        break;
    case 9:
        printf("September");
        break;
    case 10:
        printf("October");
        break;
    case 11:
        printf("November");
        break;
    case 12:
        printf("December");
        break;
    default:
        break;
    }

    printf(", 20%.2d\n", d.year);

    return 0;
}