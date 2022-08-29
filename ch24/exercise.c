#include <stdio.h>
#include <math.h>
#include <errno.h>
#include <stdlib.h>

#define TRY_MATH_FCN(fcn, x) (try_math_fcn((fcn), x, "Error in call of " #fcn))

double try_math_fcn(double (*fcn)(double), double arg, const char *err_msg);

int main(void)
{
    double res = try_math_fcn(sqrt, 100.0, "error in sqrt\n");
    printf("%.2lf\n", res);

    return 0;
}

double try_math_fcn(double (*fcn)(double), double arg, const char *err_msg)
{
    errno = 0;
    double val = (*fcn)(arg);

    if (errno != 0)
    {
        perror(err_msg);
        exit(EXIT_FAILURE);
    }

    return val;
}