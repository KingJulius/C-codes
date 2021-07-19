#include <stdio.h>
#include <stdlib.h>

// Using Recursion with Pascal's Triangle
int C(int n, int r)
{
    if (r == 0 || r == n)
        return 1;
    return C(n - 1, r - 1) + C(n - 1, r);
}

int main()
{
    printf("%d", C(4, 2));
    return 0;
}