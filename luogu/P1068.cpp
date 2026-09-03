#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

struct Person {
    int k;
    int s;
} persons[5001];

bool comp(Person a, Person b) {
    if (a.s != b.s) return a.s > b.s;
    return a.k < b.k;
}

int main() {
    int n, m;
    cin >> n >> m;
    int planned = 1.5 * m;
    for (int i = 0; i < n; i++) {
        cin >> persons[i].k >> persons[i].s;
    }
    sort(persons, persons + n, comp);
    int score_min = persons[planned - 1].s;
    queue<Person> q;
    for (int i = 0; i < n; i++) {
        if (persons[i].s < score_min) {
            break;
        }
        q.push(persons[i]);
    }
    cout << score_min << ' ' << q.size() << '\n';
    while (!q.empty()) {
        cout << q.front().k << ' ' << q.front().s << '\n';
        q.pop();
    }
    return 0;
}