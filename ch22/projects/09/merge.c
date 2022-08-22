#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define NAME_LEN (20)
#define MAX_PARTS (100)

typedef struct
{
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
} Part;

int restore_data(FILE *stream, Part inventory[]);
int find_part(int num, Part inventory[], int num_parts);
int compare_part(const void *a, const void *b);
int save_data(FILE *fp, Part inventory[], int part_num);

bool vis[MAX_PARTS]; // indicate inventory2's elements has been visited.
Part new_inventory[MAX_PARTS];
int new_inventory_num = 0;

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        //
    }

    FILE *input1 = fopen(argv[1], "rb");
    if (input1 == NULL)
    {
        //
    }

    FILE *input2 = fopen(argv[2], "rb");
    if (input2 == NULL)
    {
        //
    }

    FILE *output = fopen(argv[3], "wb");
    if (output == NULL)
    {
        //
    }
    int s1;
    int s2;

    do
    {
        Part part1, part2;
        s1 = fread(&part1, sizeof(Part), 1, input1);
        s2 = fread(&part2, sizeof(Part), 1, input2);

        if (s1)
        {
            if (insert_part(&s1) != 0)
            {
                // error
            }
        }
        if (s2)
        {
            if (insert_part(&s2) != 0)
            {
                // error
            }
        }

    } while (s1 + s2 > 0);

    fclose(input1);
    fclose(input2);
    fclose(output);

    return 0;
}

int find_part(int num, Part inventory[], int num_parts)
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

int insert_part(Part *new)
{
    int i;
    if (new_inventory_num == MAX_PARTS)
    {
        return -1;
    }

    if ((i = find_part(new->number, new_inventory, new_inventory_num)) >= 0)
    {
        if (!strcmp(new->name, new_inventory[i].name))
        {
            return -2;
        }
        new_inventory[i].number += new->on_hand;
        return 0;
    }

    for (i = 0; i < new_inventory_num; ++i)
    {
        if (new->number < new_inventory[i].number)
        {
            break;
        }
    }

    for (int j = new_inventory_num; j > i; --j)
    {
        new_inventory[j] = new_inventory[j - 1];
    }

    new_inventory[i] = *new;

    new_inventory_num++;

    return 0;
}

int restore_data(FILE *stream, Part inventory[])
{
    int num_parts;
    // 원소 하나씩 읽어야 제대로 저장된다.
    for (num_parts = 0; fread(&inventory[num_parts], sizeof(Part), 1, stream); ++num_parts)
    {
        ;
    }

    if (num_parts == 0)
    {
        printf("failed to read inventory data.");
    }

    if (feof(stream) || ferror(stream))
    {
        return 0;
    }

    fclose(stream);

    return num_parts;
}

int compare_part(const void *a, const void *b)
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

int save_data(FILE *fp, Part inventory[], int part_num)
{
    qsort(inventory, part_num, sizeof(inventory[0]), compare_part);
    int n = fwrite(inventory, sizeof(Part), part_num, fp);

    if (n != part_num)
    {
        printf("%d", n);
        // failed to write inventory data.
        // return 0;
    }
    fclose(fp);
    return 1;
}