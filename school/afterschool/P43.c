#include <stdio.h>
#include <string.h>

int a[114];
int nr_a = 0;

int main() {
    char buf[110];
    fgets(buf, 100, stdin);
    char *left = NULL;
    for (char *p = buf; *p != '\0'; p++) {
        if (*p >= '0' && *p <= '9') {
            if (left == NULL) {
                left = p;
            }
        } else {
            if (left != NULL) {
                int res = 0, exp = 1;
                for (char *t = p - 1; t >= left; t--) {
                    res += (*t - '0') * exp;
                    exp *= 10;
                }
                a[nr_a++] = res;
            }
            left = NULL;
        }
    }
    printf("%d ", nr_a);
    for (int i = 0; i < nr_a; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}