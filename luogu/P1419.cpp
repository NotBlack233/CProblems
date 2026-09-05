#include <deque>
#include <iostream>
using namespace std;

const int N = 1e5 + 1;
const double eps = 1e-5;

int n, s, t;
int a[N];

bool check(double minx) {
    deque<int> q; // index
    double sum[N] = {0};
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + (double) a[i] - minx;
    }
    for (int i = s; i <= n; i++) {
        while (!q.empty() && sum[q.back()] > sum[i - s]) q.pop_back();
        while (!q.empty() && q.front() <= i - t) q.pop_front();
        q.push_back(i - s);
        if (sum[i] - sum[q.front()] >= 0) return true;
    }
    return false;
}

int main() {
    cin >> n >> s >> t;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    double left = -1e4, right = 1e4;
    while (right - left > eps) {
        double mid = (left + right) / 2;
        if (check(mid)) left = mid;
        else right = mid;
    }
    printf("%.3lf\n", left);
    return 0;
}
