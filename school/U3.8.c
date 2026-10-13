#include <stdio.h>

int main() {
    char c = getchar();
    char offset = 'a' <= c && c <= 'z' ? 'a' : 'A';
    putchar((c - offset + 4) % 26 + offset);
    return 0;
}