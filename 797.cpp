//
// Created by cebiao zhu on 2018/7/23.
//
#include <vector>
#include <iostream>

using namespace std;


vector<int> tmp;
bool *flag;

bool walk(vector<vector<int>> &graph, int to, vector<vector<int>> &res) {
    if (!flag[to]) {
        return false;
    }

    if (to == graph.size() - 1) {
        tmp.push_back(to);
        res.push_back(tmp);
        tmp.pop_back();
        return true;
    }

    cout << graph.size() << endl;
    if (graph[to].empty()) {
        flag[to] = false;
        return false;
    }

    tmp.push_back(to);
    flag[to] = false;
    for (int i = 0; i < graph[to].size(); ++i) {
        if (walk(graph, graph[to][i], res)) {
            flag[to] = true;
        }
    }
    tmp.pop_back();
    return flag[to];
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
    vector<vector<int>> res;
    if (graph.empty())
        return res;
    flag = new bool[graph.size()];
    for (int i = 0; i < graph.size(); ++i) {
        flag[i] = true;
    }
    walk(graph, 0, res);
    return res;
}

//int main() {
//    vector<vector<int>> graph = {{1, 2},
//                                 {3},
//                                 {3},
//                                 {}};
//    vector<vector<int>> res = allPathsSourceTarget(graph);
//    cout << "a";
//}