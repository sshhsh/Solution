//
// Created by sshhsh on 2018/9/9.
//
#include <vector>

using namespace std;

int leastInterval(vector<char> &tasks, int n) {
    int num[26];
    int interval[26];
    for (int i = 0; i < 26; ++i) {
        num[i] = 0;
        interval[i] = 0;
    }
    for (auto task:tasks) {
        num[task - 'A']++;
    }
    int res = 0;
    while (true) {
        int max = 0, max2 = 0, current = -1;
        for (int i = 0; i < 26; ++i) {
            if (num[i] >= max) {
                max = num[i];
            }
            if (num[i] >= max2 && interval[i] == 0) {
                current = i;
                max2 = num[i];
            }
        }
        if (max == 0)break;
        res++;
        for (int &i : interval) {
            if (i > 0)
                i--;
        }
        if (current != -1) {
            num[current]--;
            interval[current] = n;
        }
    }
    return res;
}

int main() {
    vector<char> v = {'A', 'A', 'A', 'A', 'A', 'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    int res = leastInterval(v, 2);
    return res;
}