#include <stdbool.h>
#include <stdio.h>

bool is_prime[110];
int primes[110], nr_primes = 0;

void Eratosthenes(int n) {
    for (int i = 2; i <= n; ++i)
        is_prime[i] = true;
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            primes[nr_primes++] = i;
            if ((long long)i * i > n)
                continue;
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    Eratosthenes(n);
    for (int i = 0; i < nr_primes; i++) {
        printf("%d ", primes[i]);
    }
    return 0;
}
