#include <stdio.h>
#include <string.h>

typedef struct {
    int letter, num, space, other;
} res;

res stat(char *s) {
    res r = {0, 0, 0, 0};
    char c;
    while ((c = *s++)) {
        if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z')) {
            r.letter++;
        } else if ('0' <= c && c <= '9') {
            r.num++;
        } else if (c == ' ') {
            r.space++;
        } else {
            r.other++;
        }
    }
    return r;
}

int main() {
    char buf[51];
    fgets(buf, 51, stdin);
    buf[strcspn(buf, "\r\n")] = 0;
    res r = stat(buf);
    printf("%d %d %d %d\n", r.letter, r.num, r.space, r.other);
    return 0;
}