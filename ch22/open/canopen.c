#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: canopen filename");
        exit(EXIT_FAILURE);
    }

    FILE *fp;
    if ((fp = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stdout, "%s can't be opened.\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    fprintf(stdout, "%s can be opened.", argv[1]);
    fclose(fp);

    return 0;
}