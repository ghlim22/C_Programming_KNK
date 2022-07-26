#include <stdio.h>

#define NAME_LEN (20)

struct part
{
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
} part1 = {528, "Disk drive", 10}, part2 = {914, "Printer cable", 5};

struct person_name
{
    char first[21];
    char middle_initial;
    char last[21];
};

struct student
{
    struct person_name name;
    int id, age;
    char sex;
} student1, student2;

int main(void)
{
    printf("Part number: %d\n", part1.number);
    printf("Part name: %s\n", part1.name);
    printf("Quantity on hand: %d\n", part1.on_hand);
}
