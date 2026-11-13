#include <stdio.h>
#include <string.h>

int b[26];

int main() {
    int n;
    scanf("%d", &n);
    char buf[1010];
    while (n--) {
        scanf("%s", buf);
        memset(b, 0, sizeof(b));
        for (int i = 0; buf[i]; i++) {
            b[buf[i] - 'a']++;
        }
        char mx_letter;
        int mx_cnt = -1;
        for (int i = 0; i < 26; i++) {
            if (b[i] > mx_cnt) {
                mx_cnt = b[i];
                mx_letter = i;
            }
        }
        mx_letter += 'a';
        printf("%c %d\n", mx_letter, mx_cnt);
    }
    return 0;
}