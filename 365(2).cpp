//
// Created by zhucebiao on 2018/7/23.
//
#include <map>
#include <vector>
#include <iostream>

using namespace std;

long aMax, bMax;
map<long,bool> m;
map<long,vector<long>> jug1,jug2;


void walk(long a, long b, vector<long>& j1, vector<long>&j2) {
    if (m[a * (bMax + 1) + b]) {
        return;
    }
    m[a * (bMax + 1) + b] = true;
    j1.push_back(a);
    j2.push_back(b);
    jug1[a * (bMax + 1) + b] = j1;
    jug2[a * (bMax + 1) + b] = j2;

    walk(aMax, b,j1,j2);
    walk(a, bMax,j1,j2);
    walk(0, b,j1,j2);
    walk(a, 0,j1,j2);
    if (a + b > aMax) {
        walk(aMax, b - aMax + a,j1,j2);
    } else {
        walk(a + b, 0,j1,j2);
    }
    if (a + b > bMax) {
        walk(a - bMax + b, bMax,j1,j2);
    } else {
        walk(0, a + b,j1,j2);
    }
    j1.pop_back();
    j2.pop_back();
}

bool canMeasureWater(int x, int y, int z) {
    aMax = x;
    bMax = y;
    vector<long> j1, j2;
    walk(0, 0,j1,j2);
    for (long i = 0; i <= z && i <= x; ++i) {
        long j = z - i;
        if(j>y)
            continue;
        if (m[i * (bMax + 1) + j])
            return true;
    }
    return false;
}

int main() {
    bool a = m[2];
    bool res = canMeasureWater(41,91,2);
    vector<long> j1 = jug1[2 * (bMax + 1) + 0];
    vector<long> j2 = jug2[2 * (bMax + 1) + 0];
    for(int i=0;i<j1.size();++i){
        cout << j1[i] << "\t" << j2[i] << endl;
    }
    return 0;
}