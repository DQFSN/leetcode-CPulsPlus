//
// Created by 段其沣 on 2020-09-21.
//

#include <vector>
#include <iostream>

using namespace std;

class Solution {

public:

    int FindGreatestSumOfSubArray(vector<int> array)
    {
        if(array.size( ) == 0)
        {
            return 0;
        }

        int sum = 0, maxSum = INT_MIN;
        for(unsigned int i = 0; i < array.size( ); i++)
        {
            if(sum <= 0)
            {
                sum = array[i];
            }
            else
            {
                sum += array[i];
            }

            if(sum > maxSum)
            {
                maxSum = sum;
            }
        }

        return maxSum;
    }

    int maxSum(vector<int>& array) {

        if (array.size() <= 0) return 0;

        int maxSum = array[0];
        int sum = 0;

//        int begin = 0, end = 0;
        for (auto x : array) {

            if (sum < 0) {
                sum = x;
            }else {
                sum += x;
            }
            maxSum = maxSum > sum ? maxSum : sum;
        }

        return maxSum;
    }

};


int main() {
    vector<int> array = {55,1,2,3,-9,-50,100,1,-2};
    cout<<Solution().maxSum(array)<<endl;
    cout<<Solution().FindGreatestSumOfSubArray(array)<<endl;

    return 0;
}