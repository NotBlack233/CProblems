#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int fact[10010];
int nr_fact = 0;

int comp(const void *a, const void *b) {
    return *(int *)a > *(int *)b;
}

bool is_prime(int n) {
    if (n == 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (is_prime(i)) fact[nr_fact++] = i;
            if (is_prime(n / i)) fact[nr_fact++] = n / i;
        }
    }
    qsort(fact, nr_fact, sizeof(fact[0]), comp);
    for (int i = 0; i < nr_fact; i++) {
        printf("%d ", fact[i]);
    }
    if (nr_fact == 0) {
        puts("No Answer");
    }
    return 0;
}