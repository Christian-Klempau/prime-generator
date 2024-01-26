#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h> // current time for random seed
#include <stdio.h>

#include "primality.h"
#include "mathfuncs.h"

bool is_prime(long long n, int k)
{

    if (n <= 1)
        return false;
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;

    int neg_count = 0;

    for (int i = 1; i <= k; i++)
    {
        long long a = (rand() + 2) % n;

        if (gcd(a, n) > 1)
            return false;

        int b = exp_mod(a, (n - 1) / 2, n); // floor division
        if (b == n - 1)
            neg_count++;
        else if (b != 1)
            return false;
    }

    if (is_exponent(n))
        return false;
    else if (neg_count > 0)
        return true;

    return false;
};

int find_prime(int a, int b, int k)
{
    assert(b > a);

    srand(time(0)); // current time as seed for random generator
    // RAND_MAX =
    int p = rand() % b;

    while (!is_prime(p, k))
        p = rand() % b;

    return p;
}