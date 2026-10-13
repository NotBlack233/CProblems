#include <stdio.h>
#include <string.h>

int main() {
    char buf1[20], buf2[20];
    scanf("%s %s", buf1, buf2);
    int nr_buf1 = strlen(buf1), nr_buf2 = strlen(buf2);
    for (int i = 0; i < nr_buf1; i++) {
        buf1[i] -= '0';
    }
    for (int i = 0; i < nr_buf2; i++) {
        buf2[i] -= '0';
    }

    int n1 = 0, n2 = 0, exp = 1;
    for (int i = nr_buf1 - 1; i >= 0; i--) {
        n1 += buf1[i] * exp;
        exp *= 10;
    }

    exp = 1;
    for (int i = nr_buf2 - 1; i >= 0; i--) {
        n2 += buf2[i] * exp;
        exp *= 10;
    }

    int r1 = 0, r2 = 0;
    exp = 1;
    for (int i = 0; i < nr_buf1; i++) {
        r1 += buf1[i] * exp;
        exp *= 10;
    }

    exp = 1;
    for (int i = 0; i < nr_buf2; i++) {
        r2 += buf2[i] * exp;
        exp *= 10;
    }

    int prod = n1 * n2, prodr = r1 * r2;
    if (prod == prodr) {
        printf("%d*%d=%d*%d", n1, n2, r1, r2);
    } else {
        printf("%d*%d!=%d*%d", n1, n2, r1, r2);
    }
    return 0;
}