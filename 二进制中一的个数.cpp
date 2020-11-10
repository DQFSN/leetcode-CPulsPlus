//
// Created by 段其沣 on 2020-09-18.
//


#include <iostream>

using namespace std;

class Solution{
public:
    int countOneNum(int n) {
        if (n == 0) return 0;

        int count = 0;
        while (n) {
            count++;
            n = n & (n - 1);
        }

        return count;

    }
};


int main() {

    cout<<Solution().countOneNum(2)<<endl;
}
