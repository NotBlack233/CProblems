#include <stdio.h>
#include <string.h>

int main() {
    freopen("text1.dat", "r", stdin);
    freopen("text2.dat", "w", stdout);

    char buf[100];
    while (fgets(buf, 100, stdin) != NULL) {
        int len = strlen(buf);
        if (len > 0 && buf[len - 1] == '\n') {
            len--;
        }
        for (int i = len - 1; i >= 0; i--) {
            putchar(buf[i]);
        }
        putchar('\n');
    }

    return 0;
}