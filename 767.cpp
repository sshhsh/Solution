//
// Created by zhucebiao on 2018/9/11.
//
#include <string>
#include <unordered_map>

using namespace std;

pair<char, int> getMax(unordered_map<char, int> &m, char c) {
    int max = 0;
    pair<char, int> res;
    for (auto p:m) {
        if (max < p.second && p.first != c) {
            max = p.second;
            res = p;
        }
    }
    return res;
}

string reorganizeString(string S) {
    unordered_map<char, int> m;
    for (char c:S) {
        if (m.count(c) == 0)
            m[c] = 1;
        else
            m[c]++;
    }

    if (getMax(m, 0).second > (S.length() + 1) / 2)
        return "";
    string res;
    for (int i = 0; i < S.length(); i++) {
        auto it = getMax(m, res.back());
        res.push_back(it.first);
        m[it.first]--;
    }
    return res;
}

int main() {
    string res = reorganizeString("aaab");
    return 0;
}