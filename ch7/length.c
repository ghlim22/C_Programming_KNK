#include <stdio.h>

typedef int8_t Int8;
typedef int16_t Int16;
typedef int32_t Int32;

int main(void)
{
    int counter = 0;
    printf("Enter a message: ");

    while (getchar() != '\n')
    {
        counter++;
    }

    printf("Your message was %d character(s) long.", counter);

    unsigned long size = (unsigned long)sizeof(long);
    printf("%zu\n", size);

    return 0;
}

double compute_average_word_length(const char *sentence)
{
    int word_cnt = 0;
    int total_length = 0;
    
    while (*sentence != '\0')
    {
        if (*sentence == ' ')
        {
            word_cnt++;
        }
        else
        {
            total_length++;
        }
    }
    word_cnt++;
    
    return total_length / word_cnt;
}
