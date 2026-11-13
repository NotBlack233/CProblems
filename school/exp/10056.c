#include <stdio.h>
#include <string.h>

int digit(char hex) {
    if ('a' <= hex && hex <= 'f') return hex - 'a' + 10;
    if ('A' <= hex && hex <= 'F') return hex - 'A' + 10;
    return hex - '0';
}

char digitchar(int n) {
    if (10 <= n && n <= 15) return n - 10 + 'A';
    return n + '0';
}

int to_num(const char *n, int base) {
    int len = strlen(n);
    int p = 1;
    int res = 0;
    for (int i = len - 1; i >= 0; i--) {
        res += p * digit(n[i]);
        p *= base;
    }
    return res;
}

void to_nbase(char *dest, int n, int base) {
    int len = 0;
    if (n == 0) {
        dest[0] = '0';
        dest[1] = '\0';
        return;
    }
    while (n) {
        dest[len++] = digitchar(n % base);
        n /= base;
    }
    dest[len] = '\0';
    for (int i = 0; i * 2 < len - 1; i++) {
        char t = dest[i];
        dest[i] = dest[len - 1 - i];
        dest[len - 1 - i] = t;
    }
}

int main() {
    int a, b;
    char n[20];
    scanf("%d %s %d", &a, n, &b);
    int t = to_num(n, a);
    char nbase[20];
    to_nbase(nbase, t, b);
    puts(nbase);
    return 0;
}