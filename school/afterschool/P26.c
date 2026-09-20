#include <stdio.h>
#include <stdbool.h>

bool primes_vis[10010];
int primes[10010] = {2};
int nr_primes = 1;

bool is_prime(int n) {
    if (n == 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void gen_prime() {
    for (int i = primes[nr_primes - 1] + 1;; i++) {
        if (is_prime(i)) {
            primes[nr_primes++] = i;
            return;
        }
    }
}

void factorize(int x) {
    int ipr = 0;
    while (x > 1) {
        if (x % primes[ipr] != 0) {
            if (ipr >= nr_primes - 1) {
                gen_prime();
            }
            ipr++;
        } else {
            primes_vis[ipr] = true;
            x /= primes[ipr];
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int t;
        scanf("%d", &t);
        factorize(t);
    }
    for (int i = 0; i < nr_primes; i++) {
        if (primes_vis[i]) {
            printf("%d ", primes[i]);
        }
    }
    return 0;
}