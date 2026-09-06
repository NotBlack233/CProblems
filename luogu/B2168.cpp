#include <cstdint>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int n;
vector<string> strings;
vector<string> str_codes;

struct Node {
    uint64_t weight;
    int str_id;
    Node *left;
    Node *right;
};

void traverse(Node *root, string code) {
    if (root == nullptr) return;
    if (root->str_id != -1) {
        str_codes[root->str_id] = code;
        return;
    }
    traverse(root->left, code + "0");
    traverse(root->right, code + "1");
}

int main() {
    auto comp = [](Node *a, Node *b){ return a->weight > b->weight; };
    priority_queue<Node *, vector<Node *>, decltype(comp)> roots(comp);
    cin >> n;
    if (n == 1) {
        string s;
        int w;
        cin >> s >> w;
        cout << s << ' ' << 0 << endl;
        return 0;
    }
    str_codes.reserve(n);
    for (int i = 0; i < n; i++) {
        string s;
        uint64_t w;
        cin >> s >> w;
        strings.push_back(s);
        roots.push(new Node{w, i, nullptr, nullptr});
    }
    while (roots.size() > 1) {
        Node *a = roots.top();
        roots.pop();
        Node *b = roots.top();
        roots.pop();
        Node *root = new Node{a->weight + b->weight, -1, a, b};
        roots.push(root);
    }
    Node *root = roots.top();
    roots.pop();
    traverse(root, "");
    for (int i = 0; i < n; i++) cout << strings[i] << ' ' << str_codes[i] << '\n';;
    return 0;
}
