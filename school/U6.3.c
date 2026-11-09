#include <stdio.h>

int main() {
    int n, sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int t;
            scanf("%d", &t);
            if (i == j) sum += t;
        }
    }
    printf("%d", sum);
    return 0;
}