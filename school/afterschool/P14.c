#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main() {
    char buf[110];
    scanf("%s", buf);
    int exp = -1, len = strlen(buf);
    if (strcmp("0.0", buf) == 0) {
        printf("0e0\n");
        return 0;
    }
    bool neg = buf[0] == '0' && buf[1] == '.';
    if (neg) {
        int i;
        for (i = 2; buf[i] == '0' && i < len; i++) {
            exp--;
        }
        putchar(buf[i]);
        bool first = true;
        for (i++; i < len; i++) {
            if (first) {
                first = false;
                putchar('.');
            }
            putchar(buf[i]);
        }
        printf("e%d\n", exp);

    } else {
        for (int i = 0; buf[i] != '.' && i < len; i++) {
            exp++;
        }
        putchar(buf[0]);
        bool first = true;
        for (int i = 1; i < len; i++) {
            if (buf[i] == '.') continue;
            if (first) {
                first = false;
                putchar('.');
            }
            putchar(buf[i]);
        }
        printf("e%d\n", exp);
    }
    return 0;
}
