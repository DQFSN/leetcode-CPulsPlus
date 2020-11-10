//
// Created by 段其沣 on 2020-09-19.
//

#include <iostream>
#include <vector>

using namespace std;


class Solution {

public:

    bool check(vector<int> postOrder) {

        if (postOrder.size() <= 2) return true;

        int rootVal = postOrder[postOrder.size() - 1];
        int leftLen = 0;



        for (int i = postOrder.size() - 1; i >= 0 ; i--) {
            if (postOrder[i] >= rootVal) continue;
            leftLen = i + 1;
            break;
        }


        for (int i = leftLen - 1; i >= 0; i--) {
            if (postOrder[i] > rootVal) {
                return false;
            }
        }

        if (leftLen == 0 || leftLen == postOrder.size() - 1) {
            return true;
        }

        vector<int> leftPostorder(postOrder.begin(), postOrder.begin() + leftLen);
        vector<int> righPostorder(postOrder.begin() + leftLen + 1, postOrder.begin() + postOrder.size() - 1);

        return check(leftPostorder) && check(righPostorder);
    }
};


int main() {

    vector<int> postOrder = {10, 5, 15};

    cout<<Solution().check(postOrder);

    return 0;
};