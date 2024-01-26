#include <stdio.h>
#include "primality.h"

int main() {
    int integer = 10000000;
    int prime = find_prime(1, integer, 10);
    printf("%d\n", prime);
    // scanf("%d", &integer);
    // printf("%d\n", integer);
    return 0;
}