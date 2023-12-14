#include "main.h"

/**
* add - adds two integers
* @a: first integer
* @b: second integer
*
* Return: the sum of a and b
*/
int add(int a, int b)
{
    return (a + b);
}

/**
* subtract - subtracts two integers
* @a: first integer
* @b: second integer
*
* Return: the result of subtracting b from a
*/
int subtract(int a, int b)
{
    return (a - b);
}

/**
* multiply - multiplies two integers
* @a: first integer
* @b: second integer
*
* Return: the product of a and b
*/
int multiply(int a, int b)
{
    return (a * b);
}

/**
 * divide - divides two integers
* @a: first integer (dividend)
* @b: second integer (divisor)
*
* Return: the result of dividing a by b
*/
int divide(int a, int b)
{
    if (b != 0)
        return (a / b);
    else
        return (0); 
}
