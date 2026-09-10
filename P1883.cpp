#include <cstdio>
#include <iostream>
using namespace std;

const int N = 1e4 + 1;
const double eps = 1e-9;

struct QuadrFunc {
    int a;
    int b;
    int c;
};

int n;
QuadrFunc func[N];

double calc(double x) {
    double ans = func[1].a * x * x + func[1].b * x + func[1].c;
    for (int i = 2; i <= n; i++)
        ans = max(ans, func[i].a * x * x + func[i].b * x + func[i].c);
    return ans;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> func[i].a >> func[i].b >> func[i].c;
        double left = 0, right = 1000;
        while (right - left > eps) {
            double d = (right - left) / 3;
            double mid1 = left + d;
            double mid2 = right - d;
            double res1 = calc(mid1);
            double res2 = calc(mid2);
            // printf("mid1 = %lf, res1 = %lf, mid2 = %lf, res2 = %lf\n", mid1, res1, mid2, res2);
            // printf("left = %lf, right = %lf\n", left, right);
            if (res1 < res2) right = mid2;
            else left = mid1;
        }
        printf("%.4lf\n", calc(left));
    }
    return 0;
}