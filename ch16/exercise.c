#include <stdbool.h>
#include <math.h>

typedef struct complex
{
    double real;
    double imaginary;
} Complex;

typedef struct date
{
    int month;
    int day;
    int year;
} Date;

typedef struct time
{
    int hour;
    int min;
    int sec;
} Time;

typedef struct
{
    int numerator;
    int denominator;
} Fraction;

typedef struct color
{
    int red;
    int green;
    int blue;
} Color;

typedef struct
{
    int x;
    int y;
} Pointer;

typedef struct
{
    Pointer upper_left;
    Pointer lower_right;
} Rectangle;

int get_area(const Rectangle *rect)
{
    return (rect->upper_left.y - rect->lower_right.y) * (rect->lower_right.x - rect->upper_left.x);
}

Pointer get_center(const Rectangle *rect)
{
    Pointer p = {(rect->lower_right.x + rect->upper_left.x) / 2, (rect->lower_right.y + rect->upper_left.y) / 2};
    return p;
}

typedef struct shape
{
    enum
    {
        RECTANGLE,
        CIRCLE
    } shape_kind;

    Pointer center;

    union
    {
        struct
        {
            double height;
            double width;
        } rectangle;

        struct
        {
            double radius;
        } circle;
    } u;
} Shape;

double compute_area(const Shape *s)
{
    switch (s->shape_kind)
    {
    case RECTANGLE:
        return s->u.rectangle.height * s->u.rectangle.width;
    case CIRCLE:
        return s->u.circle.radius * s->u.circle.radius * 3.14;
    default:
        return -1.0;
    }
}

void move_unit(Shape *s, int x, int y)
{
    s->center.x += x;
    s->center.y += y;
}

void scale(Shape *s, double c)
{
    switch (s->shape_kind)
    {
    case RECTANGLE:
        s->u.rectangle.height *= c;
        s->u.rectangle.width *= c;
        break;
    case CIRCLE:
        s->u.circle.radius *= sqrt(c);
        break;
    default:
        break;
    }
}

void move_rect(Rectangle *rect, int x, int y)
{
    rect->upper_left.x += x;
    rect->lower_right.x += x;
    rect->upper_left.y += y;
    rect->lower_right.y += y;
}

bool within(const Rectangle *rect, const Pointer *p)
{
    if (rect->upper_left.x < p->x && p->x < rect->lower_right.x)
    {
        if (rect->lower_right.y < p->y && p->y < rect->upper_left.y)
        {
            return true;
        }
    }
    return false;
}

int get_gcd(int x, int y)
{
    if (x < y)
    {
        return get_gcd(y, x);
    }
    if (x % y == 0)
    {
        return y;
    }

    return get_gcd(y, x % y);
}

void get_low(Fraction *frac)
{
    int gcd = get_gcd(frac->denominator, frac->numerator);
    frac->denominator /= gcd;
    frac->numerator /= gcd;
}

Fraction add_frac(Fraction *f1, Fraction *f2)
{
    Fraction frac = {f1->numerator + f2->numerator, f1->denominator + f2->denominator};
    get_low(&frac);
    return frac;
}

Fraction subtract_frac(Fraction *f1, Fraction *f2)
{
    Fraction frac = {f1->numerator - f2->numerator, f1->denominator - f2->denominator};
    get_low(&frac);
    return frac;
}

Fraction multiply_frac(Fraction *f1, Fraction *f2)
{
    Fraction frac = {f1->numerator * f2->numerator, f1->denominator * f2->denominator};
    get_low(&frac);
    return frac;
}

Fraction divide_frac(Fraction *f1, Fraction *f2)
{
    Fraction frac = {f1->numerator / f2->numerator, f1->denominator / f2->denominator};
    get_low(&frac);
    return frac;
}

Time split_time(long total_sec)
{
    Time result;
    result.hour = total_sec / 3600;
    result.min = total_sec % 3600 / 60;
    result.sec = total_sec % 3600 % 60;

    return result;
}

int compare_dates(Date *d1, Date *d2)
{
    if (d1->year == d2->year)
    {
        if (d1->month == d2->month)
        {
            return d1->day - d2->day;
        }
        return d1->month - d2->month;
    }

    return d1->year - d2->year;
}

struct complex make_complex(double r, double i)
{
    struct complex temp = {r, i};
    return temp;
}

Complex add_complex(Complex x, Complex y)
{
    Complex temp = {x.real + y.real, x.imaginary + y.imaginary};
    return temp;
}

Color make_color(int red, int green, int blue)
{
    if (red < 0)
    {
        red = 0;
    }
    if (green < 0)
    {
        green = 0;
    }
    if (blue < 0)
    {
        blue = 0;
    }

    if (red > 255)
    {
        red = 255;
    }
    if (green > 255)
    {
        green = 255;
    }
    if (blue > 255)
    {
        blue = 255;
    }

    Color r = {red, green, blue};
    return r;
}

int get_red(Color *c)
{
    return c->red;
}

bool equal_color(Color *c1, Color *c2){
    return c1->red == c2->red && c1->blue == c2->blue && c1->green && c2->green}

Color brighter(Color *c)
{
    int color[3] = {c->red, c->green, c->blue};

    if (color[0] == 0 && color[1] == 0 && color[2] == 0)
    {
        Color r = {3, 3, 3};
        return r;
    }

    for (int i = 0; i < 3; ++i)
    {
        if (color[i] < 3)
        {
            color[i] = 3;
        }
        color[i] /= 0.7;
        if (color[i] > 255)
        {
            color[i] = 255;
        }
    }

    Color r = {color[0], color[1], color[2]};
    return r;
}

int main(void)
{
    struct complex c1, c2, c3;
    const Color MAGENTA = {.red = 255, .blue = 255};

    typedef enum seven_days
    {
        SUN,
        MON,
        TUE,
        WED,
        THU,
        FRI,
        SAT
    } Days;

    /*
    enum piece
    {
        EMPTY,
        PAWN,
        KNIGHT,
        BISHOP,
        ROOK,
        QUEEN,
        KING
    };
    */

    enum color
    {
        BLACK,
        WHITE
    };

    typedef struct
    {
        enum piece p;
        enum color c;
    } Square;

    Square board[8][8] = { {{ROOK, BLACK}};

    struct pinball_machine
    {
        char name[41];
        int year;
        enum
        {
            EM,
            SS
        } type;
        int players;
    };

    int x = 0;
    int y = 0;

    typedef enum
    {
        NORTH,
        SOUTH,
        EAST,
        WEST
    } Direction;
    Direction d = NORTH;
    switch (d)
    {
    case NORTH:
        y++;
        break;
    case SOUTH:
        y--;
        break;
    case EAST:
        x++;
        break;
    case WEST:
        x--;
        break;
    default:
        break;
    }

    enum chess_pieces
    {
        KING,
        QUEEN,
        ROOK,
        BISHOP,
        KNIGHT,
        PAWN
    };

    int board[6] = {[KING] = 200, [QUEEN] = 9, [ROOK] = 5, [BISHOP] = 3, [KNIGHT] = 3, [PAWN] = 1};
}