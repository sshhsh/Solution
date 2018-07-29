//
// Created by cebiao zhu on 2018/7/29.
//
#include <string>

using namespace std;

int numDecodings(string s) {
    long end0 = 1, end1 = 0, end2 = 0;
    long c0, c1, c2;
    for (char c : s) {
        if (c == '*') {
            c0 = 9 * end0 + 9 * end1 + 6 * end2;
            c1 = end0;
            c2 = end0;
        } else {
            c0 = (c != '0' ? end0 : 0) + end1 + (c <= '6' ? end2 : 0);
            c1 = c == '1' ? end0 : 0;
            c2 = c == '2' ? end0 : 0;
        }
        end0 = c0 % 1000000007;
        end1 = c1;
        end2 = c2;
    }
    return int(end0);
}

int main() {
    int res = numDecodings("*1");
    return res;
}