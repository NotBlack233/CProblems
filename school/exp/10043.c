#include <stdio.h>
#include <stdlib.h>

#define N 3

typedef struct {
    int no, math, eng, cs, tot;
    char name[16];
} Student;

Student stu[N];

void input(Student *s) {
    scanf("%d%s%d%d%d", &(s->no), s->name, &(s->math), &(s->eng), &(s->cs));
    s->tot = s->math + s->eng + s->cs;
}

int cmp(const void *a, const void *b) {
    return -(((const Student *)a)->tot - ((const Student *)b)->tot);
}

int main() {
    int sum_math = 0, sum_eng = 0, sum_cs = 0;
    for (int i = 0; i < N; i++) {
        input(&stu[i]);
        sum_math += stu[i].math;
        sum_eng += stu[i].eng;
        sum_cs += stu[i].cs;
    }
    qsort(stu, N, sizeof(Student), cmp);
    double avg_math = (double)sum_math / N;
    double avg_eng = (double)sum_eng / N;
    double avg_cs = (double)sum_cs / N;

    puts("NO   Name   Maths   English   Computer   Total ");
    for (int i = 0; i < N; i++) {
        printf("%d    %s    %d    %d    %d    %d\n", stu[i].no, stu[i].name,
               stu[i].math, stu[i].eng, stu[i].cs, stu[i].tot);
    }
    printf("average of Maths:%.2lf\n", avg_math);
    printf("average of English:%.2lf\n", avg_eng);
    printf("average of Computer:%.2lf\n", avg_cs);
    return 0;
}
