//
// Created by zhucebiao on 2018/9/10.
//
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

bool comp(const string &a, const string &b) {
    int res = 0;
    for (auto ita = a.begin(), itb = b.begin(); ita != a.end(); ita++) {
        if (*ita != *itb) {
            res++;
        }
        if (res > 1)
            return false;
        itb++;
    }
    return res == 1;
}

int minMutation(string start, string end, vector<string> &bank) {
    bool flag = false;
    for (auto b:bank) {
        if (b.compare(end) == 0) {
            flag = true;
            break;
        }
    }
    if (!flag) {
        return -1;
    }
    unordered_map<string, int> map;
    queue<string> q;
    q.push(start);
    map.emplace(start, 0);
    while (!q.empty()) {
        auto tmp = q.front();
        q.pop();
        for (auto b:bank) {
            if (map.count(b) == 0 && comp(b, tmp)) {
                if (b.compare(end) == 0)
                    return map[tmp] + 1;
                map.emplace(b, map[tmp] + 1);
                q.push(b);
            }
        }
    }
    return -1;
}

int main() {
    vector<string> bank = {"AACCGGTA", "AACCGCTA", "AAACGGTA"};
    int res = minMutation("AACCGGTT", "AAACGGTA", bank);
    return 0;
}