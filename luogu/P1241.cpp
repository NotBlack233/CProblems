#include <cstddef>
#include <deque>
#include <iostream>
using namespace std;

using node = pair<int, char>;

deque<node> st;

inline const char *get_para(char c) {
    if (c == '(' || c == ')') return "()";
    if (c == '[' || c == ']') return "[]";
    return "";
}

int main() {
    string s;
    cin >> s;
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '[') st.push_back({i, s[i]});
        else if (s[i] == ')') {
            if (st.back().second == '(') {
                st.pop_back();
            } else {
                st.push_back({i, ')'});
            }
        } else if (s[i] == ']') {
            if (st.back().second == '[') {
                st.pop_back();
            } else {
                st.push_back({i, ']'});
            }
        }
    }
    for (size_t i = 0; i < s.size(); i++) {
        if (!st.empty() && st.front().first == i) {
            cout << get_para(st.front().second);
            st.pop_front();
        } else {
            cout << s[i];
        }
    }
    return 0;
}
