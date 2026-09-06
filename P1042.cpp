#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

const int N = 25 * 2502;

char record[N];
int len = 0;

void solve(int format) {
    int left = 0, right = 0;
    for (int i = 0; i < len; i++) {
        if (record[i] == 'W') left++;
        else if (record[i] == 'L') right++;
        if ((left >= format || right >= format) && abs(left - right) >= 2) {
            printf("%d:%d\n", left, right);
            left = 0;
            right = 0;
        }
    }
    printf("%d:%d\n", left, right);
    cout << endl;
}

int main() {
    while (cin >> record[len++]) {
        if (record[len - 1] == 'E') {
            len--;
            break;
        }
    }
    solve(11);
    solve(21);
    return 0;
}