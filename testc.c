#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        if (i == 5)
            goto _for_break;
        printf("%d ", i);
    }
    puts("\nFoo Bar");
_for_break:
    return 0;
}
