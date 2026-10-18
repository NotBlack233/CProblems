#include <stdio.h>
#include <string.h>

int main() {
    char buf[100];
    scanf("%s", buf);
    for (int i = 0; i < strlen(buf); i++) {
        printf("%c  ", buf[i]);
    }
    return 0;
}