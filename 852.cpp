//
// Created by cebiao zhu on 2018/7/6.
//

#include <vector>
#include <iostream>

using namespace std;

int peakIndexInMountainArray(vector<int> &A) {
    int pos = A.size() / 2;
    int left = 0;
    int right = A.size();
    bool up, down;
    while (true) {
        up = pos == 0 || A[pos] > A[pos - 1];
        down = pos == (A.size() - 1) || A[pos] > A[pos + 1];
        if (up && down) {
            return pos;
        } else if (up) {
            left = pos;
            pos = (pos + right) / 2;
        } else if (down) {
            right = pos;
            pos = (pos + left) / 2;
        }
    }
}

int main852() {
    int arr[10] = {40, 48, 61, 75, 100, 99, 98, 39, 30, 10};
    vector<int> vec(arr, arr + 10);
    cout << peakIndexInMountainArray(vec);
    return 0;
}
