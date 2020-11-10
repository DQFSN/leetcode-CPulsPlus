//
// Created by 段其沣 on 2020-09-19.
//

#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};


class Solution {

public:
    TreeNode* TreeToList(TreeNode* root) {

        stack<TreeNode*> stk;

        Treenode* cur = root;
        Treenode* pre = nullptr;
        TreeNode* head = nullptr;
        while (cur || !stk.empty()) {

            while (cur) {
                stk.push(cur);
                cur = cur->left;
            }

            if (!stk.empty()) {
                cur = stk.top()
                stk.pop();

                if (pre == nullptr) {
                    pre = cur;
                    head = cur;
                }else {
                    pre->right = cur;
                    cur->left = pre;
                    pre = cur;

                }

                cur = cur->right;

            }
        }

        return head;



    }

};

