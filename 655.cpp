//
// Created by cebiao zhu on 2018/7/27.
//
#include <string>
#include <vector>
#include <cmath>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<string> s;
int max_level = 0;

void walk(TreeNode *root, int level, int position) {
    if (max_level < level)
        max_level = level;
    int pos = int(pow(2, level)) + position;
    if (pos >= s.size())
        s.resize(2 * pos);
    s[pos] = to_string(root->val);
    if (root->left != nullptr) {
        walk(root->left, level + 1, position * 2);
    }
    if (root->right != nullptr) {
        walk(root->right, level + 1, position * 2 + 1);
    }
}

vector<vector<string>> printTree(TreeNode *root) {
    walk(root, 0, 0);
    vector<vector<string>> res(max_level + 1);
    for (int i = 0; i <= max_level; ++i) {
        for (int j = 0; j < pow(2, i); ++j) {
            for (int k = 0; k < pow(2, max_level - i) - 1; ++k) {
                res[i].push_back("");
            }
            res[i].push_back(s[int(pow(2, i)) + j]);
            for (int k = 0; k < pow(2, max_level - i) - 1; ++k) {
                res[i].push_back("");
            }
        }
    }
    return res;
}

int main() {
    TreeNode *r = new TreeNode(1);
    r->left = new TreeNode(2);
    vector<vector<string>> res = printTree(r);
    return 0;
}