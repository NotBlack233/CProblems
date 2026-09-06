#include <cstdint>
#include <cstdio>
#include <iostream>
using namespace std;
uint64_t fast_pow(uint64_t a, uint64_t b, uint64_t p) {
    uint64_t res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

int main() {
    int a, b, p;
    cin >> a >> b >> p;
    printf("%d^%d mod %d=%lld", a, b, p, fast_pow(a, b, p));
    return 0;
}