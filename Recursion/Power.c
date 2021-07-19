#include <stdio.h>
#include <stdlib.h>

int power(int base, int exp)
{
    if (exp == 0)
        return 1;
    return power(base, exp - 1) * base;
}

int pow_updated(int base, int exp)
{
    if (exp == 0)
        return 1;
    else if (exp % 2 == 0)
        return pow_updated(base * base, exp / 2);
    return pow_updated(base * base, (exp - 1) / 2) * base;
}

int main()
{
    printf(" %d ", power(2, 4));
    printf(" %d ", pow_updated(2, 4));
    return 0;
}