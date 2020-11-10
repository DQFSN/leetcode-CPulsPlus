//
// Created by 段其沣 on 2020-09-18.
//

#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    vector<int> addToArray(vector<int> num, int k){

        int src = 0;
        vector<int> ans;

        for (auto x : num) {
            src = src * 10 + x;
        }

        src += k;

        while (src/10) {
            ans.push_back(src%10);
            src = src/10;
        }

        ans.push_back(src);

        reverse(ans.begin(), ans.end());

        return ans;

    }

    vector<int> addToArray2(vector<int> num) {
        int carry = k;

        for (int i = num.size() - 1; i > 0; i--) {
            int a = num[i] + carry;
            num[i] = a % 10;
            carry = a / 10;
        }

        while(carry / 10 ){
            num.insert(num.begin(), carry % 10);
            carry = carry / 10;
        }

        return num;

    }
};
