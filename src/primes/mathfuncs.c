#include <stdbool.h>

#include "mathfuncs.h"

long long exp_mod(long long a, long long b, long long n)
{
    long long result = 1;
    a = a % n;

    if (a == 0)
        return 0;

    while (b > 0)
    {
        if (b & 1)
            // if b is odd, multiply x with result
            result = (result * a) % n;

        b = b >> 1; // b = b // 2
        a = (a * a) % n;
    }

    return result;
};

long long gcd(long long a, long long b)
{
    while (b != 0)
    {
        long long temp = b;
        b = a % b;
        a = temp;
    }

    return a;
};

long long extended_euclides(long long a, long long b)
{
    long long r_0 = a;
    long long s_0 = 1;
    long long t_0 = 0;

    long long r_1 = b;
    long long s_1 = 0;
    long long t_1 = 1;

    long long r_2, s_2, t_2;

    while (r_1 > 0)
    {
        r_2 = r_0 % r_1;
        s_2 = s_0 - ((r_0 / r_1) * s_1);
        t_2 = t_0 - ((r_0 / r_1) * t_1);

        r_0 = r_1;
        s_0 = s_1;
        t_0 = t_1;

        r_1 = r_2;
        s_1 = s_2;
        t_1 = t_2;
    }

    return s_0;
};

long long modular_inverse(long long a, long long n)
{
    long long s = extended_euclides(a, n);
    return s % n;
};

bool is_exponent(long long n)
{
    if (n <= 3)
        return false;

    long long k = 2;
    long long limit = 4;

    while (limit <= n)
    {
        if (has_natural_root(n, k))
            return true;

        k++;
        limit = 2 * k;
    };

    return false;
};

bool has_natural_root(long long n, long long k)
{
    return false;
}

bool has_natural_root_in_interval(long long n, long long k, long long i, long long j)
{
    return false;
}
