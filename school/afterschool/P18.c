#include <stdio.h>

int a[110];

int main() {
    int n, q;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    scanf("%d", &q);
    // int left = 1, right = n;
    // while (left < right) {
    //     int mid = (left + right) >> 1;
    //     if (a[mid] > q) right = mid;
    //     else left = mid + 1;
    // }
    // if (a[left - 1] == q) {
    //     printf("%d\n", left - 1);
    // } else {
    //     puts("no\n");
    // }
    for (int i = 1; i <= n; i++) {
        if (a[i] == q) {
            printf("%d\n", i);
            return 0;
        }
    }
    puts("no\n");
    return 0;
}
