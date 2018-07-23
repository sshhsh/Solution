//
// Created by cebiao zhu on 2018/7/23.
//
#include <string>
#include <regex>
#include <iostream>
#include <vector>
#include <sstream>
#include "stdlib.h"

using namespace std;

int gcd(int x, int y) {
    if (x < 0)
        x = -x;
    if (y < 0)
        y = -y;
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
    regex re(R"([\+]?(-?\d+)/(\d+))");
    sregex_iterator it(expression.begin(), expression.end(), re);
    sregex_iterator end;

    int mul = 1;
    for (; it != end; ++it) {
        char c[5];
        strcpy(c, it->str(1).c_str());
        m.push_back(atoi(c));
        strcpy(c, it->str(2).c_str());
        n.push_back(atoi(c));
//        cout << atoi(c) << endl;
        mul *= n.back();
    }

    int sum = 0;
    for (int i = 0; i < m.size(); ++i) {
        sum += mul / n[i] * m[i];
    }

    int g = gcd(sum, mul);

    stringstream str;
    str << sum / g << "/" << mul / g;

    return str.str();
}

int main() {
    cout << fractionAddition("-5/2+10/3+7/9");
}