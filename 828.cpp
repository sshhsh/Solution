//
// Created by zhucebiao on 2018/7/23.
//
#include <string>
#include <iostream>

using namespace std;

int uniqueLetterString(string S) {
    int left[26];
    int middle[26];
    int sum = 0;
    for (int &i : left)
        i = -1;
    for (int &i : middle)
        i = -1;
    for (int i = 0; i < S.length(); ++i) {
        sum += (i - middle[S[i] - 'A']) * (middle[S[i] - 'A'] - left[S[i] - 'A']);
        left[S[i] - 'A'] = middle[S[i] - 'A'];
        middle[S[i] - 'A'] = i;
    }

    for (int i = 0; i < 26; ++i) {
        sum += (S.length() - middle[i]) * (middle[i] - left[i]);
    }
    return sum % 1000000007;
}

int main() {
    int res = uniqueLetterString("ABIQWGIQWGRIQUBFUASBFIASUDHOIWQNFOIWHFOIASFOIHWIHFOANFIA");
    cout << res;
}