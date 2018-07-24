//
// Created by zhucebiao on 2018/7/24.
//
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

static bool comp(string &a, string &b) {
    return a.length() > b.length();
}

bool check(string &a, string &b) {
    if (a.length() > b.length())return false;
    for (int i = 0, j = 0; i < a.length(); ++i) {
        while (a[i] != b[j]) {
            ++j;
            if (a.length() - i > b.length() - j)
                return false;
        }
        ++j;
    }
    return true;
}

int findLUSlength(vector<string> &strs) {
    sort(strs.begin(), strs.end(), comp);
    bool flag;
    for (int i = 0; i < strs.size(); ++i) {
        flag = false;
        for (int j = 0; j < strs.size(); ++j) {
            if (i == j)continue;
            if (check(strs[i], strs[j])) {
                flag = true;
                break;
            }
        }
        if (!flag)
            return int(strs[i].length());
    }
    return -1;
}

int main() {
    vector<string> s = {"aabbcc", "aabbcc","bc","bcc"};
    int res = findLUSlength(s);
    return 0;
}