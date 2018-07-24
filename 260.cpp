//
// Created by zhucebiao on 2018/7/24.
//
#include <vector>

using namespace std;

vector<int> singleNumber(vector<int> &nums) {
    int tmp = 0;
    for (int num : nums) {
        tmp = tmp ^ num;
    }
    int mask = 1;
    while (mask) {
        if (tmp & mask)
            break;
        mask = mask << 1;
    }
    int tmp1 = 0, tmp2 = 0;
    for (int num : nums) {
        if (num & mask) {
            tmp1 = tmp1 ^ num;
        } else {
            tmp2 = tmp2 ^ num;
        }
    }
    vector<int> res;
    res.push_back(tmp1);
    res.push_back(tmp2);
    return res;
}

int main() {
    vector<int> a = {1, 2, 1, 3, 2, 5};
    vector<int> res = singleNumber(a);
    return 0;
}