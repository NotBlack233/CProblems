#include <cstring>
#include <iostream>
#include <ostream>
#include <string>
using namespace std;

char mp[26], rev_mp[26];

int main() {
    memset(mp, -1, sizeof(mp));
    memset(rev_mp, -1, sizeof(rev_mp));
    string enc, dec;
    cin >> enc;
    for (int i = 0; i < enc.size(); i++) {
        char c;
        cin >> c;
        if ((mp[enc[i] - 'A'] != -1 && mp[enc[i] - 'A'] != c) || (rev_mp[c - 'A'] != -1 && rev_mp[c - 'A'] != enc[i])) goto failed;
        mp[enc[i] - 'A'] = c;
        rev_mp[c - 'A'] = enc[i];
    }
    for (auto c : mp) {
        if (c == -1) goto failed;
    }
    cin >> enc;
    for (auto c : enc) {
        if (mp[c - 'A'] == -1) goto failed;
        dec += mp[c - 'A'];
    }
    cout << dec << endl;
    return 0;

failed:
    cout << "Failed" << endl;
    return 0;
}