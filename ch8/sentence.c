#include <stdio.h>

int main(void)
{
    char input[64], last, temp;
    int count;
    printf("Enter a sentence: ");
    count = 0;
    while (1)
    {
        temp = getchar();
        if (temp == '.' || temp == '?' || temp == '!')
        {
            last = temp;
            input[count] = ' ';
            break;
        }

        input[count] = temp;
        ++count;
    }

    for (int i = count; i > 0;)
    {
        if (input[i] == ' ')
        {
            int j;
            for (j = i - 1; input[j] != ' '; --j)
            {
                if (j == 0)
                {
                    j = -1;
                    break;
                }
            }

            for (int k = j + 1; k < i; k++)
            {
                printf("%c", input[k]);
            }
            printf("%c", j == -1 ? last : ' ');
            i = j;
        }
    }
    printf("\n");

    return 0;
}