#include <stdio.h>

int main(void)
{
    int number, date, month, year;
    float price;

    printf("enter item number: ");
    scanf("%d", &number);

    printf("enter unit price: ");
    scanf("%f", &price);

    printf("enter purchase date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &date, &month, &year);

    printf("%-8s%-8s%-8s\n\t%-8s%-8s\n", "Item", "Unit", "Purchase", "Price", "Date");
    printf("%-8d$%5.2f%d/%d/%d\n", number, price, month, date, year);

    return 0;
}