//
// Created by 段其沣 on 2020-09-18.
//

#include <iostream>


using namespace std;
class Solution{
public:
    double numPow(int x, int y) {
        int base = x, exp = y;
        if (y == 0) return 1;

        if (y < 0) exp = -exp;

        double  ans = 1;

        while (exp) {

            if (exp & 1) {
                ans = ans * base;
            }

            base *= base;
            exp >>= 1;
        }

        return y < 0 ?  1 / ans : ans;



    }
};

int main () {

    cout<<Solution().numPow(-1, -2)<<endl;

    return 0;
}