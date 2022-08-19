#include <stdio.h>
#include <math.h>

struct file_date
{
    unsigned int day : 5;
    unsigned int month : 4;
    unsigned int year : 7;
};

union int_date
{
    unsigned short i;
    struct file_date fd;
};

void print_date(unsigned short i)
{
    union int_date u;
    
    u.i = i;
    printf("%d/%d/%d\n", u.fd.month, u.fd.day, u.fd.year + 1980);
}

unsigned short swap_bytes(unsigned short i)
{
    return i << 8 | i >> 8;
}

unsigned int rotate_left(unsigned int i, int n)
{
    return i << n | i >> (32 - n);
}

int main(void)
{
    unsigned short i;
    printf("Enter a hexadecimal number (up to 4 digits): ");
    scanf("%hx", &i);
    printf("return value: %hx\n", swap_bytes(i));
    
    unsigned int x;
    int n;
    printf("Enter a hexadecimal number (up to 8 digits): ");
    scanf("%x", &x);
    printf("Enter n: ");
    scanf("%d", &n);
    printf("return value: %x\n", rotate_left(x, n));
    
    return 0;
}
