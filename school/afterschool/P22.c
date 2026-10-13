#include <stdio.h>

const int primes[] = {
    2,   3,   5,   7,   11,  13,  17,  19,  23,  29,
    31,  37,  41,  43,  47,  53,  59,  61,  67,  71,
    73,  79,  83,  89,  97,  101, 103, 107, 109, 113,
    127, 131, 137, 139, 149, 151, 157, 163, 167, 173,
    179, 181, 191, 193, 197, 199
};

int main() {
    int a;
    scanf("%d", &a);
    const int *p = primes;
    while (a > 1) {
        if (a % *p != 0) {
            p++;
            continue;
        }
        printf("%d ", *p);
        a /= *p;
    }
    return 0;
}