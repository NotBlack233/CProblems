#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool is_vowel(char c) {
    static const char vowels[] = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
    for (int i = 0; i < 10; i++) {
        if (c == vowels[i]) return true;
    }
    return false;
}

int main() {
    char buf[102];
    fgets(buf, 100, stdin);
    int len = strlen(buf);
    for (int i = 0; i < len; i++) {
        if (is_vowel(buf[i])) {
            putchar(buf[i]);
        }
    }
    return 0;
}