#include <stdio.h>
#include <stdbool.h>

int months[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool is_leap(int year) {
    return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

int main() {
    int y, m, d;
    scanf("%d %d %d", &y, &m, &d);
    int ans = 0;
    for (int i = 1; i < m; i++)
        ans += (i == 2 && is_leap(y) ? 29 : months[i]);
    ans += d;
    printf("%d\n", ans);
    return 0;
}