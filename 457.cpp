//
// Created by cebiao zhu on 2018/7/20.
//
#include <vector>
#include <iostream>

using namespace std;

int l;

bool circularArrayLoop(vector<int> &nums) {
    l = (int) nums.size();

    for (int i = 0; i < l; ++i) {
        nums[i] = nums[i] % l;
    }

    for (int i = 0; i < l; ++i) {
        int current = i;
        int init = nums[current];
        if (init % l == 0)
            continue;

        while (true) {
            int next = ((current + nums[current]) % l + l) % l;
            nums[current] = i * l + l;
            current = next;
            if (nums[next] * init < 0)
                break;
            if (nums[next] == i * l + l)
                return true;
            else if (nums[next] % l == 0)
                break;
        }
    }
    return false;
}

//int main() {
//    vector<int> n = {-11,-20,-10,-4,-5,16,27,31,19,10};
//    bool res = circularArrayLoop(n);
//    cout << res;
//}