#include <stdio.h>

int main(void)
{
    int n;
    float e, r;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter r: ");
    scanf("%f", &r);

    e = 1;
    for (int i = 0; i < n; ++i)
    {
        int term = 1;
        for (int j = 1; j <= i; ++j)
        {
            term *= (j + 1);
        }
        if (term >= r)
        {
            break;
        }
        e += 1.0f / term;
    }

    printf("%.5f\n", e);

    return 0;
}