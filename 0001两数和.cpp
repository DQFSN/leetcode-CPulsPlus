//
// Created by 段其沣 on 2020-09-17.
//


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // sort(nums.begin(),nums.end());
        map<int,int> dict;

        for(int i=0;i<nums.size();i++){
            dict[nums[i]] = i;
        }

        for(int i=0;i<nums.size();i++){
            if(dict.find(target-nums[i]) != dict.end() && (i != dict[target-nums[i]]) ){
                return vector<int>{i,dict[target-nums[i]]};
            }
        }

        return vector<int>{-1,-1};
    }
};