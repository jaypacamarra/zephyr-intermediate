#include <zephyr/ztest.h>
#include "calculator.h"

ZTEST_SUITE(calculator_add, NULL, NULL, NULL, NULL, NULL);

ZTEST(calculator_add, test_positive_numbers)
{
        int result;

        zassert_ok(calculator_add(2, 3, &result), "Addition failed");
        zassert_equal(result, 5, "2 + 3 did not equal 5");
}
