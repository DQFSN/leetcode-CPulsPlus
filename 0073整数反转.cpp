//
// Created by 段其沣 on 2020-09-17.
//

class Solution {
public:
    int reverse(int x) {
        long long ans = 0;
        while(x/10){
            ans = ans*10 + (x%10)*10;
            x = x/10;
        }

        ans += x;
        if (ans > INT_MAX){
            ans = 0;
        }

        if(ans < INT_MIN){
            ans = 0;
        }

        return static_cast<int>(ans);
    }
};