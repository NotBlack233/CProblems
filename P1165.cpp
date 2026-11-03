#include <bits/stdc++.h>
using namespace std;
int main() {
    stack<int> st;
    int n;
    cin >> n;
    while (n--) {
        int t;
        cin >> t;
        switch (t) {
        case 0:
            int x;
            cin >> x;
            st.push(max(st.empty() ? -1 : st.top(), x));
            break;
        case 1:
            if (!st.empty()) st.pop();
            break;
        case 2:
            cout << (st.empty() ? 0 : st.top()) << '\n';
            break;
        }
    }
    return 0;
}