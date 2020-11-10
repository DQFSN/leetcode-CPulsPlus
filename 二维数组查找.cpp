//
// Created by 段其沣 on 2020-09-18.
//
#include <iostream>
#include <vector>

using namespace std;


class Solution{
public:
    bool findTarget(vector<vector<int>>& array, int target) {

        if (array.size() < 0) return false;
        int row = array.size(), col = array[0].size();

        for (int r = 0, l = col - 1; r < row && l >= 0;  ) {
            if (target == array[r][l]) {
                return true;
            }else if (target < array[r][l]) {
                l--;
            }else {
                r++;
            }
        }

        return false;
    }
};




int main(){
    vector<vector<int>> array(3);
    array[0] = {4,5,6};
    array[1] = {3,4,5};
    array[2] = {2,3,4};

    int target = 4;

    cout<<"找到："<<Solution().findTarget(array, target)<<endl;


    return 0;
}
