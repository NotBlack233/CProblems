#include <cstdint>
#include <iostream>
using namespace std;

int key[101];

int main() {
    string k, enc;
    cin >> k >> enc;
    int key_len = k.size();
    for (int i = 0; i < key_len; i++) {
        key[i] = k[i] >= 'A' && k[i] <= 'Z' ? k[i] - 'A' : k[i] - 'a';
    }
    int k_idx = 0;
    for (auto c : enc) {
        bool upper = c >= 'A' && c <= 'Z';
        int8_t data = (upper ? c - 'A' : c - 'a') - key[k_idx++];
        if (data < 0) data += 26;
        if (k_idx >= key_len) k_idx = 0;
        cout << (char)(data + (upper ? 'A' : 'a'));
    }
    cout << endl;
    return 0;
}