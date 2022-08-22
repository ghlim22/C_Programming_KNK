#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    int n, ch;
    char input_file_name[FILENAME_MAX];
    FILE *input_fp, *output_fp;

    printf("Enter name of file to be encrypted: ");
    scanf("%s", input_file_name);

    if ((input_fp = fopen(input_file_name, "r")) == NULL)
    {
        return 1;
    }

    strcat(input_file_name, ".enc");
    if ((output_fp = fopen(input_file_name, "w")) == NULL)
    {
        return 1;
    }

    printf("Enter shift amount: ");
    scanf("%d", &n);

    while (fscanf(input_fp, "%c", &ch) == 1)
    {
        if (ch == EOF)
        {
            break;
        }
        if (ch >= 'A' && ch <= 'Z')
        {
            ch = ((ch - 'A') + n) % 26 + 'A';
        }
        else if (ch >= 'a' && ch <= 'z')
        {
            ch = ((ch - 'a') + n) % 26 + 'a';
        }
        fprintf(output_fp, "%c", (char)ch);
    }

    return 0;
}
