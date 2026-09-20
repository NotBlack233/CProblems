#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

uint64_t hashes[50];
size_t nr_hashes = 0;

uint64_t hash(const char *s, size_t n) {
    static const uint64_t base = 10007;
    uint64_t res = 0xdeadbeefbeefdead;
    for (int i = 0; i < n; i++) {
        res = res * base + s[i];
    }
    return res;
}

bool check_valid(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')
        || (c >= '0' && c <= '9') || c == '_'; 
}

int main() {
    char buf1[1000], buf2[1000];
    size_t len1, len2;
    fgets(buf1, 900, stdin);
    len1 = strlen(buf1);
    fgets(buf2, 900, stdin);
    len2 = strlen(buf2);

    int left = 0, right;
    while (left < len2) {
        if (check_valid(buf2[left])) {
            right = left;
            while (check_valid(buf2[right])) right++;
            hashes[nr_hashes++] = hash(buf2 + left, right - left);
            left = right;
        }
        left++;
    }

    left = 0;
    while (buf1[left] != ' ') left++;
    while (left < len1) {
        if (check_valid(buf1[left])) {
            right = left;
            while (check_valid(buf1[right])) right++;
            uint64_t hsh = hash(buf1 + left, right - left);
            for (int i = 0; i < nr_hashes; i++) {
                if (hsh == hashes[i]) {
                    for (int t = left; t < right; t++) {
                        putchar(buf1[t]);
                    }
                    putchar(' ');
                    break;
                }
            }
            left = right;
        }
        left++;
    }
    return 0;
}