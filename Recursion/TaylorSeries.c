#include <stdio.h>
#include <stdlib.h>

// Using Recursion - O(n^2)
double e_1(int x, int n)
{
    static double p = 1, f = 1;
    double result;
    if (n == 0)
        return 1;
    else
    {
        result = e_1(x, n - 1);
        p = p * x;
        f = f * n;
        return result + (p / f);
    }
}

// Using Loop - O(n)
double e_2(int x, int n)
{
    double res = 1, num = 1, denom = 1;
    for (int i = 1; i <= n; i++)
    {
        num *= x;
        denom *= i;
        res += (num / denom);
    }
    return res;
}

// Using Horner's Rule with Recursion - O(n)
double e_3(int x, int n)
{
    static double s = 1;
    if (n == 0)
        return s;
    s = 1 + x * s / n;
    return e_3(x, n - 1);
}

// Using Horner's Rule with Loop
double e_4(int x, int n)
{
    double s = 1;
    for (; n >= 1; n--)
        s = 1 + x * s / n;
    return s;
}

int main()
{
    printf("e(3, 3) = %.2f\n", e_1(4, 3));
    printf("e(3, 3) = %.2f\n", e_2(4, 3));
    printf("e(3, 3) = %.2f\n", e_3(4, 3));
    printf("e(3, 3) = %.2f\n", e_4(4, 3));
    return 0;
}