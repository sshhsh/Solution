//
// Created by zhucebiao on 2018/7/25.
//
#include <vector>
#include <map>
#include <set>

using namespace std;

vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
    multimap<int, int> top_points;
    for(auto building : buildings){
        top_points.emplace(building[0],building[2]);
        top_points.emplace(building[1],-building[2]);
    }

    vector<pair<int, int>> res;
    multiset<int> heights = {0};
    int x=-1,y=0;
    for(const pair<int, int> & p : top_points){
        if(x>=0&&p.first!=x&&(res.empty()||res.rbegin()->second!=y)){
            res.emplace_back(x,y);
        }
        if(p.second >= 0){
            heights.insert(p.second);
        } else{
            heights.erase(heights.find(-p.second));
        }
        x = p.first;
        y = *heights.rbegin();
    }
    if(!res.empty()){
        res.emplace_back(x,0);
    }
    return res;
}

int main(){

}