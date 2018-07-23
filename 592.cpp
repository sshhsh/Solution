//
// Created by cebiao zhu on 2018/7/23.
//
#include <string>
#include <regex>
#include <iostream>
#include <vector>
#include "stdlib.h"

using namespace std;

int gcd(int x, int y) {
    int z = y;
    while (x % y != 0) {
        z = x % y;
        x = y;
        y = z;
    }
    return z;
}

string fractionAddition(string expression) {
    vector<int> m;
    vector<int> n;
    string::size_type pos = 0;
    regex re(R"([\+]?(-?\d)/(\d))");
    sregex_iterator it(expression.begin(), expression.end(), re);
    sregex_iterator end;

    int mul = 1;
    for (; it != end; ++it) {
        char c[5];
        strcpy(c, it->str(1).c_str());
        m.push_back(atoi(c));
        strcpy(c, it->str(2).c_str());
        n.push_back(atoi(c));
        cout << atoi(c) << endl;
    }
    return "A";
}

int main() {
    fractionAddition("-1/2+1/2+1/3");
}