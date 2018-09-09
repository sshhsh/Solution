//
// Created by sshhsh on 2018/9/9.
//
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool res = false;

void walk(TreeNode *root, int current) {
    if (res)return;
    current += root->val;
    if (root->left) {
        walk(root->left, current);
    }
    if (root->right) {
        walk(root->right, current);
    }
    if (!root->left && !root->right && current == 0) {
        res = true;
    }
    return;
}

bool hasPathSum(TreeNode *root, int sum) {
    if (root == nullptr)
        return false;
    walk(root, -sum);
    return res;
}

int main() {
    TreeNode *root = new TreeNode(-3);
    hasPathSum(root, 8);
    bool r = res;
    return 0;
}