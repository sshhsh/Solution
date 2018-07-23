//
// Created by cebiao zhu on 2018/7/23.
//

#include <vector>
#include <iostream>
#include <limits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int flag = 0;
TreeNode *p;
int prev_num = numeric_limits<int>::lowest();
TreeNode *err1;
TreeNode *err2;

void inorder(TreeNode *root) {
    if (flag == 2)
        return;
    if (root->left != NULL)
        inorder(root->left);

    if (flag == 1) {
        if ((root->val) > prev_num) {
            err2 = p;
            flag = 2;
        } else {
            p = root;
        }
    } else if ((root->val) > prev_num) {
        prev_num = root->val;
        p = root;
    } else {
        err1 = p;
        err2 = root;
        flag = 1;
        p = root;
    }

    if (root->right != NULL)
        inorder(root->right);
}

void recoverTree(TreeNode *root) {

    inorder(root);
    if (flag == 1) {
        err2 = p;
    }
    int tmp = err1->val;
    err1->val = err2->val;
    err2->val = tmp;
}

int main() {
    TreeNode *t = new TreeNode(3);
    t->left = new TreeNode(1);
    t->right = new TreeNode(4);
    t->right->left = new TreeNode(2);
    recoverTree(t);
    cout << "a";
}