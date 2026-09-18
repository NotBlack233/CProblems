#include <iostream>
#include <stack>
using namespace std;

stack<char> digits;

int main() {
    int n, r;
    cin >> n >> r;
    printf("%d=", n);
    while (n) {
        int res = n % r;
        if (res < 0) {
            n += r;
            res -= r;
        }
        n /= r;
        digits.push(res);
    }
    while (!digits.empty()) {
        putchar(digits.top() < 10 ? digits.top() + '0' : digits.top() - 10 + 'A');
        digits.pop();
    }
    printf("(base%d)\n", r);
    return 0;
}