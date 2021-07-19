#include <stdio.h>
#include <stdlib.h>

int factorial_recursion(int n)
{
    if (n == 0)
        return 1;
    else
    {
        return factorial_recursion(n - 1) * n;
    }
}

int factiorial_loop(int n)
{
    int sum = 1;
    for (int i = n; i > 1; i--)
        sum *= i;
    return sum;
}

int main()
{
    printf("%d\n", factorial_recursion(6));
}