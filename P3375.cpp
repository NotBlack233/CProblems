#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e6 + 10;

class KMP {
private:
    const string p;
    vector<int> lps;
    
    void build_lps() {
        int k = 0;
        for (int i = 1; i < (int)this->p.size(); i++) {
            while (k > 0 && p[i] != p[k]) {
                k = this->lps[k - 1];
            }
            if (p[i] == p[k]) {
                k++;
            }
            this->lps[i] = k;
        }
    }
public:
    KMP(const string &pat): p(pat), lps(pat.size()) {
        if (pat.size() == 0) {
            throw new invalid_argument("pat.size() must not be 0");
        }
        build_lps();
    }

    vector<int> find(const string &s) const {
        int i = 0, j = 0;
        vector<int> res;
        while (i < (int)s.size()) {
            if (s[i] == this->p[j]) {
                i++;
                j++;
                if (j == this->p.size()) {
                    res.push_back(i - j);
                    j = lps[this->p.size() - 1];
                }
            } else {
                if (j > 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        return res;
    }

    const vector<int> &get_lps() const {
        return lps;
    }
};

int main() {
    string t, p;
    cin >> t >> p;

    KMP kmp(p);
    vector<int> res = kmp.find(t);
    for (int idx : res) {
        cout << idx + 1 << '\n';
    }
    for (auto i : kmp.get_lps()) {
        cout << i << ' ';
    }
    return 0;
}