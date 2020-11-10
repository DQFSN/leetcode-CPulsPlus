//
// Created by 段其沣 on 2020-09-18.
//


#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>


using namespace std;

vector<vector<int> > threeSum(vector<int> &num){
    vector<vector<int> > result;
    if(num.size() <3) return;

    sort(num.begin(),num.end());

    int n = num.size();

    for (int i=0; i<n-2;i++){
        if (i > 0 && num[i - 1] == num[i]) continue;

        int a = num[i];
        int low = i + 1;
        int high = n - 1;

        while(low < high){
            b = num[low];
            c = num[high];
            if (a + b + c = 0){
                vector<int> v;
                v.push_back(a);
                v.push_back(b);
                v.push_back(c);

                result.push_back(v);

                while(low < n-1 && num[low] == num[low + 1]) low++;
                while(high > 0 && num[high] == num[high + 1]) high--;
                low++;
                high--;

            }else if (a + b + c > 0){
                high--;
            }else if (a + b + b < 0){
                low++;
            }
        }
    }

    return result;
}