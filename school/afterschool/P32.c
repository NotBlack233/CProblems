#include <stdio.h>
#include <stdint.h>

typedef struct {
    int id, data;
} Record;

void input(int a[10]) {
    for (int i = 0; i < 10; i++) {
        scanf("%d", a + i);
    }
}

void process(int a[10]) {
    Record rec = {-1, INT32_MAX};
    int t;
    for (int i = 0; i < 10; i++) {
        if (a[i] < rec.data) {
            rec = (Record){i, a[i]};
        }
    }
    t = a[0];
    a[0] = a[rec.id];
    a[rec.id] = t;

    rec = (Record){-1, INT32_MIN};
    for (int i = 0; i < 10; i++) {
        if (a[i] > rec.data) {
            rec = (Record){i, a[i]};
        }
    }
    t = a[9];
    a[9] = a[rec.id];
    a[rec.id] = t;
}

void output(int a[10]) {
    for (int i = 0; i < 10; i++) {
        printf("%d ", a[i]);
    }
}

int main() {
    int a[10];
    input(a);
    process(a);
    output(a);
    return 0;
}