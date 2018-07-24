//
// Created by zhucebiao on 2018/7/24.
//
#include <vector>

using namespace std;

vector<int> getRow(int rowIndex) {
    vector<int> *b = new vector<int>();
    vector<int> *a = new vector<int>();
    vector<int> *c;
    a->push_back(1);
    for (int i = 0; i < rowIndex; ++i) {
        b->push_back(1);
        for (int j = 0; j < a->size() - 1; ++j) {
            b->push_back(a->at(j) + a->at(j + 1));
        }
        b->push_back(1);
        c = b;
        b = a;
        a = c;
        b->clear();
    }

    return *a;
}

int main() {
    vector<int> res = getRow(4);
    return 0;
}