#include <stdio.h>
#include <string.h>

typedef enum {
    UPPER, LOWER, NUM, SPACE, OTHER
} Type;

int cnt[5];

Type categorize(char c) {
    if (c >= 'A' && c <= 'Z') return UPPER;
    if (c >= 'a' && c <= 'z') return LOWER;
    if (c >= '0' && c <= '9') return NUM;
    if (c == ' ') return SPACE;
    return OTHER;
}

int main() {
    char buf[100];
    int n;
    scanf("%d", &n);
    fgets(buf, 90, stdin);
    for (int i = 1; i <= n; i++) {
        fgets(buf, 90, stdin);
        int len = strlen(buf) - 1;
        for (int i = 0; i < len; i++) {
            cnt[categorize(buf[i])]++;
        }
    }
    for (int i = 0; i < 5; i++) {
        printf("%d ", cnt[i]);
    }
    return 0;
}