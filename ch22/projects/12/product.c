#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    FILE *output;
    int number, date, month, year;
    float price;
    bool is_exist;

    if (argc != 2)
    {
        fprintf(stderr, "Usage: product output_file");
        return 1;
    }

    if (access(argv[1], F_OK) != -1)
    {
        // if file exists
        if ((output = fopen(argv[1], "a")) == NULL)
        {
            return 1;
        }
        is_exist = true;
    }
    else
    {
        // if file doesn't exist.
        if ((output = fopen(argv[1], "w")) == NULL)
        {
            return 1;
        }
        is_exist = false;
    }

    printf("enter item number: ");
    scanf("%d", &number);

    printf("enter unit price: ");
    scanf("%f", &price);

    printf("enter purchase date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &date, &month, &year);

    if (!is_exist)
    {

        fprintf(output, "%-8s%-8s%-8s\n\t%-8s%-8s\n", "Item", "Unit", "Purchase", "Price", "Date");
    }
    fprintf(output, "%-8d$%5.2f%d/%d/%d\n", number, price, month, date, year);

    return 0;
}