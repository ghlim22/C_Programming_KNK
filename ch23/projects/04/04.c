#include <stdio.h>
#include <string.h>

#define MAX_SIZE (100)

int main(void)
{
    char str[MAX_SIZE + 1];
    char *arr[MAX_SIZE];
    char *p;
    int cnt = 0;
    printf("Enter a series of words: ");
    fgets(str, sizeof(str), stdin);
    str[strlen(str) - 1] = '\0';
    arr[cnt++] = strtok(str, " ");
    while ((p = strtok(NULL, " ")) != NULL)
    {
        arr[cnt++] = p;
    }
    for (int i = cnt - 1; i >= 0; --i)
    {
        printf("%s ", arr[i]);
    }

    return 0;
}