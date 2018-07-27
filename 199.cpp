//
// Created by cebiao zhu on 2018/7/27.
//
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> rightSideView(TreeNode *root) {
    vector<int> res;
    if (root == nullptr)
        return res;
    queue<TreeNode *> q;
    queue<int> layer;
    q.push(root);
    layer.push(0);
    while (!q.empty()) {
        TreeNode *current = q.front();
        int c = layer.front();
        if (res.size() <= c) {
            res.emplace_back(current->val);
        }
        layer.pop();
        q.pop();
        if (current->right != nullptr) {
            q.push(current->right);
            layer.push(c + 1);
        }
        if (current->left != nullptr) {
            q.push(current->left);
            layer.push(c + 1);
        }
    }
    return res;
}

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
//    root->right->right = new TreeNode(4);
    vector<int> res = rightSideView(root);
    return 0;
}