#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "readline.h"

#define NAME_LEN (25)

typedef struct _part
{
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
    int price;
    struct _part *next;
} Part;

Part *find_part(int num);
void insert(void);
void search(void);
void update(void);
void print(void);
void update_price(void);

Part *inventory = NULL; // points to the first part.
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

Part *find_part(int num)
{
    Part *p;

    for (p = inventory; p != NULL && num > p->number; p = p->next)
        ;

    if (p != NULL && p->number == num)
    {
        return p;
    }

    return NULL;
}

void insert(void)
{
    int part_num;
    Part *new_node, *cur, *prev;

    new_node = (Part *)malloc(sizeof(Part));
    if (new_node == NULL)
    {
        printf("Database is full; can't add more parts.\n");
        return;
    }

    printf("Enter part number: ");
    scanf(" %d", &new_node->number);

    for (prev = NULL, cur = inventory; cur != NULL && new_node->number > cur->number; prev = cur, cur = cur->next)
    {
        ;
    }

    if (cur != NULL && cur->number == new_node->number)
    {
        printf("Part already exists.\n");
        free(new_node);
        return;
    }

    printf("Enter part name: ");
    read_line(new_node->name, NAME_LEN);
    printf("Enter quantity on hand: ");
    scanf(" %d", &new_node->on_hand);
    printf("Enter price: ");
    scanf(" %d", &new_node->price);

    new_node->next = cur;
    if (prev == NULL)
    {
        inventory = new_node;
    }
    else
    {
        prev->next = new_node;
    }
}

void search(void)
{
    int input;
    Part *p;
    printf("Enter part number: ");
    scanf(" %d", &input);

    if ((p = find_part(input)) != NULL)
    {
        printf("Part name: %s\n", p->name);
        printf("Quantity on hand: %d\n", p->on_hand);
        printf("Price: %d\n", p->price);
    }
    else
    {
        printf("Part not found.\n");
    }
}

void update(void)
{
    int input, idx, change;
    Part *p;
    printf("Enter part number: ");
    scanf(" %d", &input);

    if ((p = find_part(input)) != NULL)
    {
        printf("Enter change in quantity on hand: ");
        scanf(" %d", &change);
        p->on_hand += change;
    }
    else
    {
        printf("Part not found.\n");
    }
}

void update_price(void)
{
    int input, new_price;
    Part *p;
    printf("Enter part number: ");
    scanf(" %d", &input);

    if ((p = find_part(input)) != NULL)
    {
        printf("Enter new price: ");
        scanf(" %d", &p->price);
    }
    else
    {
        printf("Part not found.\n");
    }
}

void print(void)
{

    Part *p;
    printf("%15s%15s%20s%15s\n", "Part Number", "Part Name", "Quantiy on hand", "Price");
    for (p = inventory; p != NULL; p = p->next)
    {
        printf("%7d       %-25s%11d%11d\n", p->number, p->name, p->on_hand, p->price);
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

int compare_desc(const void *a, const void *b)
{
    Part *p1 = (Part *)a;
    Part *p2 = (Part *)b;

    if (p1->number < p2->number)
    {
        return 1;
    }
    else if (p1->number > p2->number)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}
