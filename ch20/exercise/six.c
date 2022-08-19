#include <stdio.h>
#include <math.h>

typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned int DWORD;

union
{
    struct
    {
        WORD ax, bx, cx, dx;
    } word;
    struct
    {
        BYTE al, ah, bl, bh, cl, ch, dl, dh;
    } byte;
} regs;



struct floating_point
{
    unsigned int fraction : 23;
    unsigned int exponent : 8;
    unsigned int sign : 1;
};

union fp_float
{
    float f;
    struct floating_point fp;
};

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
    return i << n | i >> (sizeof(int) * 8 - n);
}

unsigned int rotate_right(unsigned int i, int n)
{
    return i >> n | i << (sizeof(int) * 8 - n);
}

int count_ones(unsigned char ch)
{
    return ch >> 1 & 1;
}

unsigned int reverse_bits(unsigned int n)
{
    unsigned int val = 0;
    for (int i = 0; i < 32; ++i)
    {
        unsigned int tmp = 1 && n >> (32 - i);
        val |= tmp << i;
    }
    return val;
}

unsigned short create_short(unsigned char high_byte, unsigned char low_byte)
{
    unsigned short high = (unsigned short)high_byte;
    unsigned short low = (unsigned short)low_byte;
    return high_byte << 8 | low;
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
    printf("rotate left: %x\n", rotate_left(x, n));
    printf("rotate right: %x\n", rotate_right(x, n));

    union fp_float fpf;
    fpf.fp.sign = 1;
    fpf.fp.exponent = 128;
    fpf.fp.fraction = 0;

    printf("%.2f\n", fpf.f);

    return 0;
}