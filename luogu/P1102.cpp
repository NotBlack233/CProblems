#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <unordered_map>
using namespace std;

const int N = 2e5 + 10;
int a[N];
unordered_map<int, int> hsh;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    size_t n;
    int c;
    uint64_t ans = 0;
    scanf("%llu %d", &n, &c);
    c = abs(c);
    for (size_t i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        hsh[a[i]]++;
    }
    for (size_t i = 0; i < n; i++) {
        ans += hsh[c + a[i]];
    }
    printf("%llu\n", ans);
    return 0;
}