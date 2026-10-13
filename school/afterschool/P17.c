#include <stdio.h>
#include <string.h>

int main() {
    char s[1010], sub[1010];
    fgets(s, 1000, stdin);
    fgets(sub, 1000, stdin);
    int s_len = strlen(s) - 1, sub_len = strlen(sub) - 1;
    for (int i = 0; i < s_len; i++) {
        if (i + sub_len - 1 < s_len && strncmp(s + i, sub, sub_len) == 0) {
            i += sub_len - 1;
        } else {
            putchar(s[i]);
        }
    }
    return 0;
}
