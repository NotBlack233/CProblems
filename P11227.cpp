#include <bits/stdc++.h>
using namespace std;

bool a[60];

constexpr int color(char c) {
    switch (c) {
        case 'D': return 0;
        case 'C': return 1;
        case 'H': return 2;
        case 'S': return 3;
    }
    return -1;
}

constexpr int amount(char c) {
    if ('2' <= c && c <= '9') return c - '0';
    switch (c) {
        case 'A': return 1;
        case 'T': return 10;
        case 'J': return 11;
        case 'Q': return 12;
        case 'K': return 0;
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    getchar();
    while (n--) {
        char x = getchar(), y = getchar();
        getchar();
        // printf("%d\n", color(x) * 13 + amount(y));
        a[color(x) * 13 + amount(y)] = true;
    }
    int cnt = 0;
    for (int i = 0; i < 52; i++) {
        if (!a[i]) cnt++;
    }
    cout << cnt << endl;
    return 0;
}
