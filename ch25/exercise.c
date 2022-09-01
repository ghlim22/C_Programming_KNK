#include <stdio.h>
#include <locale.h>
#include <wchar.h>
#include <stdlib.h>

int mbcheck(const char *s)
{
    int n;
    for (mblen(NULL, 0);; s += n)
    {
        if ((n = mblen(s, MB_CUR_MAX)) <= 0)
        {
            return n;
        }
    }
}

int main(void)
{
    // exercise 1
    char *my_locale = setlocale(LC_ALL, NULL);
    printf("%s\n", my_locale);

    // exercise 2
    printf("%d\n", mbcheck("\x05\x87\x80\x36\xed\xaa"));
    printf("%d\n", mbcheck("\x20\xe4\x50\x88\x3f"));
    printf("%d\n", mbcheck("\xde\xad\xbe\xef"));
    printf("%d\n", mbcheck("\x8a\x60\x92\x74\x41"));

    return 0;
}