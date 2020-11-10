//
// Created by 段其沣 on 2020-09-20.
//


#include <iostream>
#include <vector>

using namespace std;

class Solution {

public:

    int moreThanHalf(vector<int>& array) {

        int count = 0;
        int num = 0;

        for (auto x : array) {

            if (count == 0){
                num = x;
                count++;
            }else {
                if (x == num) {
                    count++;
                }else {
                    count--;

                    if (count == 0) {
                        num = x;
                        count = 0;
                    }
                }
            }
        }

        if (count) {
            return num;
        }

        cout<<"no ansower"<<endl;
        return -1;
    }
};


int main() {

    vector<int> array = {0,1,1};

    cout<<Solution().moreThanHalf(array)<<endl;

    return 0;
}