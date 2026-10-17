#include <stddef.h>
#include <errno.h>
#include "calculator.h"

int calculator_add(int a, int b, int *result)
{
        if (result == NULL) {
                return -EINVAL;
        }
        *result = a + b;

        return 0;
}

int calculator_sub(int a, int b, int *result)
{
        if (result == NULL) {
                return -EINVAL;
        }
        *result = a - b;

        return 0;
}

int calculator_mul(int a, int b, int *result)
{
        if (result == NULL) {
                return -EINVAL;
        }
        *result = a * b;

        return 0;
}

int calculator_div(int a, int b, int *result)
{
        if (result == NULL || b == 0) {
                return -EINVAL;
        }
        *result = a / b;

        return 0;
}
