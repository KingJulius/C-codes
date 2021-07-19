#include <stdio.h>
#include <stdlib.h>

// Using Loop - O(n)
int fib_1(int n)
{
    int t0 = 0, t1 = 1, curr;
    if (n <= 1)
        return n;
    for (int i = 2; i <= n; i++)
    {
        curr = t0 + t1;
        t0 = t1;
        t1 = curr;
    }
    return curr;
}

// Using Recursion - O(2^n)
int fib_2(int n)
{
    if (n <= 1)
        return n;
    return fib_2(n - 1) + fib_2(n - 2);
}

// Using Recursion with Memoization - O(n)
int fib_3(int n)
{
    // Dynamic Size Allocation and Initialization of the Array
    int *arr = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        arr[i] = -1;

    if (n <= 1)
    {
        arr[n] = n;
        return n;
    }
    else
    {
        if (arr[n - 1] == -1)
            arr[n - 1] = fib_3(n - 1);
        if (arr[n - 2] == -1)
            arr[n - 2] = fib_3(n - 2);

        arr[n] = arr[n - 1] + arr[n - 2];
        return arr[n - 1] + arr[n - 2];
    }
}

int main()
{
    for (int i = 0; i <= 10; i++)
        printf("%d ", fib_1(i));

    printf("\n");
    for (int i = 0; i <= 10; i++)
        printf("%d ", fib_2(i));

    printf("\n");
    for (int i = 0; i <= 10; i++)
        printf("%d ", fib_3(i));

    return 0;
}