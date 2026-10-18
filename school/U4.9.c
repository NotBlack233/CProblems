#include <stdio.h>
#include <string.h>

int main() {
    char buf[10];
    scanf("%s", buf);
    int len = strlen(buf);
    printf("%d\n", len);
    for (int i = 0; i < len; i++) {
        printf("%c ", buf[i]);
    }
    putchar('\n');
    for (int i = len - 1; i >= 0; i--) {
        printf("%c ", buf[i]);
    }
    return 0;
}