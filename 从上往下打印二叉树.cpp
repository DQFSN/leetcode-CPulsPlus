//
// Created by 段其沣 on 2020-09-19.
//

#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};


class Solution {

    queue<TreeNode*> q;
public:

    void printTreelevel(TreeNode* root) {
        if (root) {
            q.push(root);

            if (root->left) {
                printTreelevel(root->left);
            }

            if (root->right) {
                printTreelevel(root->right);
            }

            root = q.front();
            q.pop();
            cout<<root->val<<" ";

        }
    }
};


int main() {
    TreeNode tree[5];

    tree[0] = TreeNode{2, &tree[1], &tree[2]};
    tree[1] = TreeNode{1, nullptr, nullptr};
    tree[2] = TreeNode{3, &tree[3], &tree[4]};
    tree[3] = TreeNode{4, nullptr, nullptr};
    tree[4] = TreeNode{5, nullptr, nullptr};

    Solution().printTreelevel(tree);

    return 0;
}

