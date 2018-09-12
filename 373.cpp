//
// Created by zhucebiao on 2018/9/11.
//
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k) {
    vector<pair<int, int>> tmp, res;

    for (auto it1:nums1) {
        for (auto it2:nums2) {
            tmp.emplace_back(it1, it2);
        }
    }
    sort(tmp.begin(), tmp.end(), [](pair<int, int> &a, pair<int, int> &b) {
        return (a.first + a.second) < (b.first + b.second);
    });
    for (int i = 0; i < k && i < tmp.size(); ++i) {
        res.push_back(tmp[i]);
    }
    return res;
}

int main() {
    vector<int> n1 = {1, 7, 11};
    vector<int> n2 = {2, 4, 6};
    auto res = kSmallestPairs(n1, n2, 8);
    return 0;
}