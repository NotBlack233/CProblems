#include <stdio.h>
#include <string.h>

int decdigit(char hex) {
    if ('a' <= hex && hex <= 'f') return hex - 'a' + 10;
    if ('A' <= hex && hex <= 'F') return hex - 'A' + 10;
    return hex - '0';
}

int dec(char *hex) {
    int len = strlen(hex);
    int p = 1;
    int ans = 0;
    for (int i = len - 1; i >= 0; i--) {
        ans += p * decdigit(hex[i]);
        p *= 16;
    }
    return ans;
}

int main() {
    char buf1[20], buf2[20];
    scanf("%s%s", buf1, buf2);
    printf("%d\n", dec(buf1) + dec(buf2));
    return 0;
}