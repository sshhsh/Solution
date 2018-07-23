//
// Created by cebiao zhu on 2018/7/23.
//
#include <string>
#include <map>
#include <iostream>

using namespace std;

bool wordPattern(string pattern, string str) {
    map<char, string> m1;
    map<string, char> m2;
    string::size_type pos1 = 0, pos2 = 0;
    for (char c : pattern) {
        pos2 = str.find(' ', pos1);
        string s = str.substr(pos1, pos2 - pos1);
        pos1 = pos2 + 1;
        if (!m1.count(c)) {
            if (m2.count(s))
                return false;
            m1[c] = s;
            m2[s] = c;
        } else {
            if (m1[c] != s) {
                return false;
            }
        }
    }
    if (pos2 != str.npos)
        return false;
    return true;
}

int main() {
    bool res = wordPattern("abba", "ddog cat cat fish");
    return 0;
}