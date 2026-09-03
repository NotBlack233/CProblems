#include <algorithm>
#include <iostream>
using namespace std;

struct Person {
    char s[21];
    int y;
    int m;
    int d;
    int id;
} persons[101];

bool comp(Person a, Person b) {
    if (a.y != b.y) return a.y < b.y;
    if (a.m != b.m) return a.m < b.m;
    if (a.d != b.d) return a.d < b.d;
    return a.id > b.id;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> persons[i].s >> persons[i].y >> persons[i].m >> persons[i].d;
        persons[i].id = i;
    }
    sort(persons, persons + n, comp);
    for (int i = 0; i < n; i++) {
        cout << persons[i].s << '\n';
    }
    return 0;
}