#include <stdio.h>
void printocta(int num);
int main(void)
{
    int input;
    printf("Enter a number between 0 and 32767: ");
    scanf("%d", &input);
    printocta(input);
}

void printocta(int num)
{
    if (num == 0)
    {
        return;
    }

    printocta(num / 8);
    printf("%d", num % 8);
}