#include <stdio.h>
#include <string.h>

typedef struct {
    int len;
    char *d[202];
} data;

data stu[13][32];
char id[201][13];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int m, d;
        scanf(" %s%d%d", id[i], &m, &d);
        stu[m][d].d[stu[m][d].len++] = id[i];
    }
    for (int m = 1; m <= 12; m++) {
        for (int d = 1; d <= 31; d++) {
            if (stu[m][d].len > 0) {
                printf("%d %d ", m, d);
                for (int i = 0; i < stu[m][d].len; i++) {
                    printf("%s ", stu[m][d].d[i]);
                }
                putchar('\n');
            }
        }
    }
    return 0;
}