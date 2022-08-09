int *(*x[10])(void);
typedef int *Fcn(void);
typedef Fcn *Fcn_ptr;
typedef Fcn_ptr Fcn_ptr_array[10];
Fcn_ptr_array x0;

char (*a[10])(int);
typedef char Fcn1(int);
typedef Fcn1 *Fcn1_ptr;
typedef Fcn1_ptr Fcn1_ptr_array[10];
Fcn1_ptr_array x1;

int (*b(int))[5];
typedef int arr_t[5];
typedef arr_t fx_t(int);
fx_t *x;

float *(*c(void))(int);
typedef float *Fcn3(int);
typedef Fcn3 *Fcn3_t(void);
Fcn3_t x3;

void (*d(int, void (*e)(int)))(int);
typedef void Fcn4(int);
typedef void *Fcn4_param2(int);
typedef Fcn4 *Fcn4_inner(int, Fcn4_param2);
Fcn4_inner x4;

struct t
{
    int data;
};

struct n
{
    int data;
};

void insert(void);
void search(void);
void update(void);
void print(void);

int main(void)
{
    // 10
    char *(*p)(char *);

    void (*f2(struct t * param1, long n))(void);

    void (*a2[4])(void) = {insert, search, update, print};

    struct t (*b2[10])(int a, int b);

    // 11
    int *f(int);

    int (*g2(int))(int);

    int (*a3[10])(int);
}
