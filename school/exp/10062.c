#include <stdio.h>

int charcmp(char a, char b) {
    if ('a' <= a && a <= 'z') a -= 'a' - 'A';
    if ('a' <= b && b <= 'z') b -= 'a' - 'A';
    return a - b;
}

int strcasecmp(const char *a, const char *b) {
    while (*a && *b) {
        int res = charcmp(*a, *b);
        if (res) return res;
        a++;
        b++;
    }
    return charcmp(*a, *b);
}

char map_char(int x) {
    if (x == 0) return '=';
    if (x < 0) return '<';
    return '>';
}

int main() {
    char buf1[100], buf2[100];
    fgets(buf1, 90, stdin);
    fgets(buf2, 90, stdin);
    putchar(map_char(strcasecmp(buf1, buf2)));
    return 0;
}