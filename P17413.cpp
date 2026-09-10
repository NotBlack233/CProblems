#include <cstdint>
#include <iostream>
using namespace std;
int main() {
    uint64_t n;
    cin >> n;
    if (n <= 22360) cout << "O(n^2)" << endl;
    else if (n <= 5e8) cout << "O(n)" << endl;
    else cout << "O(1)" << endl;
    return 0;
}
