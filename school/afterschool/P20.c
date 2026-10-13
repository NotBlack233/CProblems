#include <stdio.h>

int cnt[10];

int main() {
    for (;;) {
        int t;
        scanf("%d", &t);
        if (t == -1) break;
        cnt[t]++;
    }
    for (int i = 0; i < 10; i++) {
        printf("%d ", cnt[i]);
    }
    return 0;
}