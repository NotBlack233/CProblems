#include <stdio.h>
#include <string.h>

int lps[110];

void build_lps(char *p) {
    int len = 0;
    for (int i = 1; p[i] != '\0'; i++) {
        while (len != 0 && p[i] != p[len]) {
            len = lps[len - 1];
        }
        if (p[i] == p[len]) len++;
        lps[i] = len;
    }
}

int kmp(char *s, char *p) {
    int i = 0, j = 0;
    while (s[i] != '\0') {
        if (s[i] == p[j]) {
            i++;
            j++;
            if (p[j] == '\0') {
                return i - j;
            }
        } else if (j > 0) {
            j = lps[j - 1];
        } else i++;
    }
    return -1;
}

int main() {
    char str[1001], ori[30], sub[20];
    fgets(str, 100, stdin);
    str[strcspn(str, "\r\n")] = 0;
    while (1) {
        scanf("%s %s", ori, sub);
        if (!(strcmp(ori, "0") || strcmp(sub, "0"))) {
            break;
        }
        build_lps(ori);
        int res = -1;
        char buf[1001];
        char *bufp = buf, *strp = str;
        while (1) {
            int t = kmp(str + res + 1, ori);
            if (t == -1) break;
            res = t + res + 1;
            while (strp - str < res) {
                *bufp++ = *strp++;
            }
            strp += strlen(ori);
            char *subp = sub;
            while (*subp) *bufp++ = *subp++;
        }
        while (*strp) *bufp++ = *strp++;
        *bufp = 0;
        strcpy(str, buf);
    }
    puts(str);
    return 0;
}