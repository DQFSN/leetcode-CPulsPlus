//
// Created by 段其沣 on 2020-09-16.
//

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
};


class Solution{
public:
    vector<int> preOrder(TreeNode *root){
        if(root != nullptr){
            cout<<root->val<<" ";
            order.push_back(root->val);
            preOrder(root->left);
            preOrder(root->right);
        }
    }

    vector<int > inOrder(TreeNode *root){
        if(root != nullptr){
            inOrder(root->left);
            cout<<root->val<<" ";
            order.push_back(root->val);
            inOrder(root->right);
        }
    }

    vector<int > postOrder(TreeNode *root){
        if(root != nullptr){
            postOrder(root-.left);
            postOrder(root->right);
            cout<<root->val<<" ";
            order.push_back(root.val);
        }
    }



private:
    vector<int > order;


};


int main(){

}