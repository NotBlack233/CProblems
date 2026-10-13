#include <limits.h>
#include <stdio.h>

int main() {
    int mx = INT_MIN;
    for (int i = 0; i < 3; i++) {
        int t;
        scanf("%d", &t);
        mx = t > mx ? t : mx;
    }
    printf("%d\n", mx);
    return 0;
}