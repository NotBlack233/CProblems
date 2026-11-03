#include <iostream>

const int N = 1e4 + 10;
long long a[N];

int main() {
    int len;
    for (len = 0; len < N; len++) {
        long long t;
        scanf("%lld", &t);
        if (t == -1) break;
        a[len] = t;
    }
    long long maxx = -1;
    for (int i = 0; i < len; i++) {
        printf("%lld ", a[i]);
        maxx = a[i] > maxx ? a[i] : maxx;
    }
    printf("\n%lld\n", maxx);
    for (int i = 0; i < len; i++) {
        if (a[i] < maxx) {
            printf("%lld ", a[i]);
        }
    }
    return 0;
}
