#include <iostream>
#include <queue>
#include <cstdlib>
using namespace std;

bool hsh[1001] = {};
queue<int> q;

int main() {
    int m, n, cnt = 0;
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        int word;
        cin >> word;
        if (!hsh[word]) {
            cnt++;
            q.push(word);
            hsh[word] = true;
            if (q.size() > (unsigned) m) {
                hsh[q.front()] = false;
                q.pop();
            }
        }
    }
    cout << cnt << endl;
    return 0;
}