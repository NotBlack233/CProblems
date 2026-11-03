#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char a_buf[300], b_buf[300];
int na, nb, nc;

typedef struct {
    char d[406];
    short len;
} BigInt;

void rev(char *s, int n) {
    for (int i = 0; i < n >> 1; i++) {
        char t = s[i];
        s[i] = s[n - 1 - i];
        s[n - 1 - i] = t;
    }
}

void to_digit(char *s, int n, BigInt *bigint) {
    bigint->len = n;
    for (int i = 0; i < n; i++) {
        bigint->d[i] = s[i] - '0';
    }
}

BigInt *new_bigint() {
    BigInt *a = malloc(sizeof(BigInt));
    memset(a, 0, sizeof(BigInt));
    return a;
}

void add(const BigInt *a, const BigInt *b, BigInt *c) {
    char cout = 0;
    int len = a->len > b->len ? a->len : b->len;
    for (int i = 0; i < len; i++) {
        char res = a->d[i] + b->d[i] + cout;
        c->d[i] = res % 10;
        cout = res / 10;
    }
    c->d[len] = cout;
    c->len = len + !!cout;
}

void mul(const BigInt *a, const BigInt *b, BigInt *c) {
    memset(c, 0, sizeof(BigInt));
    for (int i = 0; i < b->len; i++) {
        char cout = 0;
        BigInt *t = new_bigint();
        for (int j = 0; j < a->len; j++) {
            char res = a->d[j] * b->d[i] + cout;
            t->d[j + i] = res % 10;
            cout = res / 10;
        }
        t->d[a->len + i] = cout;
        t->len = a->len + i + !!cout;
        BigInt *c_orig = malloc(sizeof(BigInt));
        memcpy(c_orig, c, sizeof(BigInt));
        add(c_orig, t, c);
        free(t);
        free(c_orig);
    }
    while (c->len > 1 && c->d[c->len - 1] == 0) {
        --c->len;
    }
}

int main() {
    fgets(a_buf, 300, stdin);
    fgets(b_buf, 300, stdin);
    a_buf[strcspn(a_buf, "\r\n")] = '\0';
    b_buf[strcspn(b_buf, "\r\n")] = '\0';
    na = strlen(a_buf);
    nb = strlen(b_buf);

    rev(a_buf, na);
    rev(b_buf, nb);

    BigInt *a = new_bigint(), *b = new_bigint(), *c = new_bigint();
    to_digit(a_buf, na, a);
    to_digit(b_buf, nb, b);

    mul(a, b, c);
    for (int i = c->len - 1; i >= 0; i--) {
        printf("%d", c->d[i]);
    }
    putchar('\n');
    free(a);
    free(b);
    free(c);
    return 0;
}