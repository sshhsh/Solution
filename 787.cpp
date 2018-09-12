//
// Created by zhucebiao on 2018/9/12.
//
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

struct myDis {
    int dst;
    int price;
    int stop;

    myDis(int price, int dst, int stop) {
        this->dst = dst;
        this->price = price;
        this->stop = stop;
    }
};

struct cmp {
    bool operator()(const myDis &left, const myDis &right) {
        return left.price > right.price;
    }
};


int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int K) {
    unordered_multimap<int, pair<int, int>> m;
    for (auto &flight:flights) {
        m.emplace(flight[0], make_pair(flight[1], flight[2]));
    }

    priority_queue<myDis, vector<myDis>, cmp> q; //price dst stop
    auto tmp = m.equal_range(src);
    for (auto i = tmp.first; i != tmp.second; i++) {
        q.push(myDis(i->second.second, i->second.first, 0));
    }
    while (!q.empty()) {
        auto t = q.top();
        q.pop();
        if (t.dst == dst)return t.price;
        if (t.stop >= K)continue;
        auto range = m.equal_range(t.dst);
        for (auto i = range.first; i != range.second; i++) {
            q.push(myDis(t.price + i->second.second, i->second.first, t.stop + 1));
        }

    }
    return -1;
}

int main() {
    vector<vector<int>> edges = {{0, 1, 100},
                                 {1, 2, 100},
                                 {0, 2, 500}};
    int res = findCheapestPrice(3, edges, 0, 2, 0);
    return res;
}