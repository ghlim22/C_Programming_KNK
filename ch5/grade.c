#include <stdio.h>

int main(void)
{
    int numerical_grade;
    char letter_grade;

    printf("Enter numerical grade: ");
    scanf("%d", &numerical_grade);

    if (numerical_grade < 0 || numerical_grade > 100)
    {
        printf("Invalide grade.\n");

        return 1;
    }

    switch (numerical_grade / 10)
    {
    case 10:
    case 9:
        letter_grade = 'A';
        break;
    case 8:
        letter_grade = 'B';
        break;
    case 7:
        letter_grade = 'C';
        break;
    case 6:
        letter_grade = 'D';
        break;
    default:
        letter_grade = 'F';
        break;
    }

    printf("Letter grade: %c\n", letter_grade);

    return 0;
}