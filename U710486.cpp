#include <cstdio>

int main() {
    int n;
    int a[20];
    int cnt = 0;
    scanf("%d", &n);

    if (n == 0) {
        putchar('0');
        return 0;
    }

    if (n == -2147483648) {
        // ???
        
    }

    while (n != 0) {
        int d = n % 10;
        a[cnt] = d;
        cnt++;
        n /= 10;
    }

    for (int i = cnt - 1; i >= 0; i--) {
        printf("%d ", a[i]);
    }
    return 0;
}
