//
// Created by zhucebiao on 2018/9/7.
//
#include <vector>

using namespace std;

int gcd(int a, int b) {
    while (b) {
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

bool splitArraySameAverage(vector<int> &A) {
    int n = A.size();
    if (n <= 1) return false;
    int sum = 0;
    for (int a:A) {
        sum += a;
    }
    if (sum == 0)return true;
    int g = gcd(sum, n);
    if (g == 1) return false;

    int a = sum / g, b = n / g;
    int maxSum = a * g / 2, maxN = b * g / 2;
    bool dp[maxSum + 1][n + 1][maxN + 1];
    for (int i = 0; i <= maxSum; ++i) {
        for (int j = 0; j <= n; ++j) {
            for (int k = 0; k <= maxN; ++k) {
                if (k == 0) {
                    dp[i][j][k] = (i == 0);
                    continue;
                }
                if (j < k) {
                    dp[i][j][k] = false;
                    continue;
                }
                dp[i][j][k] = dp[i][j - 1][k] || (i >= A[j - 1] && dp[i - A[j - 1]][j - 1][k - 1]);
                bool tmp = dp[i][j][k];
                if (tmp && i * b == k * a) {
                    tmp = true;
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    vector<int> a = {5, 3, 11, 19, 2};
    return splitArraySameAverage(a);
}