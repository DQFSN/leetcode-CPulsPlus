//
// Created by 段其沣 on 2020-09-19.
//
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution {
public:
    bool hasSubTree(TreeNode* t1. TreeNode* t2) {

        if (t1 == nullptr && t2 == nullptr) {
            return true;
        }

        if ( !(t1 && t2) ) {
            return false;
        }else  {
            if (t1->val == t2->val) {

                bool left = hasSubTree(t1->left, t2->left);
                bool right = hasSubTree(t1->right, t2->right);

                return left && right;
            }else {
                return false;
            }
        }

    }
};

int main() {

    TreeNode tree1[4];

    TreeNode tree[2];

    cout<<Solution().hasSubTree(tree1, tree)<<endl;

    return 0;
}
