//
// Created by 段其沣 on 2020-09-19.
//


#include <iostream>
#include <algorithm>
#include <stack>


using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution {
public:

    void mirror(TreeNode* root) {
        if (root) {
            cout<<root->val<<" ";
            swap(root->left, root->right);
            mirror(root->left);
            mirror(root->right);
        }
    }

    void mirrorPostOrder(TreeNode* root) {
        stack<TreeNode*> stk;

        if (root == nullptr) return;

        stk.push(root);

        TreeNode* pre = nullptr;
        TreeNode* cur = root;

        while (!stk.empty()) {
            cur = stk.top();

            if ( (cur->left == nullptr && cur->right == nullptr) || ( (pre != nullptr)  && ( (pre == cur->left) || (pre == cur->right)) ) ) {
                cout<<cur->val<<" ";
                swap(cur->left, cur->right);
                stk.pop();
                pre = cur;
            }else {
                stk.push(cur->right);
                stk.push(cur->left);
            }
        }

    }
};


int main() {

    TreeNode tree[3];
    tree[0] = TreeNode{2, &tree[1], &tree[2]};
    tree[1] = TreeNode{1, nullptr, nullptr};
    tree[2] = TreeNode{3, nullptr, nullptr};
//    Solution().mirror(tree);
//    Solution().mirror(tree);
    Solution().mirrorPostOrder(tree);
    Solution().mirrorPostOrder(tree);



    return 0;
}
