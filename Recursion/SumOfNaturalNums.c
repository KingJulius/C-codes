#include <stdio.h>
#include <stdlib.h>

int sumOfNaturalNums_recursive(int n)
{
    if (n == 0)
        return 0;

    return sumOfNaturalNums(n - 1) + n;
}

int sumOfNaturalNums_loop(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    return sum;
}

int sumOfNaturalNums(int n)
{
    return n * (n + 1) / 2;
}

int main()
{
    printf("%d\n", sumOfNaturalNums_recursive(5));
}