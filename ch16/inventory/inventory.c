#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "readline.h"

#define MAX_LEN (100)
#define NAME_LEN (20)

typedef struct
{
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
    int price;
} Part;

int find_part(int num);
void insert(void);
void search(void);
void update(void);
void print(void);
void update_price(void);

Part inventory[MAX_LEN];
int num_parts = 0;

int main(void)
{
    char code;
    while (1)
    {
        printf("Enter operation code: ");
        scanf(" %c", &code);
        while (getchar() != '\n')
        {
            ;
        }

        switch (code)
        {
        case 'i':
            insert();
            break;
        case 's':
            search();
            break;
        case 'u':
            update();
            break;
        case 'p':
            print();
            break;
        case 'r':
            update_price();
            break;
        case 'q':
            return 0;
        default:
            printf("Wrong operation code.\n");
            break;
        }
        printf("\n");
    }

    return 0;
}

int find_part(int num)
{
    for (int i = 0; i < num_parts; ++i)
    {
        if (num == inventory[i].number)
        {
            return i;
        }
    }
    return -1;
}

void insert(void)
{
    int part_num;
    if (num_parts == MAX_LEN)
    {
        printf("Database is full; can't add more parts.\n");
        return;
    }

    printf("Enter part number: ");
    scanf(" %d", &part_num);
    if (find_part(part_num) != -1)
    {
        printf("Part already exists.\n");
        return;
    }
    inventory[num_parts].number = part_num;
    printf("Enter part name: ");
    read_line(inventory[num_parts].name, NAME_LEN);
    printf("Enter quantity on hand: ");
    scanf(" %d", &inventory[num_parts].on_hand);
    printf("Enter price: ");
    scanf(" %d", &inventory[num_parts].price);

    num_parts++;
}

void search(void)
{
    int input, idx;
    printf("Enter part number: ");
    scanf(" %d", &input);

    if ((idx = find_part(input)) == -1)
    {
        printf("Part not found.\n");
        return;
    }

    printf("Part name: %s\n", inventory[idx].name);
    printf("Quantity on hand: %d\n", inventory[idx].on_hand);
    printf("Price: %d\n", inventory[idx].price);
}

void update(void)
{
    int input, idx, change;
    printf("Enter part number: ");
    scanf(" %d", &input);

    if ((idx = find_part(input)) == -1)
    {
        printf("Part not found.\n");
        return;
    }

    printf("Enter change in quantity on hand: ");
    scanf(" %d", &change);
    inventory[idx].on_hand += change;
}

void update_price(void)
{
    int input, idx, new_price;
    printf("Enter part number: ");
    scanf(" %d", &input);

    if ((idx = find_part(input)) == -1)
    {
        printf("Part not found.\n");
        return;
    }

    printf("Enter new price of part: ");
    scanf(" %d", &new_price);
    inventory[idx].price = new_price;
}

void print(void)
{
    qsort(inventory, sizeof(inventory) / sizeof(inventory[0]), sizeof(inventory[0]), compare);
    printf("%15s%15s%20s%15s\n", "Part Number", "Part Name", "Quantiy on hand", "Price");
    for (int i = 0; i < num_parts; ++i)
    {
        printf("%7d       %-25s%11d%11d\n", inventory[i].number, inventory[i].name, inventory[i].on_hand, inventory[i].price);
    }
}

int compare(const void *a, const void *b)
{
    Part *p1 = (Part *)a;
    Part *p2 = (Part *)b;

    if (p1->number < p2->number)
    {
        return -1;
    }
    else if (p1->number > p2->number)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}