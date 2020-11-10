//
// Created by 段其沣 on 2020-09-18.
//

#include <iostream>
#include <string>

using namespace std;

class Solution{
public:
    string addStrings(string a, string b) {
        string longStr = a.size() < b.size() ? b : a;
        string shortStr = a.size() < b.size() ? a : b;

        int llen = longStr.size();
        int slen = shortStr.size();

        bool carry = 0;
        string result = "";

        while(llen > 0){
            int l = llen > 0 ? longStr[l - 1] - '0' : 0;
            int s = slen > 0 ? shortStr[s - 1] - '0' : 0;
            int c = (l + s + carry) % 10;
            carry = (l + s + carry) > 9 ;
            result.insert(result.begin(), c);
            llen--;
            slen--;
        }

        if(carry){
            result.insert(result.begin(), '1');
        }

        return result;

    }
};