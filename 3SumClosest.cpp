//
// Created by 段其沣 on 2020-09-18.
//


#include <vector>
#include <algorithm>


using namespace std;

int 3SumClosest(vector<int> &num, int target){
    int n = num.size();
    if (n < 3) return ;

    sort(num.begin(),num.end());

    int distance = INT_MAX;
    int sumClosest = 0;
    for (int i = 0; i < n; i++){
        int a = num[i];
        int low = i+1;
        int high = n - 1;

        while(low < high){
            int sum = a + b + c;
            if (sum == target){
                return target;
            }else {
                if (abs(target - sum) < distance){
                    distance = abs(target -sum);
                    sumClosest = sum;
                }

                if (sum > target){
                    high--;
                }else {
                    low++;
                }
            }
        }

    }
}