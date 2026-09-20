#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int left, right;
} Section;

bool check_letter(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

int main() {
    char s[100];
    fgets(s, 90, stdin);
    Section sec = {0, -1};
    int left = 0, right = 0, slen = strlen(s);
    while (right < slen) {
        if (check_letter(s[right])) {
            if (left == 0x7fffffff) {
                left = right;
            }
        } else {
            if (right - left > sec.right - sec.left) {
                sec = (Section){left, right};
            }
            left = 0x7fffffff;
        }
        right++;
    }
    for (int i = sec.left; i < sec.right; i++) {
        putchar(s[i]);
    }
    return 0;
}