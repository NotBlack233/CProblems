#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[12];
    int no, chinese, math, english;
    int total;
} Student;

Student stu[20];

int comp(const void *a, const void *b) {
    const Student *sa = a, *sb = b;
    if (sa->total != sb->total) return sb->total - sa->total;
    return sa->no - sb->no;
}

int main() {
    int n;
    scanf("%d", &n);
    if (n >= 10) {
        puts("Please input 1-9.");
        return 0;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d %s %d %d %d", &stu[i].no, stu[i].name, &stu[i].math, &stu[i].english, &stu[i].chinese);
        stu[i].total = stu[i].chinese + stu[i].english + stu[i].math;
    }
    qsort(stu, n, sizeof(Student), comp);
    int rank = 1, realrank = 1;
    for (int i = 0; i < n; i++) {
        printf("%4d%10d%10s%5d%5d%5d\n", rank, stu[i].no, stu[i].name, stu[i].math, stu[i].english, stu[i].chinese);
        realrank++;
        if (i != n - 1 && stu[i].total != stu[i + 1].total) {
            rank = realrank;
        }
    }
    return 0;
}