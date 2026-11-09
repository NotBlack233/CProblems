#include <stdio.h>
#include <string.h>

int main() {
    char a[100], b[100];
    fgets(a, 100, stdin);
    fgets(b, 100, stdin);
    a[strcspn(a, "\r\n")] = 0;
    printf("%s%.5s", a, b);
    return 0;
}