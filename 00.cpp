//
// Created by 段其沣 on 2020-09-16.
//


#include<iostream>
#include <vector>

using namespace std;


class Solution{
public :
    bool Find(vector<vector<int>> array, int target){
        if (array.size() == 0){
            return false;
        }

        int rc = array.size();
        int lc = array[0].size();

        for(int r=0,c=lc-1; r<rc&&(c>=0); ){
            if(array[r][c] == target){
                return true;
            }else if(array[r][c] > target){
                c--;
            }else{
                r++;
            }
        }

        return false;
    }
};

int __main()
{
    int a1[] = { 1, 2, 8, 9, };
    int a2[] = { 2, 4, 9, 12, };
    int a3[] = { 4, 7, 10, 13, };
    int a4[] = { 6, 8, 11, 15, };
    vector<vector<int>> array;
    array.push_back(vector<int>(a1, a1 + 4));
    array.push_back(vector<int>(a2, a2 + 4));
    array.push_back(vector<int>(a3, a3 + 4));
    array.push_back(vector<int>(a4, a4 + 4));

    Solution solu;
    cout <<solu.Find(array, 7) <<endl;
    return 0;
}