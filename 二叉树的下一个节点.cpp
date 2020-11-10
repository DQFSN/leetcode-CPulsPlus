//
// Created by 段其沣 on 2020-09-18.
//
#include <stack>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode* next;
};

class Solution{
public:
    TreeNode* inOrderNext(TreeNode* target) {
        TreeNode* res = nullptr;
        if (target->right) {
            target = target->right;
            while (target->left){
                target = target->left;
            }

            res = target;
        } else {
            if (!target->next || target == target->next->left) res = target->next;
            else {
                res = target->next;
                while (res->next && res = res->next->right) {
                    res = res->next;
                }
                res = res->next;
            }
        }

        return res;
    }
};


