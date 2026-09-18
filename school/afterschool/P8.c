#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int num;
    int cnt;
} Rec;

Rec nums[1000];
int len = 0;

bool is_prime(int n) {
    if (n == 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 2; n > 1; i++) {
        if (is_prime(i)) {
            nums[len].num = i;
            while (n > 1 && n % i == 0) {
                n /= i;
                nums[len].cnt++;
            }
        }
        len++;
    }
    for (int i = 0; i < len; i++) {
        if (nums[i].cnt > 1) {
            printf("%d ", nums[i].num);
        }
    }
    return 0;
}