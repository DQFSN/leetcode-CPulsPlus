//
// Created by 段其沣 on 2020-09-18.
//


#include <iostream>

using namespace std;

class Solution{
public:
    void printToMaxNum(int n) {

        int carry = 0;
        string last = "1";
        while (last.size() < n+1) {
            cout<<last<<endl;
            last = addOne(last);
            if (last.size() <= n){
                cout<<last<<endl;
            }else {
                break;
            }
        }

    }

    string addOne(string s) {

        int n = s.size();
        int carry = 0;
        while (n) {
            int a = s[n - 1] - '0';
            int b;
            if (n == s.size()){
                b = (a + 1 + carry) % 10;
                carry = (a + 1 + carry) / 10;

            }else {
                b = (a + carry) % 10;
                carry = (a + carry) / 10;
            }
            s[n - 1] =  b + '0';
            n--;
        }

        if (carry){
            s = "1" + s;
        }

        return s;
    }
};


int main() {

    Solution().printToMaxNum(99999);

    return 0;
}
