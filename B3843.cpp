#include <cstdint>
#include <iostream>
#include <string>
using namespace std;

enum class CharType { UPPER, LOWER, NUMS, SPECIAL, INVALID };

CharType check_letter(char c) {
    if ('A' <= c && c <= 'Z')
        return CharType::UPPER;
    if ('a' <= c && c <= 'z')
        return CharType::LOWER;
    if ('0' <= c && c <= '9')
        return CharType::NUMS;
    if (c == '!' || c == '@' || c == '#' || c == '$')
        return CharType::SPECIAL;
    return CharType::INVALID;
}

bool check(string s) {
    if (s.size() < 6 || s.size() > 12) return false;
    uint8_t types[5] = {};
    for (auto c : s) {
        CharType type = check_letter(c);
        if (type != CharType::INVALID) {
            types[(int)type] = 1;
        } else {
            return false;
        }
    }
    return (types[0] + types[1] + types[2] >= 2) && types[3];
}

int main() {
    string input;
    cin >> input;
    input += ',';
    string buf = "";
    for (auto c : input) {
        if (c == ',') {
            if (check(buf)) 
                cout << buf << '\n';
            buf = "";
        } else {
            buf += c;
        }
    }
    return 0;
}