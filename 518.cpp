//
// Created by cebiao zhu on 2018/9/1.
//
#include <vector>

using namespace std;

int change(int amount, vector<int> &coins) {
    int *m = new int[amount + 1];
    for (int i = 0; i <= amount; ++i) {
        m[i] = 0;
    }
    m[0] = 1;
    for (int c:coins) {
        for (int i = c; i <= amount; ++i) {
            m[i] += m[i - c];
        }
    }
    return m[amount];
}

int main() {
    vector<int> coins = {1, 5, 2};
    int res = change(13, coins);
    return res;
}