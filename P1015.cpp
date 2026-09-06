#include <cstdint>
#include <cstring>
#include <iostream>
using namespace std;

uint8_t nums[2][200];
uint8_t s[2];

bool check(uint8_t *num, uint8_t size) {
    int mid = (size - 2) >> 1;
    for (int i = 0; i <= mid; i++) {
        int j = size - 1 - i;
        if (num[i] != num[j]) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    string num;
    cin >> num;
    s[0] = num.size();
    for (int i = s[0] - 1; i >= 0; i--) {
        if (num[i] >= '0' && num[i] <= '9') {
            nums[0][s[0] - 1 - i] = num[i] - '0';
        } else if (num[i] >= 'A' && num[i] <= 'F') {
            nums[0][s[0] - 1 - i] = num[i] - 'A' + 10;
        } else {
            return -1;
        }
    }
    bool cur = 0;
    int step = 0;
    for (; !(step > 30 || check(nums[cur], s[cur])); step++) {
        memset(nums[cur ^ 1], 0, sizeof(nums[0]));
        for (int i = 0; i < s[cur]; i++) {
            nums[cur ^ 1][i] += nums[cur][i] + nums[cur][s[cur] - 1 - i];
            if (nums[cur ^ 1][i] >= n) {
                nums[cur ^ 1][i] %= n;
                nums[cur ^ 1][i + 1]++;
            }
        }
        s[cur ^ 1] = s[cur];
        if (nums[cur ^ 1][s[cur]]) s[cur ^ 1]++;
        cur ^= 1;
    }
    if (step > 30) cout << "Impossible!" << endl;
    else cout << "STEP=" << step << endl;
    return 0;
}