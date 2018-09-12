//
// Created by zhucebiao on 2018/9/12.
//
#include <vector>
#include <set>

using namespace std;

int kadane(vector<int> &v, int k) {
    int max = INT_MIN;
    int sum = 0;
    set<int> s;
    s.insert(0);
    for (auto a:v) {
        sum += a;
        auto gap = s.lower_bound(sum - k);
        if (gap != s.end())
            max = max > (sum - *gap) ? max : sum - *gap;
        s.insert(sum);
    }
    return max;
}

int maxSumSubmatrix(vector<vector<int>> &matrix, int k) {
    auto num_rows = matrix.size();
    auto num_columns = matrix[0].size();
    vector<int> res;
    if (num_columns >= num_rows) {

        for (auto it1 = matrix.begin(); it1 != matrix.end(); it1++) {
            vector<int> tmp;
            tmp.resize(num_columns);
            for (auto it2 = it1; it2 != matrix.end(); it2++) {
                auto it = tmp.begin();
                for (auto a:*it2) {
                    *it += a;
                    it++;
                }
                res.push_back(kadane(tmp, k));
            }
        }
    } else {

        for (int i = 0; i < num_columns; ++i) {
            vector<int> tmp;
            tmp.resize(num_rows);
            for (int j = i; j < num_columns; ++j) {
                auto it = tmp.begin();
                for (auto row:matrix) {
                    *it += row[j];
                    it++;
                }
                res.push_back(kadane(tmp, k));
            }
        }
    }

    int max = INT_MIN;
    for (auto a:res) {
        if (a > max) {
            max = a;
        }
    }
    return max;
}

int main() {
    vector<vector<int>> m = {{5,  -4, -3, 4},
                             {-3, -4, 4,  5},
                             {5,  1,  5,  -4}};
    int res = maxSumSubmatrix(m, 8);
    return res;
}