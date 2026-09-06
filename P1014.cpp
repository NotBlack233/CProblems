#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int left = 1, right = 1;
    bool dir = true;
    for (int cnt = 1; cnt < n; cnt++) {
        if (dir) {
            if (left == 1) {
                right++;
                dir ^= 1;
            } else {
                left--;
                right++;
            }
        } else {
            if (right == 1) {
                left++;
                dir ^= 1;
            } else {
                left++;
                right--;
            }
        }
    }
    printf("%d/%d\n", left, right);
    return 0;
}