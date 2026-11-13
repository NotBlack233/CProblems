#include <stdio.h>

int mdays[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void wday_inc(int *wday) {
    (*wday)++;
    if (*wday > 7) *wday = 1;
}

void date_inc(int *month, int *mday) {
    (*mday)++;
    if (*mday > mdays[*month]) {
        *mday = 1;
        (*month)++;
    }
}

int main() {
    int wday, mday = 1, month = 1;
    scanf("%d", &wday);
    while (month != 12 || mday != 31) {
        if (wday == 5 && mday == 13) {
            printf("%d\n", month);
        }
        wday_inc(&wday);
        date_inc(&month, &mday);
    }
    return 0;
}