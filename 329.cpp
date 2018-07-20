//
// Created by cebiao zhu on 2018/7/20.
//
#include <vector>
#include <iostream>

using namespace std;

int w, h;

int walk(int a, int b, int *m, vector<vector<int>> &matrix) {
    if (m[a * w + b] != -1) {
        return m[a * w + b];
    }
    //up
    if (a > 0 && matrix[a][b] < matrix[a - 1][b]) {
        int res = walk(a - 1, b, m, matrix) + 1;
        if (res > m[a * w + b])
            m[a * w + b] = res;
    }
    //down
    if (a < h - 1 && matrix[a][b] < matrix[a + 1][b]) {
        int res = walk(a + 1, b, m, matrix) + 1;
        if (res > m[a * w + b])
            m[a * w + b] = res;
    }
    //left
    if (b > 0 && matrix[a][b] < matrix[a][b - 1]) {
        int res = walk(a, b - 1, m, matrix) + 1;
        if (res > m[a * w + b])
            m[a * w + b] = res;
    }
    //right
    if (b < w - 1 && matrix[a][b] < matrix[a][b + 1]) {
        int res = walk(a, b + 1, m, matrix) + 1;
        if (res > m[a * w + b])
            m[a * w + b] = res;
    }
    if (m[a * w + b] == -1) {
        m[a * w + b] = 1;
        return 1;
    } else {
        return m[a * w + b];
    }
}

int longestIncreasingPath(vector<vector<int>> &matrix) {
    h = (int) matrix.size();
    if (h == 0)
        return 0;
    w = (int) matrix[0].size();
    if (w == 0)
        return 0;

    auto m = new int[w * h];
    for (int i = 0; i < w * h; ++i) {
        m[i] = -1;
    }
    int res = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            int tmp = walk(i, j, m, matrix);
            if (tmp > res) {
                res = tmp;
            }
        }
    }
    return res;
}

//int main() {
//    vector<vector<int>> martix = {{9, 9, 4},
//                                  {6, 6, 8},
//                                  {2, 1, 1}};
//    int res = longestIncreasingPath(martix);
//    cout << res;
//}