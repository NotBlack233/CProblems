#include <iostream>
using namespace std;

const int pow2[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};

enum class TreeType : char {
    F = 'F', B = 'B', I = 'I'
};

struct Node {
    TreeType type;
    Node *left, *right;
};

int n;
string s;

inline TreeType from_char(char c) {
    return c == '0' ? TreeType::B : TreeType::I;
}

Node *make_tree(int l, int r) {
    if (l == r) {
        return new Node {from_char(s[l]), nullptr, nullptr};
    }
    int mid = (l + r) >> 1;
    Node *left = make_tree(l, mid);
    Node *right = make_tree(mid + 1, r);

    TreeType type = left->type == right->type ? left->type : TreeType::F;
    Node *root = new Node {type, left, right};
    return root;
}

void traverse(Node *root) {
    if (!root) return;
    traverse(root->left);
    traverse(root->right);
    cout << static_cast<char>(root->type);
}

int main() {
    cin >> n >> s;
    traverse(make_tree(0, pow2[n] - 1));
    return 0;
}
