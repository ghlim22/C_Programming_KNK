#include <stdio.h>

struct s
{
    char a;
    int b[2];
    float c;
} st;

int main(void)
{
    printf("size of struct s: %lu\n", sizeof(struct s));
    printf("offset of a: %lu\n", __offsetof(struct s, a));
    printf("offset of b: %lu\n", __offsetof(struct s, b));
    printf("offset of c: %lu\n", __offsetof(struct s, c));

    return 0;
}