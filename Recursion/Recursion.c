#include <stdio.h>
#include <stdlib.h>

void tail_recursion(int n)
{
    if (n > 0)
    {
        printf("%d ", n);
        tail_recursion(n - 1);
    }
}

void head_recursion(int n)
{
    if (n > 0)
    {
        head_recursion(n - 1);
        printf("%d ", n);
    }
}

void tree_recursion(int n)
{
    if (n > 0)
    {
        printf("%d ", n);
        tree_recursion(n - 1);
        tree_recursion(n - 1);
    }
}

void funcB(int n);

void funcA(int n)
{
    if (n > 0)
    {
        printf("%d ", n);
        funcB(n - 1);
    }
}

void funcB(int n)
{
    if (n > 1)
    {
        printf("%d ", n);
        funcA(n / 2);
    }
}

int nested_func(int n)
{
    if (n > 100)
    {
        printf(" %d ", n);
        return n - 10;
    }
    else
    {
        printf(" %d ", n);
        return nested_func(nested_func(n + 11));
    }
}

int main()
{
    // printf("\n Tail Recursion:\n");
    // tail_recursion(3);
    // printf("\n Head Recursion:\n");
    // head_recursion(3);
    // printf("\n Tree Recursion:\n");
    // tree_recursion(3);
    // printf("\n Indirect Recursion:\n");
    // funcA(20);
    printf("\n Nested Recursion:\n");
    printf("\n\n%d", nested_func(95));
    return 0;
}