/*
 * Calculator Module - Public API
 *
 * Pure arithmetic operations with no Zephyr kernel dependencies.
 * This module compiles on any platform, including the minimal
 * unit_testing board.
 */

#ifndef CALCULATOR_H
#define CALCULATOR_H

/**
 * @brief Add two integers
 *
 * @param a First operand
 * @param b Second operand
 * @param result Pointer where result will be stored
 *
 * @return 0 on success, -EINVAL if result is NULL
 */
int calculator_add(int a, int b, int *result);

/**
 * @brief Subtract two integers
 *
 * @param a First operand
 * @param b Second operand
 * @param result Pointer where result will be stored
 *
 * @return 0 on success, -EINVAL if result is NULL
 */
int calculator_sub(int a, int b, int *result);

/**
 * @brief Multiply two integers
 *
 * @param a First operand
 * @param b Second operand
 * @param result Pointer where result will be stored
 *
 * @return 0 on success, -EINVAL if result is NULL
 */
int calculator_mul(int a, int b, int *result);

/**
 * @brief Divide two integers (integer truncation toward zero)
 *
 * @param a Dividend
 * @param b Divisor
 * @param result Pointer where result will be stored
 *
 * @return 0 on success, -EINVAL if result is NULL or b is 0
 */
int calculator_div(int a, int b, int *result);

#endif /* CALCULATOR_H */
