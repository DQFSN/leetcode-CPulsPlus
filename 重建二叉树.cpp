//
// Created by 段其沣 on 2020-09-18.
//

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution{
public:
    void preOrder(TreeNode* root) {
        if (root) {
            this->preOrderList.push_back(root->val);
            preOrder(root->left);
            preOrder(root->right);
        }
    }

    void inOrder(TreeNode* root) {
        if (root) {
            this->inOrder(root->left);
            inOrderList.push_back(root->val);
            inOrder(root->right);
        }
    }

    TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> in) {
        if (pre.size() != in.size()) return nullptr;

        int rootVal = pre[0];
        int rootIndex = 0;

        for (int i = 0; i < in.size(); i++) {
            if (in[i] == rootVal) rootIndex = i;
        }

        int left_len = rootIndex;
        int right_len = in.size() - rootIndex - 1;
        cout<<left_len<<" "<<endl;
        vector<int> left_pre(pre.begin() + 1, pre.begin() + 1 + left_len);
        vector<int> right_pre(pre.begin() + left_len + 1, pre.end());
        vector<int> left_in(in.begin(), in.begin() + left_len);
        vector<int> right_in(in.begin() + left_len, in.end());

        TreeNode* root = new TreeNode{rootVal, reConstructBinaryTree(left_pre, left_in), reConstructBinaryTree(right_pre, right_in)};
        return root;


    }


private:
    vector<int> preOrderList;
    vector<int> inOrderList;
};

int main( ) {
    int pre[] = { 1, 2, 4, 7, 3, 5, 6, 8 };
    int in[] = { 4, 7, 2, 1, 5, 3, 8, 6 };

    vector<int> preOrder(pre, pre + 8);
    vector<int>  inOrder( in,  in + 8);

    Solution solu;
    TreeNode *root = solu.reConstructBinaryTree(preOrder, inOrder);



    return 0;
}