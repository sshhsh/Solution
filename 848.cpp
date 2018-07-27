//
// Created by cebiao zhu on 2018/7/27.
//
#include <string>
#include <vector>

using namespace std;

string shiftingLetters(string S, vector<int> &shifts) {
    int current = 0;
    for (int i = S.length() - 1; i >= 0; --i) {
        current += shifts[i];
        current = current % 26;
        S[i] = 'a' + (S[i] - 'a' + current) % 26;
    }
    return S;
}

int main() {
    string s = "abc";
    vector<int> shifts = {3, 5, 9};
    string res = shiftingLetters(s, shifts);
    return 0;
}