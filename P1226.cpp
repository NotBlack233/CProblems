#include <bits/stdc++.h>
#include <cstdint>
using namespace std;

uint64_t _pow(uint64_t a, uint64_t b, uint64_t p) {
    uint64_t ans = 1;
    while (b) {
        if (b & 1) {
            ans = (ans * a) % p;
        }
        a = (a * a) % p;
        b >>= 1;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    uint64_t a, b, p;
    scanf("%lld%lld%lld", &a, &b, &p);
    printf("%lld^%lld mod %lld=%lld\n", a, b, p, _pow(a, b, p));
    return 0;
}