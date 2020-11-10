//
// Created by 段其沣 on 2020-09-17.
//

class Solution {
public:
    bool isPalindrome(int x) {
        long ans = 0;
        int src = x;

        while(x/10){
            ans = ans*10 + (x%10)*10;
            x = x/10;
        }

        ans += x;

        if(x<0){
            ans = -ans;
        }

        return src == ans;
    }
};