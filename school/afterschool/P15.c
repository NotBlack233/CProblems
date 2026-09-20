#include <stdio.h>

int main() {
    char a[110];
    int len = 0;
    int exp;
    char t;
    while ((t = getchar()) != EOF) {
        if (t == '.') continue;
        if (t == 'e') {
            scanf("%d", &exp);
            break;
        }
        a[len++] = t;
    }
    if (exp < len - 1) {
        int i;
        for (i = 0; i <= exp; i++) {
            putchar(a[i]);
        }
        putchar('.');
        for (; i < len; i++) {
            putchar(a[i]);
        }
    } else {
        for (int i = 0; i <= exp; i++) {
            if (i < len) putchar(a[i]);
            else putchar('0');
        }
    }
    return 0;
}