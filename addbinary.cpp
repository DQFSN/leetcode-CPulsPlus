//
// Created by 段其沣 on 2020-09-18.
//

#include <iostream>
#include <string>

using namespace std;

string addBinary(string a, string b){
    int alen = a.size();
    int blen = b.size();

    string result;
    bool carry = false;

    while(alen > 0 || blen > 0){
        int abit = alen<=0 ? 0 : a[alen - 1] - '0';
        int bbit = blen<=0 ? 0 : b[blen - 1] - '0';
        int cbit = (abit + bbit + carry) & 1;
        carry = abit & bbit;
        result.insert(result.begin(), cbit + '0');
        alen--;
        blen--;
    }

    if (carry){
        result.insert(result.begin(), carry + '0');
    }

    return result;
}

