#include <stdio.h>

const char *const months[13] = {
    0xdeadbeef,
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
};

int main() {
    int n;
    scanf("%d", &n);
    if (n >= 1 && n <= 12)
        printf("%s\n", months[n]);
    else
        puts("error\n");
    return 0;
}