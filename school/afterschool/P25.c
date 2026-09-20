#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

void str_bin(char s1[], char s2[], char s[]) {
    size_t s1_len = strlen(s1), s2_len = strlen(s2);
    char *ps1 = s1, *ps2 = s2, *ps = s;
    while (ps1 < s1 + s1_len && ps2 < s2 + s2_len) {
        if (*ps1 < *ps2) {
            *ps++ = *ps1++;
        } else {
            *ps++ = *ps2++;
        }
    }
    while (ps1 < s1 + s1_len) *ps++ = *ps1++;
    while (ps2 < s2 + s2_len) *ps++ = *ps2++;
    *ps = '\0';
}

int main() {
    char buf1[1010], buf2[1010], bufs[2020];
    scanf("%s %s", buf1, buf2);
    str_bin(buf1, buf2, bufs);
    printf("%s\n", bufs);
    return 0;
}