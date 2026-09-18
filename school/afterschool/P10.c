#include <stdio.h>

int cube(int x) {
    return ((x) * (x) * (x));
}

int main() {
    for (int i = 100; i < 1000; i++) {
        if (cube(i / 100) + cube(i / 10 % 10) + cube(i % 10) == i)
            printf("%d ", i);
    }
    return 0;
}