//
// Created by cebiao zhu on 2018/7/22.
//
#include <string>
#include <vector>
#include <iostream>

using namespace std;

string longestCommonPrefix(vector<string> &strs) {
    if (strs.empty())
        return "";
    if (strs[0].empty())
        return "";
    if (strs.size() == 1) {
        return strs[0];
    }
    int index = 0;
    for (int i = 0; i < strs[0].length(); ++i) {
        for (int j = 1; j < strs.size(); ++j) {
            if (strs[j][i] != strs[0][i]) {
                return strs[0].substr(0, index);
            }
        }
        ++index;
    }
    return strs[0].substr(0, index);
}

//int main(){
//    vector<string> strs = {"c","c"};
//    string res = longestCommonPrefix(strs);
//    cout << res;
//}