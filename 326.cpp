//
// Created by cebiao zhu on 2018/7/20.
//

bool isPowerOfThree(int n) {
    if (n <= 0)return false;
    return 1162261467 % n == 0;
}