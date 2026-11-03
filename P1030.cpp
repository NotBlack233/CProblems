#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

void traverse(string inord, string postord) {
    if (inord.empty()) return;
    char root = postord.back();
    putchar(root);
    int ridx = inord.find(root);
    traverse(inord.substr(0, ridx), postord.substr(0, ridx));
    traverse(inord.substr(ridx + 1), postord.substr(ridx, inord.size() - ridx - 1));
}

int main() {
    string inorder, postorder;
    cin >> inorder >> postorder;
    traverse(inorder, postorder);
    return 0;
}