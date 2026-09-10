#include <stdio.h>

int main() {
    char prev = ' ', cur;
    while (scanf("%c", &cur) != EOF) {
        if (prev == ' ' && cur >= 'a' && cur <= 'z')
            putchar(cur - ('a' - 'A'));
        else putchar(cur);
        prev = cur;
    }
    return 0;
}
