//
// Created by cebiao zhu on 2018/7/20.
//
#include <string>
#include <vector>
#include <iostream>

using namespace std;

void check(string s, vector<vector<string>> &v, vector<string> &tmp) {
    for (int i = 0; i < s.length(); ++i) {
        int j = 0;
        bool flag = true;
        while (j < (i + 1) / 2) {
            if (s[j] != s[i - j]) {
                flag = false;
                break;
            }
            j++;
        }

        if (flag) {
            tmp.push_back(s.substr(0, i + 1));
            if (i + 1 == s.length()) {
                v.push_back(tmp);
                tmp.pop_back();
                break;
            }
            check(s.substr(i + 1), v, tmp);
            tmp.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> v;
    vector<string> tmp;
    check(s, v, tmp);
    return v;
}

//int main() {
//    vector<vector<string>> p = partition("aabbb8998");
//    cout << "a";
//}