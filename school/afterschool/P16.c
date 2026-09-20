#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define max(a,b) (((a) > (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))

int main() {
    int n;
    scanf("%d", &n);

    int minx = INT32_MAX, maxx = INT32_MIN;
    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        minx = min(minx, t);
        maxx = max(maxx, t);
    }
    printf("%d %d\n", maxx, minx);
    return 0;
}