//
// Created by 段其沣 on 2020-09-19.
//

#include <vector>
#include <stack>
#include <iostream>


using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution {
public:
    stack<int> stk;
    stack<stack<int >> res;

public:
    bool findSumPath(TreeNode* root, int sum) {

        if (root) {

            stk.push(root->val);

            sum -= root->val;

            if (sum < 0) {
                stk.pop();
                sum += root->val;
                bool left = findSumPath(root->left, sum) ;
                bool right = findSumPath(root->right, sum);
                return left && right;
            }else if ( sum == 0) {
                res.push(stk);
                stack<int>().swap(stk);
                return true;
            }else {

                bool left = findSumPath(root->left, sum) ;
                bool right = findSumPath(root->right, sum);
                return left && right;
            }

        }

        return false;
    }

};


int main() {

    TreeNode tree[3];
    tree[0] = TreeNode{2, &tree[1], &tree[2]};
    tree[1] = TreeNode{1, nullptr, nullptr};
    tree[2] = TreeNode{3, nullptr, nullptr};
    Solution solu = Solution();

    cout<<solu.findSumPath(tree, 2)<<" "<<solu.res.size()<<endl;
    return 0;
}