//
// Created by cebiao zhu on 2018/7/23.
//

#include <vector>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void subTree(TreeNode **parent, vector<int> &inorder, vector<int> &postorder) {
    if (inorder.empty()) {
        *parent = nullptr;
        return;
    }
    *parent = new TreeNode(postorder.back());

    int i;
    for (i = 0; i < postorder.size(); ++i) {
        if (inorder[i] == postorder.back()) {
            break;
        }
    }
    vector<int> new_in(inorder.begin(), inorder.begin() + i);
    vector<int> new_post(postorder.begin(), postorder.begin() + i);
    subTree(&(*parent)->left, new_in, new_post);
    vector<int> new_in2(inorder.begin() + i + 1, inorder.end());
    vector<int> new_post2(postorder.begin() + i, postorder.end() - 1);
    subTree(&(*parent)->right, new_in2, new_post2);
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    TreeNode *res;
    subTree(&res, inorder, postorder);
    return res;
}

//int main(){
//    vector<int> in = {9,3,15,20,7};
//    vector<int> post = {9,15,7,20,3};
//    TreeNode* res = buildTree(in,post);
//    cout << "a";
//}