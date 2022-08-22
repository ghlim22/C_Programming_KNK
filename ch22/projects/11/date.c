#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN (10)

int main(void)
{
    const char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    char user_input[MAX_LEN + 1];
    int month, day, year;

    printf("Enter the date(m-d-y or m/d/y):");
    scanf("%s", user_input);

    int n = sscanf(user_input, "%d%*[-/]%d%*[-/]%d", &month, &day, &year);
    if (n != 3)
    {
        fprintf(stderr, "error: wrong input form.\n");
        return 1;
    }

    printf("%s %d, %d\n", months[month - 1], day, year);

    return 0;
}