#include <stdio.h>

int main(void)
{
    char ch, input[128];
    int n;

    printf("Enter message to be encrypted: ");
    for (int i = 0; i < 80; ++i)
    {
        input[i] = getchar();
        if (input[i] == '\n')
        {
            break;
        }
    }

    printf("Enter shift amount: ");
    scanf("%d", &n);

    printf("Encrypted message: ");
    for (int i = 0; i < 80; ++i)
    {
        if (input[i] >= 'A' && input[i] <= 'Z')
        {
            ch = input[i];
            input[i] = ((ch - 'A') + n) % 26 + 'A';
        }
        else if (input[i] >= 'a' && input[i] <= 'z')
        {
            ch = input[i];
            input[i] = ((ch - 'a') + n) % 26 + 'a';
        }
    }
    for (int i = 0; input[i] != '\n'; ++i)
    {
        printf("%c", input[i]);
    }
    printf("\n");

    return 0;
}